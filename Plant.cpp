#include "Plant.h"

using namespace std;

Plant::Plant() {
    tWater = 0;
    tSun = 0;
    tFert = 0;
    nameLen = 0;
    name = "";
}

Plant::Plant(string str) {
    stringstream strIn(str);
    string sunStr = "";
    name = "";
    nickname = "";
    genus = "";
    nameLen = 0;
    char discard, temp;
    char sunCharOne, sunCharTwo;
    //ex: "w3sFSf30"
    strIn >> discard >> tWater >> discard >> sunCharOne >> sunCharTwo >> 
        discard >> tFert;
    sunStr += sunCharOne;
    sunStr += sunCharTwo;
    for (int i = 0; i < 4; i++) {
        if (sunStr == T_SUN_STR[i]) {
            tSun = T_SUN_NUM[i];
        }
    }
}

void Plant::setTWater(int n) {
    tWater = n;
}

void Plant::setTSun(string str) {
    for (int i = 0; i < 4; i++) {
        if (str == T_SUN_STR[i]) {
            tSun = T_SUN_NUM[i];
        }
    }
}

void Plant::setTFert(int n) {
    tFert = n;
}

void Plant::setName(string str) {
    name = str;
    nameLen = name.length();
}

void Plant::setGenus(string str) {
    genus = str;
}

void Plant::setNickname(string str) {
    nickname = str;
}

int Plant::getTWater() {
    return tWater;
}

int Plant::getTSun() {
    return tSun;
}

int Plant::getTFert() {
    return tFert;
}

string Plant::getName() {
    return name;
}

string Plant::getGenus() {
    return genus;
}

string Plant::getNickname() {
    return nickname;
}

void Plant::print() {
    cout << "******** " << name << " ********" << endl;
    cout << genus << endl;
    cout << nickname << endl;
    cout << "Needs water every " << tWater << " days" << endl;
    cout << "Needs " << tSun << " hours of sun every day" << endl;
    cout << "Needs fertilizer every " << tFert << " days" << endl;
    for (int i = 0; i < nameLen + 18; i++) {
        cout << "*";
    }
    cout << endl << endl;
}

string Plant::getStr() {
    string result = "";
    result = "w" + to_string(tWater) + "s";
    string sun = "";
    for (int i = 0; i < 4; i++) {
        if (tSun == T_SUN_NUM[i]) {
            sun = T_SUN_STR[i];
        }
    }
    result += sun + "f" + to_string(tFert);
    return result;
}