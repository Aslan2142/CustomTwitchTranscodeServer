#include "client_socket.h"

ClientSocket::ClientSocket(QTcpServer *server, QThread *thread, QObject *parent) : QObject(parent), current_thread(thread)
{
    //Set the connection pointer to the new incoming connection
    connection = server->nextPendingConnection();

    //Connect the socket's disconnect signal
    connect(connection, SIGNAL(disconnected()), this, SLOT(disconnected()));
}

void ClientSocket::process_connection() const
{
    qDebug() << "new thread";

    //Set the latest chunk id to 1 if it's less than 1
    unsigned long latest_chunk_id = StreamDownloader::chunk_buffer_id > 0 ? StreamDownloader::chunk_buffer_id : 1;

    while (true)
    {
        //Wait for new data
        qDebug() << "waiting";
        QEventLoop loop;
        QObject::connect(connection, SIGNAL(readyRead()), &loop, SLOT(quit()));
        loop.exec();

        //Read the incoming data
        qDebug() << "got request";
        QByteArray request_all = connection->readAll();
        QStringList request = QString::fromUtf8(request_all).split("-", Qt::SplitBehaviorFlags::SkipEmptyParts);

        //Ignore empty data
        if (request.length() == 0) break;

        //Process chunk
        if (request.length() > 0 && request[0] == "request_chunk")
        {
            QString chunk = QString::number(latest_chunk_id);
            QString root_path = settings.get_string("root_path", ".");
            QString path = root_path + "/chunk_transcoded_buffer_" + chunk + ".mp4";
            while (!QFile::exists(path)) //Wait if the chunk doesn't exist
            {
                qDebug() << "sleep on " << latest_chunk_id;
                QThread::msleep(500);
                continue;
            }

            QByteArray *file = load_file(path);
            while (file->size() == 0) //Wait if the chunk isn't transcoded
            {
                file = load_file(path);
                QThread::msleep(500);
            }

            //Send new chunk to the client
            send_data(connection, "start_of_chunk-");
            send_data(connection, file);
            send_data(connection, "-end_of_chunk");
            qDebug() << "sent chunk " << latest_chunk_id;
            latest_chunk_id++;

            delete file; //Remove the chunk from memory after sending
        }
    }
}

void ClientSocket::disconnected() // TO-DO Memory Leak needs to be fixed
{
    /*connection->close();
    QThread::sleep(1);
    delete connection;*/
}

QByteArray* ClientSocket::load_file(const QString& file_path) const
{
    QByteArray* file_data = new QByteArray();

    //Read the file data
    QFile file(file_path);
    file.open(QIODevice::ReadOnly);
    *file_data = file.readAll();
    file.close();

    return file_data;
}

void ClientSocket::send_data(QTcpSocket * const connection, const QByteArray& data) const
{
    //Write the data into the socket
    connection->write(data);
    connection->flush();
    connection->waitForBytesWritten();
}

void ClientSocket::send_data(QTcpSocket * const connection, const QByteArray * const data) const
{
    //Write the data into the socket
    connection->write(*data);
    connection->flush();
    connection->waitForBytesWritten();
}
