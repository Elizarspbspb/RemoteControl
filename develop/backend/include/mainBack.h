#pragma once

#include <iostream>
#include <string>
#include <map>

#include <QString>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

using namespace std;

struct DeviseState final {
    string id;
    string ipAddress;
    string nameDevise;
    string netMask;
    string imageResource;
    DeviseState() = default;
};

class Deviсe final {
private:
    const QString localFileName = "../develop/devices.json";
    //const QString& localFileName;
    map<int, DeviseState> masDev;
    Ui::Dialog *uiMain;
public:
    Deviсe();
    int startWork();
    map<int, DeviseState> getMasDev();
    DeviseState getDevState();
    QJsonArray loadDevices(const QString& filename);    // Функция для загрузки JSON файла
    bool saveDevices(const std::map<int, DeviseState>&);
    //void addDevice(const QString&, const QString&, const QString&, const QString&); // Функция для добавления нового устройства
    void addDevice(const QString&, const QString&, const QString&, const QString&, Ui::Dialog&); // Функция для добавления нового устройства
    ~Deviсe() {};
};
