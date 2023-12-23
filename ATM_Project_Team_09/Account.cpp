#include "Account.h"

using namespace std;


Account::Account() {
	accountID = "";
	PIN = "";
	balanceOfAccount = 0;
	friendList = {};

	accountTransferInfo.transferToId = "";
	accountTransferInfo.transferAmount = 0;
	
}

//GETTER
string Account::getAccountID() {
	return accountID;
}

string Account::getPIN() {
	return PIN;
}

long int Account::getBalance() {
	return balanceOfAccount;
}

vector<string> Account::getFriendList() {
	return friendList;
}

transferInfo Account::getTransferInfo() {
	return accountTransferInfo;
}

//SETTER

void Account::setFriendList(vector<string>* input) {
	for (string friendOnList : (*input)) {
		friendList.push_back(friendOnList);
	}
}

void Account::setBalance(long int input) {
	balanceOfAccount = input;
}

void Account::setPIN(string input) {
	PIN = input;
}

void Account::setAccountID(string input) {
	accountID = input;
}

void Account::setTransferInfo(string input, long int amount) {
}

void Account::printAccountInfo() {
	cout << "----------------------------------------" << endl;
	cout << "Account ID: ";
	cout << accountID << endl;
	cout << "Balance: ";
	cout << balanceOfAccount << endl;
	cout << endl;
	printFriendList();
	cout << "----------------------------------------" << endl;
	cout << endl;
}

void Account::printFriendList() {
	cout << "List of friends:" << endl;
	for (int i = 0; i < friendList.size(); i++) {
		cout << (i+1) << ". " << friendList[i] << endl;
	}
}


void Account::deposit() {
	long int* depositAmount = new long int;
	cout << "Type the deposit amount. 0 for cancellation: ";
	cin >> *depositAmount;
	while ((*depositAmount) < 0 ) {
		cout << "Please type a positive number for deposit." << endl;
		cout << "Type the deposit amount. 0 for cancellation: ";
		cin >> *depositAmount;
	}

	if ((*depositAmount) == 0) {
		cout << endl;
		cout << "--- ";
		cout << "You have just canceled your deposit";
		cout << " ---";
		cout << endl << endl;
	}
	else {
		balanceOfAccount += *depositAmount;

		cout << endl;
		cout << "--- ";
		cout << "You have just deposited " << *depositAmount;
		cout << " ---";
		cout << endl << endl;
	}
	
	delete depositAmount;
}

void Account::withdraw() {
	long int* withdrawAmount = new long int;
	*withdrawAmount = 0;
	int* optionWithdraw = new int;
	cout << "----------------------------------------" << endl;
	cout << "Please choose the amount of money you want to withdraw" << endl;
	cout << endl;
	cout << "1. 10" << endl;
	cout << "2. 20" << endl;
	cout << "3. 50" << endl;
	cout << "4. 100" << endl;
	cout << "5. Other" << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	cout << "Your option: ";
	cin >> *optionWithdraw;
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid input. Please enter an positive integer: ";
		cin >> *optionWithdraw;
	}

	while (*optionWithdraw > 5 || *optionWithdraw <= 0) {
		cout << "There is no option " << *optionWithdraw << endl;
		cout << "Try again!" << endl;
			cout << "Your option: ";
		cin >> *optionWithdraw;
	}

	if (*optionWithdraw == 1) {
		*withdrawAmount = 10;
	}
	else if (*optionWithdraw == 2) {
		*withdrawAmount = 20;
	}
	else if (*optionWithdraw == 3) {
		*withdrawAmount = 50;
	}
	else if (*optionWithdraw == 4) {
		*withdrawAmount = 100;
	}
	else if (*optionWithdraw == 5) {
		cout << "Type the  withdraw amount. 0 for cancellation: ";
		cin >> *withdrawAmount;
		while ((*withdrawAmount) < 0) {
			cout << "Please type a positive number for withdraw." << endl;
			cout << "Type the  withdraw amount. 0 for cancellation: ";
			cin >> *withdrawAmount;
		}
	}

	if ((*withdrawAmount) > balanceOfAccount) {
		cout << endl;
		cout << "--- ";
		cout << "NOT ENOUGH MONEY!";
		cout << " ---";
		cout << endl << endl;
	}
	else if ((*withdrawAmount) == 0 ) {
		cout << endl;
		cout << "--- ";
		cout << "You have just canceled your withdrawal";
		cout << " ---";
		cout << endl << endl;
	}
	else {
		balanceOfAccount -= *withdrawAmount;

		cout << endl;
		cout << "--- ";
		cout << "You have just withdrawn " << *withdrawAmount;
		cout << " ---";
		cout << endl << endl;
	}
	
	delete optionWithdraw;
	delete withdrawAmount;
}

void Account::addFriend(string input) {
	friendList.push_back(input);
}

void Account::transfer() {

	int* optionWho = new int;

	cout << "----------------------------------------" << endl;
	cout << "Who do you want to transfer money to?" << endl;
	cout << endl;
	cout << "1. Account on Friendly List " << endl;
	cout << "2. Others" << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	cout << "Your option: ";
	cin >> *optionWho;

	while (*optionWho > 2 || *optionWho <= 0) {
		cout << "There is no option " << *optionWho << endl;
		cout << "Please try again!" << endl;
		cout << "Your option: ";
		cin >> *optionWho;
		cout << endl;
	}

	if (*optionWho == 1) {
		if (getFriendList().size() == 0) {
			cout << endl;
			cout << "You dont have any friend on the list" << endl;
			cout << endl;
		}
		else {
			cout << endl;
			printFriendList();
			cout << endl;
			int optionAccount = 0;
			cout << "Which account would you like to transfer?" << endl;
			cout << "Your option (Type the number corresponding to the ID): ";
			cin >> optionAccount;
			while (optionAccount <= 0 || optionAccount > getFriendList().size() ) {
				cout << "Please enter the number corresponding to the ID you want: ";
				cin >> optionAccount;

			}
			accountTransferInfo.transferToId = getFriendList()[optionAccount - 1];

			cout << endl;
			cout << "Type amount to transfer. 0 for cancellation: ";
			cin >> accountTransferInfo.transferAmount;

			while (accountTransferInfo.transferAmount < 0) {
				cout << "Please type a positive number." << endl;
				cout << "Type amount to transfer. 0 for cancellation: ";
				cin >> accountTransferInfo.transferAmount;
			}
			if (accountTransferInfo.transferAmount > balanceOfAccount) {
				accountTransferInfo.transferAmount = 0;

				cout << endl;
				cout << "--- ";
				cout << "NOT ENOUGH MONEY!";
				cout << " ---";
				cout << endl << endl;
			}
			else if (accountTransferInfo.transferAmount == 0) {
				cout << endl;
				cout << "--- ";
				cout << "You have just canceled your transfer";
				cout << " ---";
				cout << endl << endl;
			}
			else {
				balanceOfAccount -= accountTransferInfo.transferAmount;

				cout << endl;
				cout << "--- ";
				cout << "You just transfer " << accountTransferInfo.transferAmount << " to " << accountTransferInfo.transferToId ;
				cout << " ---";
				cout << endl << endl;
			}
		}
	}

	else if (*optionWho == 2) {
		cout << "Type the ID you want to transfer money to: ";
		cin >> accountTransferInfo.transferToId;
		ifstream inFile;
		inFile.open("Account File Folder\\" + accountTransferInfo.transferToId + ".txt");
		if ( !inFile.is_open() ) {	
			cout << "Account does not exist" << endl;
			cout << endl;
		}
		else {
			inFile.close();
			if (getFriendList().size() == 0) {
				cout << "Do you want to add this ID in your friendly list?" << endl;
				cout << "Type \'y\' for \"yes\" and \'n\' for \"no\": ";
				char addFriendOption;
				cin >> addFriendOption;
				while (true) {
					if (addFriendOption == 'y') {
						addFriend(accountTransferInfo.transferToId);
						break;
					}
					else if (addFriendOption == 'n') {
						break;
					}
					else {
						cout << "Please type only \'y\' for \"yes\" and \'n\' for \"no\": ";
						cin >> addFriendOption;
					}
				}
			}
			else {
				for (int i = 0; i < getFriendList().size(); i++) {
					if (getFriendList()[i] != accountTransferInfo.transferToId) {
						if (i == getFriendList().size() - 1) {
							cout << "Do you want to add this ID in your friendly list?" << endl;
							cout << "Type \'y\' for \"yes\" and \'n\' for \"no\": ";
							char addFriendOption;
							cin >> addFriendOption;
							while (true) {
								if (addFriendOption == 'y') {
									addFriend(accountTransferInfo.transferToId);
									break;
								}
								else if (addFriendOption == 'n') {
									break;
								}

								else {
									cout << "Please type only \'y\' for \"yes\" and \'n\' for \"no\": ";
									cin >> addFriendOption;
								}
							}

						}
					}
					else if (getFriendList()[i] == accountTransferInfo.transferToId) {
						break;
					}
				}
			}

			cout << endl;
			cout << "Type amount to transfer: ";
			cin >> accountTransferInfo.transferAmount;

			while (accountTransferInfo.transferAmount < 0) {
				cout << "Please type a positive number." << endl;
				cout << "Type amount to transfer. 0 for cancellation: ";
				cin >> accountTransferInfo.transferAmount;
			}
			if (accountTransferInfo.transferAmount > balanceOfAccount) {
				accountTransferInfo.transferAmount = 0;
				cout << endl;
				cout << "--- ";
				cout << "NOT ENOUGH MONEY!";
				cout << " ---";
				cout << endl << endl;
			}
			else if (accountTransferInfo.transferAmount == 0) {
				cout << endl;
				cout << "--- ";
				cout << "You have just canceled your transfer";
				cout << " ---";
				cout << endl << endl;
			}
			else {
				balanceOfAccount -= accountTransferInfo.transferAmount;

				cout << endl;
				cout << "--- ";
				cout << "You just transfer " << accountTransferInfo.transferAmount << " to " << accountTransferInfo.transferToId ;
				cout << " ---";
				cout << endl << endl;
			}
		}

	}

	delete optionWho;
}

void Account::receive(long int transferAmount) {
	balanceOfAccount += transferAmount;
}

void Account::resetTransferInfo() {
	accountTransferInfo.transferToId = "";
	accountTransferInfo.transferAmount = 0;
}