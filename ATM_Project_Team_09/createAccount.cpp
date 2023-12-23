#include "createAccount.h"

using namespace std;

string  ID_GENERATOR() {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> distNum(10000000, 99999999);
	int random = distNum(gen);
	uniform_int_distribution<int> distChar(65, 90);

	string letterPart;
	letterPart += distChar(gen);
	letterPart += distChar(gen);
	string numberPart = to_string(random);
	string ID = letterPart + numberPart;
	return ID;
}

string ACCOUNT_ID_CREATE() {
	bool fileIsExist = true;
	while (fileIsExist) {
		string ID = ID_GENERATOR();
		string fileName = ID + ".txt";
		ifstream inFile;
		inFile.open("Account File Folder\\" + fileName);
		if (inFile.is_open()) {
			fileIsExist = true;
			inFile.close();
		}
		else {
			return ID;
		}
	}
}

void createAccount(string ID) {
	cout << "Your ID is: " << ID << endl;
	string PIN;
	cout << "Please type PIN for your current account: ";
	bool flag = true;
	while (flag) {
		cin >> PIN;
		cout << endl;
		if (PIN.length() != 6) {
			cout << "PIN must have 6 digits" << endl;
			cout << "Try again: ";
			continue;
		}
		for (int i = 0; i < PIN.length(); i++) {
			if (PIN[i] < 48 || PIN[i] > 57) {
				cout << "PIN must have 6 digits" << endl;
				cout << "Try again: ";
				break;
			}
			if (i == 5) {
				flag = false;
			}
		}
	}

	ofstream outFile;
	string fileName = ID + ".txt";
	outFile.open("Account File Folder\\" + fileName);
	if (outFile.is_open()) {
		outFile << PIN << endl;
		outFile << 0 << endl;
	}
	else {
		cout << "File is not open" << endl;
	}
	outFile.close();
}