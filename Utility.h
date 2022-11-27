#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <string>
using namespace std;

//filenames
const string SAVE_FILE = "plantData.txt";

//program constants
const string T_SUN_STR[4] = {"FS", "PS", "PD", "FD"};
const int T_SUN_NUM[4] = {8, 6, 4, 2};
const int MAX_PLANTS_PER_GARDEN = 50;

//test function
void start_tests();

#endif