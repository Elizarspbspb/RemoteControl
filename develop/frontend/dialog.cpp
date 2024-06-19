#include <QDebug>

#include "dialog.h"
#include "delete_dev.h"

#include "./ui_dialog.h"

void Dialog::updateViewDevises() {

    //ui->comboBoxDevice->clear();

    /*const bool ok = photoDev.insert({"Выбрать устройство", "image: url(:/Icons/startPict.png);"}).second;
    if(ok)
        qDebug() << "start_photo_install";
    else
        qDebug() << "start_photo_not_correct_install\n";
    ui->photoLabel->setStyleSheet("image: url(:/Icons/startPict.png);");*/

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


Dialog::Dialog(Deviсe &device, QWidget *parent) : QDialog(parent), ui(new Ui::Dialog), dev(device) {
    ui->setupUi(this);
    dev.startWork();

    const bool ok = photoDev.insert({"Выбрать устройство", "image: url(:/Icons/startPict.png);"}).second;
    if(ok)
        qDebug() << "start_photo_install";
    else
        qDebug() << "start_photo_not_correct_install\n";
    ui->photoLabel->setStyleSheet("image: url(:/Icons/startPict.png);");

    updateViewDevises();
    /*for (auto in : dev.getMasDev()) {
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
    }*/
}

void Dialog::on_addNewDevise_clicked() {
    DialogNewDev *newDev = new DialogNewDev(dev);
    newDev->show();
    dev.startWork();
    /*ui->comboBoxDevice->clear();
    ui->comboBoxDevice->clearEditText();
    ui->comboBoxDevice->clearFocus();
    ui->comboBoxDevice->clearMask();
    updateViewDevises();
    //accept(); */
}

void Dialog::on_deleteDevise_clicked() {
    deleteDevise *delDev = new deleteDevise(this);
    delDev->show();
}

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
