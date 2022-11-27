#ifndef _PLANT_H_
#define _PLANT_H_

#include <iostream>
#include <cmath>
#include <sstream>
#include "Utility.h"

class Plant {
private:
    int tWater;
    int tSun;
    int tFert;
    int nameLen;
    string name;
    string genus;
    string nickname;

public:
    Plant();
    Plant(string str);
    void setTWater(int n);
    void setTSun(string str);
    void setTFert(int n);
    void setName(string str);
    void setGenus(string str);
    void setNickname(string str);
    int getTWater();
    int getTSun();
    int getTFert();
    string getName();
    string getGenus();
    string getNickname();
    void print();
    string getStr();
};

#endif