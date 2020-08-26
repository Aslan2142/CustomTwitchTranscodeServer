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

    void load(const QString& path); //Load the data from file
    QString get_string(const QString& key, const QString& default_value) const; //Get string data by key
    int get_int(const QString& key, int default_value) const; //Get integer data by key

private:
    QMap<QString, QString> *data; //Data is stored here
};

#endif // SETTINGS_H
