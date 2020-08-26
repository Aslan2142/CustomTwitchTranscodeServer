#include "stream_server.h"

StreamServer::StreamServer(QObject *parent) : QObject(parent)
{
    server = new QTcpServer(this);
}

bool StreamServer::start_server(int port) const
{
    //Connect the server new connection signal
    connect(server, SIGNAL(newConnection()), this, SLOT(accept_connection()), Qt::QueuedConnection);

    //Start listening on a given port
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

    //Create socket and thread for socket
    QThread *socket_thread = new QThread();
    ClientSocket *socket = new ClientSocket(server, socket_thread);

    //Connect the thread start signal to the socket
    connect(socket_thread, SIGNAL(started()), socket, SLOT(process_connection()));

    //Move the socket to the thread
    socket->moveToThread(socket_thread);
    socket_thread->start();
}
