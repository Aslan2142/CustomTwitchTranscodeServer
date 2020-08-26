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

    QString root_path; //Root path for storing the chunks
    QString channel; //Twitch channel name
    unsigned int transcoded_video_height; //Height of the output video (width gets adjusted accordingly to keep the aspect ratio)
    unsigned int transcoded_video_bitrate; //Bitrate of the output video
    unsigned long update_interval; //How often downloader checks for new chunks
    unsigned int chunk_buffer_size; //How many chunks are needed to make a chunk buffer
    unsigned int keep_chunks; //How many chunks to keep before deleting them from storage
    static unsigned long chunk_id;
    static unsigned long chunk_buffer_id;

    bool authorize(); //Authorize with Twitch (fills up access token)
    void start(); //Starts the main loop
    void download_stream_data(); //Downloads new chunks
    void update_m3u8_list(); //Updates m3u8 file url

private:
    QString client_id = "kimne78kx3ncx6brgo4mv6wki5h1ko"; //Client ID for Twitch
    QString access_token = ""; //Access token for Twitch (gets filled in)
    QString access_token_sig = ""; //Access token signature for Twitch (gets filled in)
    QString chunked_m3u8_file_url = ""; //Url for m3u8 file (chunked quality setting) (gets filled in)
    QStringList ts_links; //List of links for TS files
    QNetworkAccessManager *restclient;

    void transcode(const QString& input, const QString& output); //Transcodes the chunk using ffmpeg
    void make_buffer_chunk(); //Makes chunk buffer (big chunk made out of small chunks) using ffmpeg
    void update_ts_links(); //Updates the list of TS links from new m3u8 file and discards old ones
    QStringList parse_m3u8(const QString& m3u8) const; //Returns a list of TS file links from m3u8 file
    QByteArray get_reply(const QString& url, bool use_client_id = true) const; //Get reply from api server

};

#endif // STREAM_DOWNLOADER_H
