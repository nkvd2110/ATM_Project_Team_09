#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_FRIENDLY_ACCOUNTS = 10;

struct Account
{
    string id;
    string pin;
    double balance;
    string friendly_accounts[MAX_FRIENDLY_ACCOUNTS];
};

Account* getAccount(const string& id)
{
    string filename = id + ".txt";
    ifstream file(filename.c_str());
    if (!file.is_open())
    {
        return nullptr;
    }

    Account* account = new Account();

    file >> account->pin >> account->balance;
    for (int i = 0; i < MAX_FRIENDLY_ACCOUNTS; i++)
    {
        account->friendly_accounts[i] = "";
    }
    for (int i = 0; i < MAX_FRIENDLY_ACCOUNTS && file >> account->friendly_accounts[i]; i++)
    {
    }

    file.close();
    return account;
}

bool login(const string& id, const string& pin)
{
    Account* account = getAccount(id);
    if (account == nullptr)
    {
        return false;
    }

    return account->pin == pin;
}

void createAccount()
{

    string id = "exampleID";
    string pin;
    cout << "Enter your desired PIN (6 digits): ";
    cin >> pin;

    Account account;
    account.id = id;
    account.pin = pin;
    account.balance = 0;

    string filename = id + ".txt";
    ofstream file(filename.c_str());
    file << account.pin << " " << account.balance << endl;

    cout << "Your new ID is: " << id << endl;
}

void displayMenu()
{
    cout << "* ATM Main Menu *" << endl;
    cout << "1. Login" << endl;
    cout << "2. Create new account" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your choice: ";
}

int main()
{
    int choice;

    while (true)
    {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            string id, pin;
            cout << "Enter your ID: ";
            cin >> id;
            cout << "Enter your PIN: ";
            cin >> pin;

            if (login(id, pin))
            {
                cout << "Login successful!" << endl;
            }
            else
            {
                cout << "Invalid ID or PIN. Please try again." << endl;
            }
            break;
        case 2:
            createAccount();
            break;
        case 3:
            cout << "Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}