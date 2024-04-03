#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>

#include "dialog.h"
#include "./ui_dialog.h"

#include "newdevise.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {

    ui->setupUi(this);

// /////////////////////////////////////////////
// start json DB
    QFile file("devices.json");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    if (!infile.open("devices.json")
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
            QString ipAddress = obj["ipAddress"].toString();
            QString netMask = obj["netMask"].toString();
            QString imageResource = obj["imageResource"].toString();

            // Делаем что-то с данными устройства (например, добавляем их в список устройств)
            qDebug() << "Имя:" << name;
            qDebug() << "IP-адрес:" << ipAddress;
            qDebug() << "Маска сети:" << netMask;
            qDebug() << "Ресурс изображения:" << imageResource;
        }
    }

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
