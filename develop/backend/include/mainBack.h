#include <iostream>
#include <string>
#include <unordered_set>

#include <QString>

using namespace std;

struct DeviseState final {
    string nameDevise;
    string ipAddress;
    string netMask;
    string imageResource;
};

//QString localFileName = "../remotecontrol/develop/devices.json";
//QString localFileName = "../develop/devices.json";
//string localFileName = "../develop/devices.json";

int startWork();
