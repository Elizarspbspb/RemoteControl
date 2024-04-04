#include "../include/mainBack.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QString>

/*#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct DeviseState final {
    string nameDevise;
    string ipAddress;
    string netMask;
    string imageResource;
};

//QString localFileName = "../remotecontrol/develop/devices.json";
//QString localFileName = "../develop/devices.json";
//string localFileName2 = "../develop/devices.json"; */

int startWork() {

    DeviseState one;
    one.nameDevise = "astra";
    one.ipAddress = "1";
    one.netMask = "255";
    one.nameDevise = "comp";
    //unordered_set<DeviseState> masDev; // ERROR
    //masDev.insert(one);
    unordered_set<DeviseState*> masDev;
    masDev.insert(&one);

    //std::string localFileName = "../develop/devices.json";
    QString localFileName = "../develop/devices.json";

    // ///////////////////////////////////////

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

            // Добавляем в выпадающий список устройств
            //if(name.length() != 0)
            //    ui->comboBoxDevice->addItem(name);
            //else
            //    ui->comboBoxDevice->addItem(ipAddress);
        }
    }

    return 0;
}
