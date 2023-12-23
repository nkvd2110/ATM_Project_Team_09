#include "displayMenu.h"

using namespace std;

void displayMenu2(int& optionMenu2, string& ID) {

	cout << "You are now logged in as " << ID << endl;
	cout << "----------------------------------------" << endl;
	cout << "What would you like to do?" << endl;
	cout << endl;
	cout << "1. Account Information" << endl;
	cout << "2. Withdraw money" << endl;
	cout << "3. Deposit money" << endl;
	cout << "4. Transfer money" << endl;
	cout << "5. Log out your account" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Your option : ";
	cin >> optionMenu2;
	cout << endl;
	while (cin.fail())
	{
		// Same as displayMenu1
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		cout << "Invalid input. Please enter an positive integer: ";
		cin >> optionMenu2;
	}
}


void displayMenu1(int& optionMenu1) {
	// Menu
	cout << "----------------------------------------" << endl;
	cout << "\tWelcome to Bank ABC" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Please choose a option below:" << endl;
	cout << endl;
	cout << "1. Login" << endl;
	cout << "2. Create a new account" << endl;
	cout << "3. Exit" << endl;
	cout << "----------------------------------------" << endl;
	cout << endl;
	cout << "Your option : ";
	cin >> optionMenu1;
	cout << endl;
	while (cin.fail()) // This will prevent user type char or string in input unless it start with a int (nkvd2110)
	{
		// clear the error flag
		cin.clear();

		// ignore the invalid input
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// print an error message
		cout << "Invalid input. Please enter an positive integer: ";

		// read the input again
		cin >> optionMenu1;
	}
}