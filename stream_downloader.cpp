#include "stream_downloader.h"

unsigned long StreamDownloader::chunk_id = 0;
unsigned long StreamDownloader::chunk_buffer_id = 0;

StreamDownloader::StreamDownloader(QObject *parent) : QObject(parent)
{
    restclient = new QNetworkAccessManager();
}

bool StreamDownloader::authorize()
{
    //Clear access token
    access_token = "";
    access_token_sig = "";

    //Download new access token
    QByteArray data = get_reply("https://api.twitch.tv/api/channels/" + channel + "/access_token?need_https=true&platform=_type=site&player_backend=mediaplayer");
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonObject jsonObject = json.object();

    //Set access token
    access_token = QUrl::toPercentEncoding(jsonObject["token"].toString());
    access_token_sig = jsonObject["sig"].toString();

    //Return true if access token were successfully downloaded
    return access_token.length() > 0 && access_token_sig.length() > 0;
}

void StreamDownloader::start()
{
    //Update m3u8 file url
    update_m3u8_list();

    //Check for new chunks and download them
    while (true)
    {
        QThread::msleep(update_interval);
        update_ts_links();
        download_stream_data();
    }
}

void StreamDownloader::download_stream_data()
{
    for (int i = 0; i < ts_links.length(); i++)
    {
        chunk_id++;

        //Download new TS file
        QByteArray ts_file = get_reply(ts_links[i], false);

        //Setup output paths
        QString output_path = root_path + "/chunk_" + QString::number(chunk_id) + ".ts";
        QString output_path_transcoded = root_path + "/chunk_transcoded_" + QString::number(chunk_id) + ".ts";
        QString output_path_old = root_path + "/chunk_" + QString::number(chunk_id - keep_chunks) + ".ts";
        QString output_path_transcoded_old = root_path + "/chunk_transcoded_" + QString::number(chunk_buffer_id - keep_chunks) + ".ts";
        qDebug() << output_path;

        //Remove conflicting files
        if (QFile::exists(output_path)) QFile::remove(output_path);
        if (QFile::exists(output_path_transcoded)) QFile::remove(output_path_transcoded);
        if (QFile::exists(output_path_old)) QFile::remove(output_path_old);
        if (QFile::exists(output_path_transcoded_old)) QFile::remove(output_path_transcoded_old);

        //Save TS file
        QFile output_file(output_path);
        output_file.open(QIODevice::WriteOnly);
        output_file.write(ts_file);
        output_file.close();

        //Transcode TS file and remove the original
        transcode(output_path, output_path_transcoded);
        QFile::remove(output_path);

        //If there are enough chunks, make a buffer chunk
        if (chunk_id % chunk_buffer_size == 0 && chunk_id > 0)
        {
            make_buffer_chunk();
        }
    }
}

void StreamDownloader::update_m3u8_list()
{
    //Get m3u8 file url
    QByteArray data = get_reply("https://usher.ttvnw.net/api/channel/hls/" + channel + ".m3u8?player=twitchweb&allow_source=true&allow_audio_only=true&allow_spectre=false&sig=" + access_token_sig + "&token=" + access_token + "&type=any", false);
    chunked_m3u8_file_url = parse_m3u8(data)[0];
}

void StreamDownloader::transcode(const QString& input, const QString& output)
{
    //Use ffmpeg to transcode TS file
    QProcess ffmpeg_process;
    ffmpeg_process.setProgram("ffmpeg");
    ffmpeg_process.setArguments({ "-i", input, "-c:a", "copy", "-c:v", "libx264", "-b:v", QString::number(transcoded_video_bitrate) + "k", "-preset", "veryfast", "-vf", "scale=-1:" + QString::number(transcoded_video_height), output });
    ffmpeg_process.start();
    ffmpeg_process.waitForFinished();
}

void StreamDownloader::make_buffer_chunk()
{
    chunk_buffer_id++;

    //Setup paths
    QString output_path = root_path + "/chunk_transcoded_buffer_" + QString::number(chunk_buffer_id) + ".mp4";
    QString file_list_path = root_path + "/list.txt";

    //Remove conflicting files
    if (QFile::exists(output_path)) QFile::remove(output_path);
    if (QFile::exists(file_list_path)) QFile::remove(file_list_path);

    //Setup chunk file list
    QFile file_list(file_list_path);
    file_list.open(QIODevice::WriteOnly);
    for (unsigned long i = chunk_id - (chunk_buffer_size - 1); i <= chunk_id; i++)
    {
        QString input_path = "chunk_transcoded_" + QString::number(i) + ".ts";
        file_list.write("file '");
        file_list.write(input_path.toUtf8());
        file_list.write("'\n");
    }
    file_list.close();

    //Use ffmpeg to join multiple chunks to make a buffer chunk using a file list
    QProcess ffmpeg_process;
    ffmpeg_process.setProgram("ffmpeg");
    ffmpeg_process.setArguments({ "-f", "concat", "-safe", "0", "-i", file_list_path, "-c", "copy", output_path });
    ffmpeg_process.start();
    ffmpeg_process.waitForFinished();
}

void StreamDownloader::update_ts_links()
{
    //Get last TS link if it is not empty
    QString last_ts_link = ts_links.length() > 0 ? ts_links.last() : "";

    //Update list of TS file links
    QByteArray data = get_reply(chunked_m3u8_file_url, false);
    ts_links = parse_m3u8(data);

    //Get index of last used TS file link
    int last_index = -1;
    for (int i = 0; i < ts_links.length(); i++)
    {
        if (ts_links[i] == last_ts_link)
        {
            last_index = i;
            break;
        }
    }

    //Remove old TS file links
    while (last_index >= 0)
    {
        ts_links.removeAt(0);
        last_index--;
    }
}

QStringList StreamDownloader::parse_m3u8(const QString& m3u8) const
{
    //Get lines
    QStringList lines = m3u8.split("\n", Qt::SplitBehaviorFlags::SkipEmptyParts);

    //Remove lines that begin with # charater
    for (int i = 0; i < lines.count(); i++)
    {
        if (lines[i].startsWith("#"))
        {
            lines.removeAt(i);
            i--;
        }
    }

    //Return valid lines
    return lines;
}

QByteArray StreamDownloader::get_reply(const QString& url, bool use_client_id) const
{
    //Setup url
    QUrl myurl;
    myurl.setUrl(url);

    //Setup request
    QNetworkRequest request;
    request.setUrl(myurl);
    if (use_client_id) request.setRawHeader("Client-ID", client_id.toUtf8());

    //Get reply
    QNetworkReply *reply = restclient->get(request);

    //Wait for reply
    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    //Set the reply to be cleaned from memory
    reply->deleteLater();

    //Return contents of the reply
    return reply->readAll();
}
