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

extern Settings settings; //Object for storing loaded program settings

class ClientSocket : public QObject
{
    Q_OBJECT
public:
    explicit ClientSocket(QTcpServer *server, QThread *thread, QObject *parent = nullptr);

public slots:
    void process_connection() const; //Gets called when new client connects
    void disconnected(); //Gets called when client gets disconnected

private:
    QTcpSocket *connection;
    QThread *current_thread;

    QByteArray* load_file(const QString& file_path) const; //Used for loading chunks into memory
    void send_data(QTcpSocket * const connection, const QByteArray&) const; //Writes data into the socket
    void send_data(QTcpSocket * const connection, const QByteArray * const data) const; //Writes data into the socket

};

#endif // CLIENT_SOCKET_H
