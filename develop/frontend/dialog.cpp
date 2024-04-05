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
//#include "../backend/include/mainBack.h"

#include "./ui_dialog.h"

/*QString localFileName = "../remotecontrol/develop/devices.json";
//QString localFileName = "devices.json"; */

/*Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog), dev(0) {
    ui->setupUi(this);
    // /////////////////////////////////////////////
        //startWork();
    // /////////////////////////////////////////////
    on_comboBoxDevice_activated(0);
}*/

//Dialog::Dialog(QWidget *parent, Deviсe &device) : QDialog(parent), ui(new Ui::Dialog), dev(device) {
Dialog::Dialog(Deviсe &device, QWidget *parent) : QDialog(parent), ui(new Ui::Dialog), dev(device) {
    ui->setupUi(this);
    // /////////////////////////////////////////////
    //if(!device.startWork()) {
    device.startWork(); //{
        // Добавляем в выпадающий список устройств
        //for (auto in : *device.getDevices()) {
        //for (auto in = device.getDevices().begin()->first; in != device.getDevices().end()->first; in++) {
        //for (auto in = device.getDevices(); in != device.getDevices(); in++) {
        for (auto in : device.getDevices()) {
            if(std::atoi(in.second.nameDevise.c_str()) != 0)
            //if(in != 0)
                ui->comboBoxDevice->addItem(in.second.nameDevise.c_str());
            else
                ui->comboBoxDevice->addItem(in.second.ipAddress.c_str());
            qDebug() << "!!!!!!!!!!!!!!!!!!!!";
        }
    //}
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
