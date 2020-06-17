#include <QCoreApplication>
#include <QtConcurrent/QtConcurrent>
#include "stream_downloader.h"
#include "stream_server.h"
#include "settings.h"

Settings settings;

void start_stream_downloader();

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qInfo() << "Custom Twitch Transcode Server v0.9";

    settings.load("settings.json");

    QtConcurrent::run(start_stream_downloader);

    StreamServer *server = new StreamServer();
    server->preload_chunks = settings.get_int("preload_chunks", 4);
    if (!server->start_server(settings.get_int("server_port", 2142)))
    {
        qInfo() << "Cannot Start Server!";
        exit(1);
    }

    return a.exec();
}

void start_stream_downloader()
{
    StreamDownloader *stream_downloader = new StreamDownloader();
    stream_downloader->update_interval = settings.get_int("update_interval", 5000);
    stream_downloader->keep_chunks = settings.get_int("keep_chunks", 25);
    stream_downloader->channel = settings.get_string("channel", "");

    if (!stream_downloader->authorize())
    {
        qInfo() << "Authorization Error!";
    }

    stream_downloader->start();
}
