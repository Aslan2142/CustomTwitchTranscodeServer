#ifndef CLIENT_SOCKET_H
#define CLIENT_SOCKET_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QFile>
#include <QThread>
#include <QEventLoop>
#include "stream_downloader.h"
#include "settings.h"

extern Settings settings;

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QTcpServer *server, QThread *thread, QObject *parent = nullptr);

public slots:
    void process_connection() const;
    void disconnected();

private:
    QTcpSocket *connection;
    QThread *current_thread;

    QByteArray* load_file(const QString& file_path) const;
    void send_data(QTcpSocket * const connection, const QByteArray&) const;
    void send_data(QTcpSocket * const connection, const QByteArray * const data) const;

};

#endif // CLIENT_SOCKET_H
