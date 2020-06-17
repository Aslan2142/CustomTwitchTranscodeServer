#include "client_socket.h"

ClientSocket::ClientSocket(QTcpServer *server, QThread *thread, QObject *parent) : QObject(parent), current_thread(thread)
{
    connection = server->nextPendingConnection();

    connect(connection, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void ClientSocket::process_connection() const
{
    qDebug() << "new thread";
    unsigned long latest_chunk_id = StreamDownloader::chunk_id > preload_chunks ? StreamDownloader::chunk_id - preload_chunks : 1;

    while (true)
    {
        qDebug() << "waiting";
        QEventLoop loop;
        QObject::connect(connection, SIGNAL(readyRead()), &loop, SLOT(quit()));
        loop.exec();
        qDebug() << "got request";
        QByteArray request_all = connection->readAll();
        QStringList request = QString::fromUtf8(request_all).split("-", Qt::SplitBehaviorFlags::SkipEmptyParts);

        if (request.length() == 0) break;

        if (request.length() > 0 && request[0] == "request_chunk")
        {
            QString chunk = QString::number(latest_chunk_id);
            QString root_path = settings.get_string("root_path", ".");
            QString path = root_path + "/chunk_transcoded_" + chunk + ".ts";
            while (!QFile::exists(path))
            {
                qDebug() << "sleep on " << latest_chunk_id;
                QThread::msleep(500);
                continue;
            }

            QByteArray *file = load_file(path);
            while (file->size() == 0)
            {
                file = load_file(path);
                QThread::msleep(500);
            }

            send_data(connection, "start_of_chunk-");
            send_data(connection, file);
            send_data(connection, "-end_of_chunk");
            qDebug() << "sent chunk " << latest_chunk_id;
            latest_chunk_id++;

            delete file;
        }
    }
}

void ClientSocket::disconnected()
{
    connection->close();
    QThread::sleep(1);
    delete connection;
}

QByteArray* ClientSocket::load_file(const QString& file_path) const
{
    QByteArray* file_data = new QByteArray();

    QFile file(file_path);
    file.open(QIODevice::ReadOnly);

    *file_data = file.readAll();
    file.close();

    return file_data;
}

void ClientSocket::send_data(QTcpSocket * const connection, const QByteArray& data) const
{
    connection->write(data);
    connection->flush();
    connection->waitForBytesWritten();
}

void ClientSocket::send_data(QTcpSocket * const connection, const QByteArray * const data) const
{
    connection->write(*data);
    connection->flush();
    connection->waitForBytesWritten();
}
