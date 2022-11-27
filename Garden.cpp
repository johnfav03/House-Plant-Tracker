#include "Garden.h"

using namespace std;

void printHead();
int printInterface();
void printInputAdd();
void printInputDel();
void printList();
void printPlant();
void readFile();
void writeFile();

Plant plantList[MAX_PLANTS_PER_GARDEN];
ifstream ins;
ofstream outs;
int numPlants = 0;
bool endLoop = false;

int main() {
	readFile();
	printHead();
	while (!endLoop) {
		int choice = printInterface();
		if (choice == 0) {
			endLoop = true;
		}
		else if (choice == 1) {
			printList();
		}
		else if (choice == 2) {
			printPlant();
		}
		else if (choice == 3) {
			printInputAdd();
		}
		else if (choice == 4) {
			printInputDel();
		}
	}
	writeFile();
}

void printHead() {
	cout << "************************" << endl;
	cout << "Welcome to your Garden!!" << endl;
	cout << "You have " << numPlants << " plants." << endl;
	cout << "************************" << endl << endl;
}

int printInterface() {
	int in;
	cout << "Select an option." << endl;
	cout << "0: Quit" << endl;
	cout << "1: See List" << endl;
	cout << "2: See Plant" << endl;
	cout << "3: Add Plant" << endl;
	cout << "4: Del Plant" << endl;
	cout << "Your selection >> ";
	cin >> in;
	cout << endl;
	return in;
}

void printInputAdd() {
	string str;
	cout << "Adding a plant." << endl;
	cout << "EX: w3sFSf30" << endl;
	cin.ignore();
	cout << "Your plant >> ";
	getline(cin, str);
	plantList[numPlants] = Plant(str);
	cout << "Common Name >> ";
	getline(cin, str);
	plantList[numPlants].setName(str);
	cout << "Scientific Name >> ";
	getline(cin, str);
	plantList[numPlants].setGenus(str);
	cout << "Name your plant >> ";
	getline(cin, str);
	plantList[numPlants].setNickname(str);
	numPlants++;
	cout << endl;
	writeFile();
}

void printInputDel() {
	int index;
	cout << "Deleting a plant." << endl;
	cout << "Input the index of the plant" << endl;
	cout << "Your plant >> ";
	cin >> index;
	cout << endl << endl;
	for (int i = index - 1; i < numPlants - 1; i++) {
		plantList[i] = plantList[i + 1];
	}
	numPlants--;
	writeFile();
}

void printList() {
	if (numPlants == 0) {
		cout << "No plants in your garden." << endl << endl;
		return;
	}
	for (int i = 0; i < numPlants; i++) {
		cout << i + 1 << ": " << plantList[i].getName() << endl;
	}
	cout << endl;
}

void printPlant() {
	int index;
	cout << "Printing a plant." << endl;
	cout << "Input the index of the plant" << endl;
	cout << "Your plant >> ";
	cin >> index;
	cout << endl << endl;
	plantList[index - 1].print();
}

void readFile() {
	ins.open(SAVE_FILE);
	char temp;
	string str;
	while (getline(ins, str)) {
		plantList[numPlants] = Plant(str);
		getline(ins, str);
		plantList[numPlants].setName(str);
		getline(ins, str);
		plantList[numPlants].setGenus(str);
		getline(ins, str);
		plantList[numPlants].setNickname(str);
		numPlants++;
	}
	ins.close();
}

void writeFile() {
	outs.open(SAVE_FILE, ofstream::out | ofstream::trunc);
	outs.close();
	outs.open(SAVE_FILE);
	for (int i = 0; i < numPlants; i++) {
		outs << plantList[i].getStr() << endl;
		outs << plantList[i].getName() << endl;
		outs << plantList[i].getGenus() << endl;
		outs << plantList[i].getNickname() << endl;
	}
	outs.close();
}