#include<string>
#include<stdlib.h>
#include<vector>
#include<iostream>
#include<fstream>
#pragma once
class User {
private:
	signed pin;
	signed balance;
public:
	//GENERATE CONSTRUCTOR AND GETTER/SETTER METHOD
	std::string userID;
	User();
	User(std::string userID);
	void setUserID(std::string userID);
	std::string getUserID() const;
	void setPin();
	signed getBalance() const;
	//LOGIN METHOD
	void login(signed check_pin);
	//UPDATE METHOD USE FOR UPDATING DATA IN FILE
	void update();
	//ADD FRIEND
	void addFriend(std::string friendAccount_ID);
	void showFriendList();
	//WHEN LOGIN SUCCESSFULY
	void withdraw(signed money);
	void deposit(signed money);
	//TRANSFER MONEY
	void transfer(signed money);
	void receive(signed money);
	//PRIN USER
	std::string to_string();


};
#pragma once