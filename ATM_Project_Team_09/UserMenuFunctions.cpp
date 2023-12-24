#include "UserMenuFunctions.h"

bool loginAccount(string& ID, ifstream& inFile) {

	string PIN_Input;
	cout << "ID: ";
	cin >> ID;
	cout << "PIN: ";
	cin >> PIN_Input;
	cout << endl;

	inFile.open("Account File Folder\\" + ID + ".txt");

	if (inFile.is_open()) {
		string PIN;
		inFile >> PIN;
		if (PIN_Input == PIN) {
			// clear the error flags
			inFile.clear();
			// move the cursor to the beginning of the file 
			// because we still need it on getDataFromCurrentAccount (nkvd2110)
			inFile.seekg(0, std::ios::beg);
			return true;
			// (inFile - accountFile) still open to process (nkvd2110)
		}
		else {
			cout << "PIN is invalid" << endl;
			inFile.close(); // close the accountFile if PIN is incorrect (nkvd2110)
			return false;
		}
	}
	else {
		cout << "Account does not exist" << endl;
		return false;
	}
}

// Get Information from txt file then apply for the pointer currentAccount (nkvd2110)

void getDataFromCurrentAccount(string& ID, Account* currentAccount, ifstream& inFile) {

	vector<string>* input = new vector<string>;
	vector<string>* listFriend = new vector<string>;


	for (string line; getline(inFile, line);) {
		input->push_back(line);
	}

	currentAccount->setPIN(input->at(0));
	currentAccount->setBalance(stoi(input->at(1)));
	currentAccount->setAccountID(ID);


	for (int i = 2; i < input->size(); i++) {
		listFriend->push_back(input->at(i));
	}

	currentAccount->setFriendList(listFriend);

	delete input;
	delete listFriend;
}

// open file to apply info from object to txt (nkvd2110)
void updateDataForAccountFile(string& ID, Account* currentAccount) {
	ofstream outFile;
	outFile.open("Account File Folder\\" + ID + ".txt");
	outFile << currentAccount->getPIN() << endl;
	outFile << currentAccount->getBalance() << endl;
	for (int i = 0; i < (currentAccount->getFriendList()).size(); i++) {
		outFile << (currentAccount->getFriendList())[i] << endl;
	}
	outFile.close();
}

// This function to finish transfer
void finishTransfer(transferInfo transferInfo) {
	if (transferInfo.transferToId != "" && transferInfo.transferAmount > 0) {
		Account* receiveAccount = new Account;

		ifstream inFileForReceiveAccount;
		inFileForReceiveAccount.open("Account File Folder\\" + transferInfo.transferToId + ".txt");

		getDataFromCurrentAccount(transferInfo.transferToId, receiveAccount, inFileForReceiveAccount);
		receiveAccount->receive(transferInfo.transferAmount);
		updateDataForAccountFile(transferInfo.transferToId, receiveAccount);
		inFileForReceiveAccount.close();
		delete receiveAccount;
	}
}