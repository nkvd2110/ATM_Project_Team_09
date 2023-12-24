# ATM_Project_Team_09

This project was done by Nguyen Khanh Viet Dung
with helps from instructor of the course and members from .NET community.

INSTRUCTOR INFORMATION:
Dinh-Van nguyen, Ph.D
HUST

Using Visual Studio 2022

###Project Requirement
To login into an ATM, an user needs to have:
1. ID number (a 10 characters string)
2. PIN number (a positive 6 digits number)

Information for an individual user is stored in a file named: ID.txt with ID is the ID number of the user. 
For example, if the user has ID: AB12345678, his/her file should be named: AB12345678.txt
The format for the file is:
PIN AMOUNT
ACC1
ACC2
ACC3
...
with PIN is the PIN number and AMOUNT is the account balance (positive number from 0 - 1e9).
and ACC1, ACC2 .... are friendly account IDs. An user can have any number of friendly accounts. 

The main menu of an ATM initially has 3 options:
1. Login: user will be asked for ID and PIN. Unsuccessful login returns user to the main menu.
2. Create new account: user will be given a random ID (10 characters string) and set his/her own password. the initial balance is 0. 
3. Exit

If the user successfully logged in, the following menu appears:
1. Account Information
2. Withdraw money
3. Deposit money
4. Transfer money
5. Logout

- For option 1, the ATM print a report includes: Account ID, account balance, list of friendly account IDs.
- For option 2, the ATM display a menu:
1. 10
2. 20
3. 50
4. 100
5. other
if the user choose other, he/she needs to type in the amount of money to withdraw.
If there is not sufficient money in the account, an error appears: "Not Enough Money!"
Else, the money is deducted from the user's account. The amount should be updated to the account file.  

- For option 3, the ATM ask the user the amount of cash they want to deposit (positive number). Update the account balance once done.

- For option 4, the ATM, user can choose from a list of his/her friendly account or input in a new account ID.
in case a new account ID inputed, the system will ask if the user want to save it to the friendly list.
Then user can input the amount of money to transfer. 
Insufficient money to transfer will result in an error message: "Not Enough Money".
Otherwise, the account balance of the user and the destination are updated.

- For option 5, the ATM goes back to the main menu. 
Write a C++ program for the ATM above. 
An Object Oriented Programming solution (using classes will be considered for a bonus of 1.5 pts)