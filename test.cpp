#include <iostream>
#include <fstream>
#include "Utility.h"
#include "Plant.h"
#include "Garden.h"

using namespace std;

void testPlant();

void start_tests() {
    testPlant();
}

void testPlant() {
    cout << "Now testing Class Plant:" << endl << endl;
    Plant p("w3sFSf30l15nArrowhead Plant");
    p.print();
    string str = p.getStr();
    cout << str << endl;
}