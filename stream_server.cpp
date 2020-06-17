#include "stream_server.h"

StreamServer::StreamServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
}

bool StreamServer::start_server(int port) const
{
    connect(server, SIGNAL(newConnection()), this, SLOT(accept_connection()), Qt::QueuedConnection);

    bool listening = server->listen(QHostAddress::Any, port);
    if (!listening)
    {
        stop_server();
        return false;
    }

    return true;
}

void StreamServer::stop_server() const
{
    server->close();
}

void StreamServer::accept_connection() const
{
    qDebug() << "new connection";

    QThread *socket_thread = new QThread();
    ClientSocket *socket = new ClientSocket(server, socket_thread);

    connect(socket_thread, SIGNAL(started()), socket, SLOT(process_connection()));

    socket->moveToThread(socket_thread);
    socket_thread->start();
}
