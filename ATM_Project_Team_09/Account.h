#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>

using namespace std;

struct transferInfo{
    string transferToId;
    long int transferAmount;
};

class Account
{

private:
    string accountID;
	string PIN;
	long int balanceOfAccount;
	vector<string> friendList;

    transferInfo accountTransferInfo;


public:
    Account();
    string getAccountID();
    string getPIN();
    long int getBalance();
    vector<string> getFriendList();
    transferInfo getTransferInfo();


    void setAccountID(string);
    void setPIN(string);
    void setBalance(long int);
    void setFriendList(vector<string>*);
    void setTransferInfo(string,long int);

    void addFriend(string);
    void removeFriend(string);

    void deposit();
    void withdraw();

    void transfer();
    void receive(long int);
    void resetTransferInfo();

    void printAccountInfo();
    void printFriendList();
    void printBalance();

};

#endif
