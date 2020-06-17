#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMap>

class Settings
{
public:
    Settings();

    void load(const QString& path);
    QString get_string(const QString& key, const QString& default_value) const;
    int get_int(const QString& key, int default_value) const;

private:
    QMap<QString, QString> *data;
};

#endif // SETTINGS_H
