#pragma once

#include <iostream>
#include <string>
//#include <unordered_set>
#include <unordered_map>

#include <QString>

using namespace std;

class Deviсe final {
private:
    const QString localFileName = "../develop/devices.json";

    struct DeviseState final {
        string ipAddress;
        string nameDevise;
        string netMask;
        string imageResource;

        DeviseState() = default;

        // Определение оператора сравнения ==
        /*bool operator==(const DeviseState& other) const {
            return ipAddress == other.ipAddress;
        }*/
    };

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
    unordered_map<int, DeviseState> masDev;
public:
    Deviсe();
    int startWork();
    //DeviseState *getDevices();
    //unordered_map<int, DeviseState> *getDevices();
    unordered_map<int, DeviseState> getDevices();
    ~Deviсe() {};
};
