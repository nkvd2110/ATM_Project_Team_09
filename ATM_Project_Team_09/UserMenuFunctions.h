#ifndef __USERMENUFUNCTIONS_H__
#define __USERMENUFUNCTIONS_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <random>
#include "Account.h"

using namespace std;

bool loginAccount(string&, ifstream&);
void getDataFromCurrentAccount(string&, Account*, ifstream&);
void updateDataForAccountFile(string&, Account*);
void finishTransfer(transferInfo);

#endif 

