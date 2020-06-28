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
    qInfo() << "Custom Twitch Transcode Server v0.9.1";

    settings.load("settings.json");

    QtConcurrent::run(start_stream_downloader);

    StreamServer *server = new StreamServer();
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
    stream_downloader->root_path = settings.get_string("root_path", ".");
    stream_downloader->channel = settings.get_string("channel", "");
    stream_downloader->transcoded_video_height = settings.get_int("transcoded_video_height", 360);
    stream_downloader->transcoded_video_bitrate = settings.get_int("transcoded_video_bitrate", 600);
    stream_downloader->update_interval = settings.get_int("update_interval", 5000);
    stream_downloader->chunk_buffer_size = settings.get_int("chunk_buffer_size", 10);
    stream_downloader->keep_chunks = settings.get_int("keep_chunks", 25);

    if (!stream_downloader->authorize())
    {
        qInfo() << "Authorization Error!";
        exit(2);
    }

    stream_downloader->start();
}
