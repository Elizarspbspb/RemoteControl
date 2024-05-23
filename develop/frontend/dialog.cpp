/*#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray> */
#include <QDebug>

#include "dialog.h"
//#include "newdevise.h"
#include "delete_dev.h"

#include "./ui_dialog.h"

Dialog::Dialog(Deviсe &device, QWidget *parent) : QDialog(parent), ui(new Ui::Dialog), dev(device) {
    ui->setupUi(this);
    dev.startWork();

    const bool ok = photoDev.insert({"Выбрать устройство", "image: url(:/Icons/startPict.png);"}).second;
    if(ok)
        qDebug() << "start_photo_install";
    else
        qDebug() << "start_photo_not_correct_install\n";
    ui->photoLabel->setStyleSheet("image: url(:/Icons/startPict.png);");

    for (auto in : dev.getMasDev()) {
        QString name = in.second.nameDevise.c_str();
        if(name.size() != 0) {
            ui->comboBoxDevice->addItem(in.second.nameDevise.c_str());
            const bool ok = photoDev.insert({name, in.second.imageResource.c_str()}).second;
            if(ok)
                qDebug() << "photo_install";
            else
                qDebug() << "photo_not_correct_install\n";
        }
        else {
            ui->comboBoxDevice->addItem(in.second.ipAddress.c_str());
            QString name = in.second.ipAddress.c_str();
            const bool ok = photoDev.insert({name, in.second.imageResource.c_str()}).second;
            if(ok)
                qDebug() << "photo_install";
            else
                qDebug() << "photo_not_correct_install\n";
        }
    }
}

void Dialog::on_addNewDevise_clicked() {
    /*newDeviseAdd *newDev = new newDeviseAdd(this); */
    //DialogNewDev newDev(dev);
    DialogNewDev *newDev = new DialogNewDev(dev);
    //DialogNewDev *newDev = new DialogNewDev(this);
    newDev->show();
    //ui->comboBoxDevice->addItem("192.168.10.10");
}

void Dialog::on_deleteDevise_clicked() {
    deleteDevise *delDev = new deleteDevise(this);
    delDev->show();
}

/*uint Dialog::addNewDevice() {
    ui->comboBoxDevice->addItem("192.168.10.10");
    return 0;
}*/

/*void Dialog::on_comboBoxDevice_activated(int index) {
    if (index == 0) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/startPict.png);");
    } else if (index == 1) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/Computer.png);");
    } else if (index == 2) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/Notepad.png);");
    } else if (index == 3) {
        ui->photoLabel->setStyleSheet("image: url(:/Icons/Printer.png);");
    }
}*/

/*void Dialog::changeIndexPhoto(int index) {

}*/

void Dialog::on_comboBoxDevice_activated(const QString &arg1) {
    for (auto in : photoDev) {
        if (arg1 == in.first) {
            ui->photoLabel->setStyleSheet(in.second);
            break;
        }
    }
}

void Dialog::on_exitButton_clicked() {
    exit(0);
}

Dialog::~Dialog() {
    delete ui;
}
