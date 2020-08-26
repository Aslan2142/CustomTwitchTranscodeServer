#ifndef STREAM_SERVER_H
#define STREAM_SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>
#include <QThread>
#include "client_socket.h"

class StreamServer : public QObject
{
    Q_OBJECT

public:
    explicit StreamServer(QObject *parent = nullptr);

    bool start_server(int port) const;
    void stop_server() const;

private:
    QTcpServer *server;

private slots:
    void accept_connection() const; //Gets called on a new incoming connection

};

#endif // STREAM_SERVER_H
