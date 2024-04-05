#include "../include/mainBack.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

Deviсe::Deviсe() {};

int Deviсe::startWork() {
    // start json DB
    QFile file(localFileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return 1;
    }

    // Считываем весь файл JSON
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError);
    file.close();

    // Проверяем наличие ошибок при парсинге JSON
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Ошибка парсинга JSON:" << parseError.errorString();
        return 1;
    }

    // Проверяем, что JSON представляет собой массив
    if (!jsonDoc.isArray()) {
        qDebug() << "JSON не является массивом";
        return 1;
    }

    // Преобразуем JSON в массив объектов
    QJsonArray jsonArray = jsonDoc.array();
    foreach (const QJsonValue &value, jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            QString name = obj["name"].toString();
            QString ipAddress = obj["IP-Addr"].toString();
            QString netMask = obj["netMask"].toString();
            QString imageResource = obj["image"].toString();

            // Выводим устройства
            qDebug() << "Имя:" << name;
            qDebug() << "IP-адрес:" << ipAddress;
            qDebug() << "Маска сети:" << netMask;
            qDebug() << "Ресурс изображения:" << imageResource;

            DeviseState dev;
            int id = obj["id"].toInt();
            dev.nameDevise = name.toStdString();
            dev.ipAddress = ipAddress.toStdString();
            dev.netMask = netMask.toStdString();
            dev.nameDevise = imageResource.toStdString();
            masDev.insert({id, dev});
            qDebug() << "значения = " << &masDev.end()->first;
            //qDebug() << "значения = " << masDev.end()->first;
            //ui->comboBoxDevice->addItem(in.second.ipAddress.c_str());
        }
    }
    return 0;
}

/*unordered_map<int, Deviсe::DeviseState> *Deviсe::getDevices() {
    return &masDev;
}*/

unordered_map<int, Deviсe::DeviseState> Deviсe::getDevices() {
    return masDev;
}
