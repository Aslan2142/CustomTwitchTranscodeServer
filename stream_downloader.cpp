#include "stream_downloader.h"

unsigned long StreamDownloader::chunk_id = 0;

StreamDownloader::StreamDownloader(QObject *parent) : QObject(parent)
{
    restclient = new QNetworkAccessManager();
}

bool StreamDownloader::authorize()
{
    access_token = "";
    access_token_sig = "";

    QByteArray data = get_reply("https://api.twitch.tv/api/channels/" + channel + "/access_token?need_https=true&platform=_type=site&player_backend=mediaplayer");
    QJsonDocument json = QJsonDocument::fromJson(data);
    QJsonObject jsonObject = json.object();

    access_token = QUrl::toPercentEncoding(jsonObject["token"].toString());
    access_token_sig = jsonObject["sig"].toString();

    return access_token.length() > 0 && access_token_sig.length() > 0;
}

void StreamDownloader::start()
{
    update_m3u8_list();

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
        QByteArray ts_file = get_reply(ts_links[i], false);
        QString root_path = settings.get_string("root_path", ".");
        QString output_path = root_path + "/chunk_" + QString::number(chunk_id + 1) + ".ts";
        QString output_path_transcoded = root_path + "/chunk_transcoded_" + QString::number(chunk_id + 1) + ".ts";
        QString output_path_old = root_path + "/chunk_" + QString::number(chunk_id + 1 - keep_chunks) + ".ts";
        QString output_path_transcoded_old = root_path + "/chunk_transcoded_" + QString::number(chunk_id + 1 - keep_chunks) + ".ts";
        qDebug() << output_path;

        if (QFile::exists(output_path)) QFile::remove(output_path);
        if (QFile::exists(output_path_transcoded)) QFile::remove(output_path_transcoded);
        if (QFile::exists(output_path_old)) QFile::remove(output_path_old);
        if (QFile::exists(output_path_transcoded_old)) QFile::remove(output_path_transcoded_old);

        QFile output_file(output_path);
        output_file.open(QIODevice::WriteOnly);
        output_file.write(ts_file);
        output_file.close();

        transcode(output_path, output_path_transcoded);
        QFile::remove(output_path);

        chunk_id++;
    }
}

void StreamDownloader::update_m3u8_list()
{
    QByteArray data = get_reply("https://usher.ttvnw.net/api/channel/hls/" + channel + ".m3u8?player=twitchweb&allow_source=true&allow_audio_only=true&allow_spectre=false&sig=" + access_token_sig + "&token=" + access_token + "&type=any", false);
    chunked_m3u8_file_url = parse_m3u8(data)[0];
}

void StreamDownloader::transcode(const QString& input, const QString& output)
{
    QProcess ffmpeg_process;
    ffmpeg_process.setProgram("ffmpeg");
    ffmpeg_process.setArguments({ "-i", input, "-c:a", "copy", "-c:v", "libx264", "-b:v", settings.get_string("transcoded_video_bitrate", "600") + "k", "-preset", "veryfast", "-vf", "scale=-1:" + settings.get_string("transcoded_video_height", "360"), output });
    ffmpeg_process.start();
    ffmpeg_process.waitForFinished();
}

void StreamDownloader::update_chunked_m3u8()
{
    QByteArray data = get_reply(chunked_m3u8_file_url, false);
    ts_links = parse_m3u8(data);
}

void StreamDownloader::update_ts_links()
{
    QString last_ts_link = ts_links.length() > 0 ? ts_links.last() : "";

    update_chunked_m3u8();

    int last_index = -1;
    for (int i = 0; i < ts_links.length(); i++)
    {
        if (ts_links[i] == last_ts_link)
        {
            last_index = i;
            break;
        }
    }

    while (last_index >= 0)
    {
        ts_links.removeAt(0);
        last_index--;
    }
}

QStringList StreamDownloader::parse_m3u8(const QString& m3u8) const
{
    QStringList lines = m3u8.split("\n", Qt::SplitBehaviorFlags::SkipEmptyParts);

    for (int i = 0; i < lines.count(); i++)
    {
        if (lines[i].startsWith("#"))
        {
            lines.removeAt(i);
            i--;
        }
    }

    return lines;
}

QByteArray StreamDownloader::get_reply(const QString& url, bool use_client_id) const
{
    QUrl myurl;
    myurl.setUrl(url);

    QNetworkRequest request;
    request.setUrl(myurl);
    if (use_client_id) request.setRawHeader("Client-ID", client_id.toUtf8());

    QNetworkReply *reply = restclient->get(request);

    QEventLoop loop;
    QObject::connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    reply->deleteLater();

    return reply->readAll();
}
