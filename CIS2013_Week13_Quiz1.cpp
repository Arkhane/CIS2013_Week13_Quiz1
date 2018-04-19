#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;


class BankAccount
{
private:


public:
	string name;
	string acctNumber = "0000000000";
	string phone = "(000) 000-0000";
	float balance = 0;
	float rate = 0.3;
	float  money;

	//print	


	void PrintSelction()
	{
		cout << "Select an action..." << endl;
		cout << "-----------------------------" << endl;
		cout << "Open a new accout (n)" << endl;
		cout << "deposit (d)" << endl;
		cout << "withdraw (w)" << endl;
		cout << "balance (b)" << endl;
		cout << "exit (y)" << endl;
		cout << "-----------------------------" << endl;
		cout << "What would you like to do?" << endl;
	}

	//input
	void Input(char x)
	{
		if (x == 'n')
		{
			cout << "Enter your first name and last name...." << endl;
			cin >> name;
		}

		if (x == 'd')
		{
			cout << "Enter amount of deposit..." << endl;
			cin >> money;
			balance += money;
		}

		if (x == 'w')
		{
			cout << "Enter amount you want to withdraw..." << endl;
			cin >> money;
			balance -= money;
		}

		if (x == 'b')
		{
			cout << name << ": your blance is: " << balance << endl;
		}
	}
};



class Savings : public BankAccount
{
private:
	float minimum_balance = 100;
	float withdraw_limit = 500;
	float withdraw;

public:

	void inSavings()
	{
		if (balance < minimum_balance)
		{
			cout << "Warning!! your balance is now below minimum blance." << endl;
		}
		if (withdraw > minimum_balance)
		{
			cout << "Your withdraw amount is over the limit." << endl;
		}
	}


};

class CheckingAcct : public BankAccount
{
private:
	int overdraft_fee;

public:
	void InCheackingAcct()
	{
		if (balance < 0)
		{
			cout << "Your Balance now below 0." << endl;
			cout << "$25 overdraft fee now added" << endl;
			overdraft_fee = +25;
		}

		balance = -overdraft_fee;
	}

};

int main()
{
	char userInput;
	char option;

	Savings myBank;
	CheckingAcct myCheck;


	myBank.PrintSelction();
	cin >> userInput;
	if (userInput == 'n')
	{
		myBank.Input(userInput);
		while (1)
		{
			cout << "-----------------------------" << endl;
			cout << "Hello " << myBank.name << ", your blance is : " << myBank.balance << endl;
			cout << "Account ID: " << myBank.acctNumber << "Phone : " << myBank.phone << endl;
			myBank.inSavings();
			myCheck.InCheackingAcct();
			myBank.PrintSelction();
			cin >> userInput;
			myBank.Input(userInput);


			;
			if (userInput == 'y')
			{
				break;
			}
		}
	}
	else
	{
		cout << "You have no account.." << endl;
	}






	return 0;
}