#include "../include/mainBack.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>

Deviсe::Deviсe() {};

// Функция для загрузки JSON файла
QJsonArray Deviсe::loadDevices(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return QJsonArray();
    }

    // Считываем весь файл JSON
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError);
    file.close();

    // Проверяем наличие ошибок при парсинге JSON
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Ошибка парсинга JSON:" << parseError.errorString();
        return QJsonArray();
    }

    // Проверяем, что JSON представляет собой массив
    if (!jsonDoc.isArray()) {
        qDebug() << "JSON не является массивом";
        return QJsonArray();
    }

    return jsonDoc.array();
}

// Функция для сохранения устройств в файл
bool Deviсe::saveDevices(const std::unordered_map<int, DeviseState>& deviceMap) {
    QFile file(localFileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Невозможно открыть файл Базы Данных для записи !";
        return 1;
    }

    QJsonArray devicesArray;
    for (const auto& [id, device] : deviceMap) {
        QJsonObject deviceObject;
        deviceObject["id"] = id;
        deviceObject["name"] = QString::fromStdString(device.nameDevise);
        deviceObject["IP-Addr"] = QString::fromStdString(device.ipAddress);
        deviceObject["netMask"] = QString::fromStdString(device.netMask);
        deviceObject["image"] = QString::fromStdString(device.imageResource);
        devicesArray.append(deviceObject);
    }
    // Ошибка - no known conversion from 'const std::string' (aka 'const basic_string<char>') to 'const QJsonValue' for 1st argument

    QJsonDocument document(devicesArray);
    file.write(document.toJson());
    file.close();
    qDebug() << "База успешно обновлена";

    return 0;
}

// Функция для сохранения JSON файла
/*void Deviсe::saveDevices(const QString& filename, const QJsonArray& devices) {
void Deviсe::saveDevices(const QJsonArray& devices) {
    QFile file(localFileName);
    if (!file.open(QIODevice::WriteOnly)) {
        qDebug() << "Невозможно открыть файл Базы Данных для записи !";
        return;
    }

    QJsonDocument document(devices);
    file.write(document.toJson());
    file.close();
    qDebug() << "База успешно обновлена";
} */

int Deviсe::startWork() {
    // Преобразуем JSON в массив объектов
    QJsonArray jsonArray = loadDevices(localFileName);
    foreach (const QJsonValue &value, jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            QString qid = obj["id"].toString();
            QString name = obj["name"].toString();
            QString ipAddress = obj["IP-Addr"].toString();
            QString netMask = obj["netMask"].toString();
            QString imageResource = obj["image"].toString();

            // Выводим устройства
            qDebug() << "id:" << qid;
            qDebug() << "Имя:" << name;
            qDebug() << "IP-адрес:" << ipAddress;
            qDebug() << "Маска сети:" << netMask;
            qDebug() << "Ресурс изображения:" << imageResource;

            DeviseState dev;
            int id = qid.toInt();
            dev.id = qid.toStdString();
            dev.nameDevise = name.toStdString();
            dev.ipAddress = ipAddress.toStdString();
            dev.netMask = netMask.toStdString();
            dev.imageResource = imageResource.toStdString();
            try {
                masDev.insert({id, dev}).second;
            }  catch (...) {
                qDebug() << "Data from DataBase has not been added" << Qt::endl;
            }
        }
    }
    return 0;
}

// Функция для вычисления следующего id
int Deviсe::getNextId(const std::unordered_map<int, DeviseState> &deviceMap) {
    int maxId = 0;
    for (const auto &[id, device] : deviceMap) {
        if (id > maxId) {
            maxId = id;
        }
        std::cout << "Current id = " << id << ", Max id = " << maxId << std::endl;
    }
    return maxId + 1;
}

/*int Deviсe::getNextId(const QJsonArray& devices) {
    int maxId = 0;
    for (const QJsonValue& value : devices) {
        QJsonObject device = value.toObject();
        int id = device["id"].toString().toInt();
        if (id > maxId) {
            maxId = id;
        }
        cout << "MAX id = " << maxId << endl;
    }
    return maxId + 1;
}*/

// Функция для добавления нового устройства
//void Deviсe::addDevice(QJsonArray& devices, const QString& name, const QString& ipAddress, const QString& netMask, const QString& imageResource) {
//void Deviсe::addDevice(const std::unordered_map<int, DeviseState> &deviceMap, const QString& name, const QString& ipAddress, const QString& netMask, const QString& imageResource) {
void Deviсe::addDevice(const QString& name, const QString& ipAddress, const QString& netMask, const QString& imageResource) {
    DeviseState dev;
        //QJsonObject newDevice;
        //QString qid = newDevice["id"].toString();
        //int id = qid.toInt(); getNextId
    //int id = getNextId(deviceMap);
    int id = getNextId(masDev);
        //dev.id = qid.toStdString();
    dev.id = QString::number(id).toStdString();
        dev.nameDevise = name.toStdString();
        dev.ipAddress = ipAddress.toStdString();
        dev.netMask = netMask.toStdString();
        dev.imageResource = imageResource.toStdString();
        try {
            //masDev.insert({id, dev}).second;
            masDev.insert({id, dev}).second;
        }  catch (...) {
            qDebug() << "Data from DataBase has not been added" << Qt::endl;
        }
    saveDevices(masDev);
    /*int newId = getNextId(devices);
    QJsonObject newDevice;
    newDevice["id"] = QString::number(newId);
    newDevice["name"] = name;
    newDevice["IP-Addr"] = ipAddress;
    newDevice["netMask"] = netMask;
    newDevice["image"] = imageResource;
    devices.append(newDevice); */

    // Обновление карты устройств
    /*DeviseState deviceState;
    deviceState.name = deviceToAdd["name"].toString();
    deviceState.ipAddr = deviceToAdd["IP-Addr"].toString();
    deviceState.netMask = deviceToAdd["netMask"].toString();
    deviceState.image = deviceToAdd["image"].toString();
    deviceMap[nextId] = deviceState; */
    /*DeviseState dev;
    QJsonObject newDevice;
    QString qid = newDevice["id"].toString();
    int id = qid.toInt();
    dev.id = qid.toStdString();
    dev.nameDevise = name.toStdString();
    dev.ipAddress = ipAddress.toStdString();
    dev.netMask = netMask.toStdString();
    dev.imageResource = imageResource.toStdString();
    try {
        masDev.insert({id, dev}).second;
    }  catch (...) {
        qDebug() << "Data from DataBase has not been added" << Qt::endl;
    } */
}

unordered_map<int, DeviseState> Deviсe::getMasDev() {
    return masDev;
}

/*DeviseState Deviсe::getDevState() {
    return DeviseState;
}*/
