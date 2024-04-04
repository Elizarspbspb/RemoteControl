/*#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray> */
#include <QDebug>

#include "dialog.h"
#include "newdevise.h"

//#include "../backend/source/mainBack.cpp"
#include "../backend/include/mainBack.h"

#include "./ui_dialog.h"

/*QString localFileName = "../remotecontrol/develop/devices.json";
//QString localFileName = "devices.json"; */

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {

    ui->setupUi(this);

    // /////////////////////////////////////////////

    // start json DB
    /*QFile file(localFileName);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Ошибка открытия файла";
        return;
    }

    // Считываем весь файл JSON
    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(file.readAll(), &parseError);
    file.close();

    // Проверяем наличие ошибок при парсинге JSON
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "Ошибка парсинга JSON:" << parseError.errorString();
        return;
    }

    // Проверяем, что JSON представляет собой массив
    if (!jsonDoc.isArray()) {
        qDebug() << "JSON не является массивом";
        return;
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
            if(name.length() != 0)
                ui->comboBoxDevice->addItem(name);
            else
                ui->comboBoxDevice->addItem(ipAddress);
        }
    }*/

    startWork();
    /* //foreach (const QJsonValue &value, jsonArray) {
        // Добавляем в выпадающий список устройств
        if(name.length() != 0)
            ui->comboBoxDevice->addItem(name);
        else
            ui->comboBoxDevice->addItem(ipAddress);
    }*/

    // /////////////////////////////////////////////

    on_comboBoxDevice_activated(0);
}

void Dialog::on_addNewDevise_clicked() {
    newDeviseAdd *newDev = new newDeviseAdd(this);
    newDev->show();
    ui->comboBoxDevice->addItem("192.168.10.10");
}

Dialog::~Dialog() {
    delete ui;
}

uint Dialog::addNewDevice() {
    ui->comboBoxDevice->addItem("192.168.10.10");
    return 0;
}

void Dialog::on_comboBoxDevice_activated(int index) {
    if (index == 0) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/startPict.png);");
    } else if (index == 1) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/Computer.png);");
    } else if (index == 2) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/Notepad.png);");
    } else if (index == 3) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/Printer.png);");
    }
}

void Dialog::changeIndexPhoto(int index) {

}
