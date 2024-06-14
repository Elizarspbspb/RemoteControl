#pragma once

#include <iostream>
#include <string>
//#include <unordered_set>
//#include <unordered_map>
#include <map>

#include <QString>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

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
public:
    Deviсe();
    int startWork();
    map<int, DeviseState> getMasDev();
    DeviseState getDevState();
    QJsonArray loadDevices(const QString& filename);    // Функция для загрузки JSON файла
    bool saveDevices(const std::map<int, DeviseState>&);
    void addDevice(const QString&, const QString&, const QString&, const QString&); // Функция для добавления нового устройства
    ~Deviсe() {};
};
