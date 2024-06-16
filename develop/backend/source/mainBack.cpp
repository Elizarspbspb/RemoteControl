#include "../include/mainBack.h"

#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QString>


// --------------------------------
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
// --------------------------------

Deviсe::Deviсe() {};

// Функция для загрузки JSON файла
QJsonArray Deviсe::loadDevices(const QString& filename) {
    qDebug() << "Cont... -6" << Qt::endl;
    qDebug() << "Попытка открыть файл:" << filename;
    // Проверяем, существует ли файл
        if (!QFile::exists(filename)) {
            qDebug() << "Файл не существует:" << filename;
            return QJsonArray();
        }
qDebug() << "Cont... -67" << Qt::endl;
    //QFile file(filename);
    QFile *file = new QFile(filename);
    qDebug() << "Cont... -7" << Qt::endl;
    //if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    if (!file->open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return QJsonArray();
    }
qDebug() << "Cont... 66" << Qt::endl;
    // Считываем весь файл JSON
    QJsonParseError parseError;
    //QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError);
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file->readAll(), &parseError);
    //file.close();
    file->close();
    delete(file);

    // Проверяем наличие ошибок при парсинге JSON
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Ошибка парсинга JSON:" << parseError.errorString();
        return QJsonArray();
    }
qDebug() << "Cont... 666" << Qt::endl;
    // Проверяем, что JSON представляет собой массив
    if (!jsonDoc.isArray()) {
        qDebug() << "JSON не является массивом";
        return QJsonArray();
    }
qDebug() << "Cont... 6666" << Qt::endl;
    return jsonDoc.array();
}

//////////////////////////////////////////////
///
/*void saveDevicesToJson(const std::map<int, DeviseState>& masDev, const QString& filename) {
    QJsonArray jsonArray;

    for (const auto& [key, device] : masDev) {
        QJsonObject jsonObj;
        deviceObject["id"] = id;
        deviceObject["name"] = QString::fromStdString(device.nameDevise);
        jsonObj["id"] = device.id;
        jsonObj["name"] = device.name;
        jsonObj["IP-Addr"] = device.ipAddr;
        jsonObj["netMask"] = device.netMask;
        jsonObj["image"] = device.image;

        jsonArray.append(jsonObj);
    }

    QJsonDocument jsonDoc(jsonArray);
    QFile file(filename);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла для записи:" << filename;
        return;
    }

    file.write(jsonDoc.toJson());
    file.close();
    qDebug() << "Данные успешно записаны в файл:" << filename;
}*/
/// ////////////////////////////////////////////
///

// Функция для сохранения устройств в файл
//bool Deviсe::saveDevices(const std::unordered_map<int, DeviseState>& deviceMap) {
bool Deviсe::saveDevices(const std::map<int, DeviseState>& deviceMap) {
    /*qDebug() << "Cont... 5" << Qt::endl;
    //QFile file(localFileName);
    QFile file("../develop/devices.json");
    if (!file.exists()) {
        qWarning() << "File does not exist:" << localFileName;
        return 1;
    }
    qDebug() << "Cont... 55" << Qt::endl;
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << "Невозможно открыть файл Базы Данных для записи !" << localFileName;
        qDebug() << "Невозможно открыть файл Базы Данных для записи !";
        return 1;
    }
qDebug() << "Cont... 555" << Qt::endl;
    QJsonArray devicesArray; */
    QJsonObject deviceObject;
    qDebug() << "Cont... 5" << Qt::endl;
    QJsonArray devicesArray = loadDevices(localFileName);
    qDebug() << "Cont... 55" << Qt::endl;
    for (const auto& [id, device] : deviceMap) {
        //deviceObject["id"] = id;
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
                //masDev.insert({id, dev}).second;
                masDev.insert({id, dev});
            }  catch (...) {
                qDebug() << "Data from DataBase has not been added" << Qt::endl;
            }
        }
    }
    return 0;
}

// Функция для вычисления следующего id
//int Deviсe::getNextId(const std::unordered_map<int, DeviseState> &deviceMap) {
/*int Deviсe::getNextId() {
    int maxId = 0;
    //for (const auto &[id, device] : deviceMap) {
    for (const auto &[id, device] : masDev) {
        if (id > maxId) {
            maxId = id;
        }
        std::cout << "Current id = " << id << ", Max id = " << maxId << std::endl;
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
    qDebug() << "Cont... 1" << Qt::endl;
    //int id = getNextId(masDev);
    int id = masDev.end()->first;
    //int id = masDev.begin()->first;
    qDebug() << "Cont... 11; id = " << id << Qt::endl;

    for (const auto& [key, value] : masDev) {
           std::cout << "Key: " << key << ", Value: " << &value << std::endl;
       }


        //dev.id = qid.toStdString();
    //dev.id = QString::number(id).toStdString();
    dev.id = QString::number(masDev.end()->first+1).toStdString();
    qDebug() << "Cont... 111" << Qt::endl;
        dev.nameDevise = name.toStdString();
        dev.ipAddress = ipAddress.toStdString();
        dev.netMask = netMask.toStdString();
        dev.imageResource = imageResource.toStdString();
        qDebug() << "Cont... 2" << Qt::endl;
        try {
            //masDev.insert({id, dev}).second;
            qDebug() << "Cont... 22" << Qt::endl;
            //masDev.insert({id, dev}).second;
            //masDev.insert({id, dev});
            qDebug() << "Cont... 222" << Qt::endl;
        } catch (...) {
            qDebug() << "Data from DataBase has not been added" << Qt::endl;
        }
        qDebug() << "Cont... 3" << Qt::endl;
    //saveDevices(masDev);
    int newKey = masDev.size() + 1;
    masDev.insert({newKey, dev});
    saveDevices(masDev);
    // Получаем текущий размер карты
    /*int newKey = masDev.size() + 1;
    qDebug() << "size = " << newKey << Qt::endl;
    masDev.insert({newKey, dev});*/
    qDebug() << "Cont... 4" << Qt::endl;
    for (const auto& [key, value] : masDev) {
           std::cout << "Key: " << key << ", Value: " << &value << std::endl;
       }
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

//unordered_map<int, DeviseState> Deviсe::getMasDev() {
map<int, DeviseState> Deviсe::getMasDev() {
    return masDev;
}

/*DeviseState Deviсe::getDevState() {
    return DeviseState;
}*/
