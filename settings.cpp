#include "settings.h"

Settings::Settings()
{
    data = new QMap<QString, QString>();
}

void Settings::load(const QString& path)
{
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    QByteArray file_data = file.readAll();
    file.close();

    QJsonDocument json = QJsonDocument::fromJson(file_data);
    QJsonObject jsonObject = json.object();

    (*data)["root_path"] = jsonObject["root_path"].toString();
    (*data)["channel"] = jsonObject["channel"].toString();
    (*data)["server_port"] = jsonObject["server_port"].toString();
    (*data)["transcoded_video_height"] = jsonObject["transcoded_video_height"].toString();
    (*data)["transcoded_video_bitrate"] = jsonObject["transcoded_video_bitrate"].toString();
    (*data)["update_interval"] = jsonObject["update_interval"].toString();
    (*data)["preload_chunks"] = jsonObject["preload_chunks"].toString();
    (*data)["keep_chunks"] = jsonObject["keep_chunks"].toString();
}

QString Settings::get_string(const QString& key, const QString& default_value) const
{
    return data->contains(key) ? (*data)[key] : default_value;
}

int Settings::get_int(const QString& key, int default_value) const
{
    return data->contains(key) ? (*data)[key].toInt() : default_value;
}
