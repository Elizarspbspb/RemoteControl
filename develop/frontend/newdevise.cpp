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
    accept();
    // Сохраняем обновленный список устройств обратно в файл
    //saveDevices(devices);
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
    accept(); // error: cannot initialize object parameter of type 'QDialog' with an expression of type 'newDeviseAdd'
    //delete uidev;
}
