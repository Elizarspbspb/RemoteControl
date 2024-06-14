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

//#include "frontend/newdevise.h"

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
//class Deviсe {
private:
    const QString localFileName = "../develop/devices.json";

    /*struct DeviseState final {
        string ipAddress;
        string nameDevise;
        string netMask;
        string imageResource;

        DeviseState() = default;

        // Определение оператора сравнения ==
        //bool operator==(const DeviseState& other) const {
        //    return ipAddress == other.ipAddress;
        //}
    };*/

    // Определение хэш-функции для структуры DeviseState
    /*struct DeviseStateHash {
        size_t operator()(const DeviseState& state) const {
            return hash<string>()(state.ipAddress);
        }
    };*/

    //unordered_set<DeviseState> masDev;  // ERROR
    //unordered_set<DeviseState, DeviseStateHash> masDev;
    // Определение типа для удобства
    //using MyMap = std::unordered_map<int, DeviseState>;
    //unordered_map<int, DeviseState> masDev;
    map<int, DeviseState> masDev;
public:
    Deviсe();
    int startWork();
    //DeviseState *getDevices();
    //unordered_map<int, DeviseState> *getDevices();
    //unordered_map<int, DeviseState> getMasDev();
    map<int, DeviseState> getMasDev();
    DeviseState getDevState();

    QJsonArray loadDevices(const QString& filename);    // Функция для загрузки JSON файла
    //bool saveDevices(const std::unordered_map<int, DeviseState>&);
    bool saveDevices(const std::map<int, DeviseState>&);
    //int getNextId();
    void addDevice(const QString&, const QString&, const QString&, const QString&); // Функция для добавления нового устройства

    ~Deviсe() {};
};
