#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

#include "displayMenu.h"
#include "createAccount.h"
#include "Account.h"
#include "UserMenuFunctions.h"

using namespace std;

int main() {
	int optionMenu1 = 0,
		optionMenu2 = 0;
	bool openApp = true;
	while(openApp) {
		displayMenu1(optionMenu1);
		if (optionMenu1 == 1)
		{	

			string ID = "";
			ifstream accountFile;

			if (loginAccount(ID,accountFile)) {

				Account* currentAccount = new Account;
				getDataFromCurrentAccount(ID, currentAccount, accountFile);

				while (true) {
					displayMenu2(optionMenu2, ID);
					if (optionMenu2 == 1) {
						currentAccount->printAccountInfo();
					}
					else if (optionMenu2 == 2) {
						currentAccount->withdraw();
						updateDataForAccountFile(ID, currentAccount);
					}
					else if (optionMenu2 == 3) {
						currentAccount->deposit();
						updateDataForAccountFile(ID, currentAccount);
					}
					else if (optionMenu2 == 4) {
						currentAccount->transfer();
						finishTransfer(currentAccount->getTransferInfo());
						currentAccount->resetTransferInfo();
						updateDataForAccountFile(ID, currentAccount);
					}
					else if (optionMenu2 == 5) {
						accountFile.close(); // close accountFile after log out (nkvd2110)
						delete currentAccount; // delete instance of class after using (nkvd2110)
						break;
					}
					else {
						cout << "There is no option " << optionMenu2 << endl;
						cout << endl;
					}
				}

			}
		}
		else if (optionMenu1 == 2)
		{
			createAccount(ACCOUNT_ID_CREATE());
		}
		else if (optionMenu1 == 3)
		{
			cout << "----------------------------------------" << endl;
			cout << "Goodbye. Thank you for using our service." << endl;
			cout << "----------------------------------------" << endl;
			openApp = false;
		}
		else {
			cout << "There is no option " << optionMenu1 << endl;
			cout << endl;
		}
	}

	return 0;
}








/*
Project for CS255
Nguyen Khanh Viet Dung HUST - TROY-IT 
*/