#include "User.h"
User::User() {}
;
User::User(std::string userID) {};
void User::setUserID(std::string userID) {};
std::string User::getUserID() const {};
void User::setPin() {};
signed User::getBalance() const {};
//LOGIN METHOD
void User::login(signed check_pin) {};
//UPDATE METHOD USE FOR UPDATING DATA IN FILE
void User::update() {};

//ADD FRIEND
void User::addFriend(std::string friendAccount_ID) {};
void User::showFriendList() {};
//WHEN LOGIN SUCCESSFULY
void User::withdraw(signed money) {};
void User::deposit(signed money) {};
//TRANSFER MONEY
void User::transfer(signed money) {};

void User::receive(signed money) {};

std::string User::to_string() {};
