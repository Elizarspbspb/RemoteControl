#include "newdevise.h"

//#include <iostream>

//#include "../backend/include/mainBack.h"

#include "./ui_addNewDev.h"
//#include "./ui_DialogNewDev.h"

using namespace std;

/*DialogNewDev::DialogNewDev(QDialog *parent):QDialog{parent}, uidev(new Ui::DialogNewDev) {
    uidev->setupUi(this);
}*/

//DialogNewDev::DialogNewDev(Deviсe device, QWidget *parent) : QDialog(parent), uidev(new Ui1::DialogNewDev), nwDev(device) {}
DialogNewDev::DialogNewDev(Deviсe device, QWidget *parent) : QDialog(parent), uidev(new Ui::DialogNewDev), nwDev(device) {
    uidev->setupUi(this);
}
//DialogNewDev::DialogNewDev(Deviсe device, QWidget *parent) : QDialog(parent), nwDev(device) {} // exit
//DialogNewDev::DialogNewDev(Deviсe device, QWidget *parent) : QDialog(parent), uidev(new Ui::Dialog), nwDev(device) {}

void DialogNewDev::on_addPushButton_clicked() {
    // Загружаем текущие устройства из файла
    //QJsonArray devices = loadDevices(filename);

    // Определяем параметры нового устройства
    QString name = "lineeditname";
    QString ipAddr = "192.168.33.11";
    QString netMask = "255.255.252.0";
    QString image = "image: url(:/Icons/Server.png);";

    // Добавляем новое устройство в список
    //addDevice(devices, name, ipAddr, netMask, image);
    //Deviсe::addDevice(name, ipAddr, netMask, image);
    nwDev.addDevice(name, ipAddr, netMask, image);

    // Сохраняем обновленный список устройств обратно в файл
    //saveDevices(devices);

    //std::cout << "New device with ID " << getNextId(devices) - 1 << " added successfully!" << std::endl;

    /*#include <QCoreApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QString>
#include <iostream>

// Функция для загрузки JSON файла
QJsonArray loadDevices(const QString& filename) {
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly)) {
        std::cerr << "Could not open the file for reading." << std::endl;
        return QJsonArray();
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument document = QJsonDocument::fromJson(fileData);
    if (!document.isArray()) {
        std::cerr << "JSON is not an array." << std::endl;
        return QJsonArray();
    }

    return document.array();
}

// Функция для сохранения JSON файла
void saveDevices(const QString& filename, const QJsonArray& devices) {
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly)) {
        std::cerr << "Could not open the file for writing." << std::endl;
        return;
    }

    QJsonDocument document(devices);
    file.write(document.toJson());
    file.close();
}

// Функция для вычисления следующего ID
int getNextId(const QJsonArray& devices) {
    int maxId = 0;
    for (const QJsonValue& value : devices) {
        QJsonObject device = value.toObject();
        int id = device["id"].toString().toInt();
        if (id > maxId) {
            maxId = id;
        }
    }
    return maxId + 1;
}

// Функция для добавления нового устройства
void addDevice(QJsonArray& devices, const QString& name, const QString& ipAddr, const QString& netMask, const QString& image) {
    int newId = getNextId(devices);
    QJsonObject newDevice;
    newDevice["id"] = QString::number(newId);
    newDevice["name"] = name;
    newDevice["IP-Addr"] = ipAddr;
    newDevice["netMask"] = netMask;
    newDevice["image"] = image;
    devices.append(newDevice);
}

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    QString filename = "devices.json";

    // Загружаем текущие устройства из файла
    QJsonArray devices = loadDevices(filename);

    // Определяем параметры нового устройства
    QString name = "ARM-11-linux";
    QString ipAddr = "192.168.33.11";
    QString netMask = "255.255.252.0";
    QString image = "image: url(:/Icons/Server.png);";

    // Добавляем новое устройство в список
    addDevice(devices, name, ipAddr, netMask, image);

    // Сохраняем обновленный список устройств обратно в файл
    saveDevices(filename, devices);

    std::cout << "New device with ID " << getNextId(devices) - 1 << " added successfully!" << std::endl;

    return 0;
}*/

}

DialogNewDev::~DialogNewDev() {
    cout << "~newDeviseAdd() 1" << endl;
    delete uidev;
}

void DialogNewDev::on_DialogNewDev_finished(int result) {
    std::cout << "~newDeviseAdd() 2" << endl;
    delete uidev;
}

void DialogNewDev::on_cancelPushButton_clicked() {
    cout << "~newDeviseAdd() 3" << endl;
    //accept(); // error: cannot initialize object parameter of type 'QDialog' with an expression of type 'newDeviseAdd'
}
