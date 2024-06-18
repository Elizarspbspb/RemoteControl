#include "../include/mainBack.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>

void appendToJson(const QString &fileName, const QJsonObject &newObject) {
    QFile file(fileName);

    if (!file.open(QIODevice::ReadWrite)) {
        qWarning() << "Error opening file:" << file.errorString();
        return;
    }

    QByteArray data = file.readAll();
    QJsonDocument document = QJsonDocument::fromJson(data);

    if (!document.isArray()) {
        qWarning() << "Root of JSON file is not an array.";
        file.close();
        return;
    }

    QJsonArray jsonArray = document.array();
    jsonArray.append(newObject);

    document.setArray(jsonArray);
    file.resize(0); // Очищаем файл перед записью
    file.write(document.toJson());
    file.close();
}

Deviсe::Deviсe() {};

// Функция для загрузки JSON файла
QJsonArray Deviсe::loadDevices(const QString& filename) {
    qDebug() << "Попытка открыть файл: " << filename;
    // Проверяем, существует ли файл
    if (!QFile::exists(filename)) {
        qDebug() << "Файл не существует:" << filename;
        return QJsonArray();
    }

    QFile *file = new QFile(filename);
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return QJsonArray();
    }

    // Считываем весь файл JSON
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file->readAll(), &parseError);
    file->close();
    delete(file);

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
//bool Deviсe::saveDevices(const std::unordered_map<int, DeviseState>& deviceMap) {
bool Deviсe::saveDevices(const std::map<int, DeviseState>& deviceMap) {
    QJsonObject deviceObject;
    QJsonArray devicesArray = loadDevices(localFileName);
    for (const auto& [id, device] : deviceMap) {
        deviceObject["1_Id"] = QString::fromStdString(device.id);
        deviceObject["2_Name"] = QString::fromStdString(device.nameDevise);
        deviceObject["3_IP-Addr"] = QString::fromStdString(device.ipAddress);
        deviceObject["4_NetMask"] = QString::fromStdString(device.netMask);
        deviceObject["5_Image"] = QString::fromStdString(device.imageResource);
        devicesArray.append(deviceObject);
    }
    // Ошибка - no known conversion from 'const std::string' (aka 'const basic_string<char>') to 'const QJsonValue' for 1st argument
qDebug() << "Cont... 6" << Qt::endl;
    QJsonDocument document(devicesArray);
    //file.write(document.toJson());
    //file.close();
    qDebug() << "База успешно обновлена";
    appendToJson(localFileName, deviceObject);
    return 0;
}

int Deviсe::startWork() {
    // Преобразуем JSON в массив объектов
    QJsonArray jsonArray = loadDevices(localFileName);
    foreach (const QJsonValue &value, jsonArray) {
        if (value.isObject()) {
            QJsonObject obj = value.toObject();
            QString qid = obj["1_Id"].toString();
            QString name = obj["2_Name"].toString();
            QString ipAddress = obj["3_IP-Addr"].toString();
            QString netMask = obj["4_NetMask"].toString();
            QString imageResource = obj["5_Image"].toString();

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
                masDev.insert({id, dev});
            }  catch (...) {
                qDebug() << "Data from DataBase has not been added" << Qt::endl;
            }
        }
    }
    return 0;
}

// Функция для добавления нового устройства
void Deviсe::addDevice(const QString& name, const QString& ipAddress, const QString& netMask, const QString& imageResource) {
    DeviseState dev;
    int id = masDev.end()->first;
    dev.id = QString::number(masDev.end()->first+1).toStdString();
    dev.nameDevise = name.toStdString();
    dev.ipAddress = ipAddress.toStdString();
    dev.netMask = netMask.toStdString();
    dev.imageResource = imageResource.toStdString();
    try {
        int newKey = masDev.size() + 1;
        masDev.insert({newKey, dev});
        saveDevices(masDev);
    } catch (...) {
        qDebug() << "Data from DataBase has not been added" << Qt::endl;
    }

    //startWork();
}

map<int, DeviseState> Deviсe::getMasDev() {
    return masDev;
}
