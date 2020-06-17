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
#include "settings.h"

extern Settings settings;

class StreamDownloader : public QObject
{
    Q_OBJECT

public:
    explicit StreamDownloader(QObject *parent = nullptr);

    QString channel;
    unsigned long update_interval;
    unsigned int keep_chunks;
    static unsigned long chunk_id;

    bool authorize();
    void start();
    void download_stream_data();
    void update_m3u8_list();
    void transcode(const QString& input, const QString& output);

private:
    QString client_id = "kimne78kx3ncx6brgo4mv6wki5h1ko";
    QString access_token = "";
    QString access_token_sig = "";
    QString chunked_m3u8_file_url = "";
    QStringList ts_links;
    QNetworkAccessManager *restclient;

    void update_chunked_m3u8();
    void update_ts_links();
    QStringList parse_m3u8(const QString& m3u8) const;
    QByteArray get_reply(const QString& url, bool use_client_id = true) const;


};

#endif // STREAM_DOWNLOADER_H
