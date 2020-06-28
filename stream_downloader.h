#ifndef STREAM_DOWNLOADER_H
#define STREAM_DOWNLOADER_H

#include <QObject>
#include <QThread>
#include <QEventLoop>
#include <QUrl>
#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QProcess>

class StreamDownloader : public QObject
{
    Q_OBJECT

public:
    explicit StreamDownloader(QObject *parent = nullptr);

    QString root_path;
    QString channel;
    unsigned int transcoded_video_height;
    unsigned int transcoded_video_bitrate;
    unsigned long update_interval;
    unsigned int chunk_buffer_size;
    unsigned int keep_chunks;
    static unsigned long chunk_id;
    static unsigned long chunk_buffer_id;

    bool authorize();
    void start();
    void download_stream_data();
    void update_m3u8_list();

private:
    QString client_id = "kimne78kx3ncx6brgo4mv6wki5h1ko";
    QString access_token = "";
    QString access_token_sig = "";
    QString chunked_m3u8_file_url = "";
    QStringList ts_links;
    QNetworkAccessManager *restclient;

    void transcode(const QString& input, const QString& output);
    void make_buffer_chunk();
    void update_chunked_m3u8();
    void update_ts_links();
    QStringList parse_m3u8(const QString& m3u8) const;
    QByteArray get_reply(const QString& url, bool use_client_id = true) const;

};

#endif // STREAM_DOWNLOADER_H
