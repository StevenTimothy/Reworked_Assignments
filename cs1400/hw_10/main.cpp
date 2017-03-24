/*
PROGRAM: Assignment 10
Written by Steven Timothy
This program keeps track of money in a piggy bank.
Last Modified: 03/24/2017
*/
#include <iostream>
#include <iomanip>								//This is for stream manipulation.

#include "PiggyBank.h"

//Declare prototypes.
void menu(PiggyBank piggyBank);

/************************************************************************
*								MAIN									*
************************************************************************/
int main()
{
	PiggyBank piggyBank;

	menu(piggyBank);

	return 0;
}

/************************************************************************
*								menu									*
*	This function gives the user a menu.								*
************************************************************************/
void menu(PiggyBank piggyBank)
{
	//Define some variables.
	char input;										//This is the users input.
	double money;									//This is the amount to deposit.
	bool done = false;								//This is whether the user wants to quit or not.

	std::cout << "Welcome to VPBSA (The Virtual Piggy Bank Savings Account).\n\n";

	while (!piggyBank.getIfBroken() && !done)
	{
		std::cout << "What would you like to do?\n";
		std::cout << "(d) Deposit money.\n";
		std::cout << "(s) See your savings.\n";
		std::cout << "(b) Break your virtual Piggy Bank.\n";
		std::cout << "(q) or Quit.\n";
		std::cin >> input;

		switch (input)
		{
		case 'd':
		case 'D':
			std::cout << "How much money would you like to deposit? $";
			std::cin >> money;
			piggyBank.depositMoney(money);
			std::cout << "Thanks, you now have $" << std::fixed << std::showpoint << std::setprecision(2) << piggyBank.countSavings() << " saved in your Virtual Piggy Bank.\n\n";
			break;
		case 's':
		case 'S':
			std::cout << "You have $" << std::fixed << std::showpoint << std::setprecision(2) << piggyBank.countSavings() << " saved in your Virtual Piggy Bank.\n\n";
			break;
		case 'b':
		case 'B':
			std::cout << "You smashed your Virtual Piggy Bank and recieved $" << std::fixed << std::showpoint << std::setprecision(2) << piggyBank.smash() << std::endl;
			break;
		case 'q':
		case 'Q':
			done = true;
			std::cout << "Thanks for using VPBSA (The Virtual Piggy Bank Savings Account)\n";
			std::cout << "Have a great day!\n";
			break;
		default:
			std::cout << "That\'s not an option!\n\n";
		}
	}
}

//Steven Timothy
//03/08/2014

/*
fout.open("savings.txt");
fout << mySavings;
fout.close();
*/
/*
# include <iostream>
# include <fstream>
# include <iomanip>
# include "PiggyBank.h"

using namespace std;

int main()
{
	ifstream fin;
	ofstream fout;
	bool broken = false;
	double mySavings;
	double money;
	char input;

	fin.open("savings.txt");
	if (fin.fail())
	{
		mySavings = 0;
	}
	else
	{
		fin >> mySavings;
		fin.close();
	}

	PiggyBank piggybank(false, mySavings);

	cout << "Welcome to VPBSA (The Virtual Piggy Bank Savings Account).\n\n";

	while (!broken)
	{
		cout << "What would you like to do?\n";
		cout << "(d) Deposit money.\n";
		cout << "(s) See your savings.\n";
		cout << "(b) Break your virtual Piggy Bank.\n";
		cout << "(q) or Quit.\n";
		cin >> input;

		if (input == 'd')
		{
			cout << "How much money would you like to deposit? $";
			cin >> money;
			piggybank.depositMoney(money);
			cout << "Thanks, you now have $" << fixed << showpoint << setprecision(2) << piggybank.countSavings() << " saved in your Virtual Piggy Bank.\n\n";
		}
		else if (input == 's')
		{
			cout << "You have $" << fixed << showpoint << setprecision(2) << piggybank.countSavings() << " saved in your Virtual Piggy Bank.\n\n";
		}
		else if (input == 'b')
		{
			cout << "You smashed your Virtual Piggy Bank and recieved $" << fixed << showpoint << setprecision(2) << piggybank.smash() << endl;
			broken = true;
			mySavings = 0;
			fout.open("savings.txt");
			fout << mySavings;
			fout.close();
		}
		else if (input == 'q')
		{
			break;
		}
		else
		{
			cout << "That's not an option!\n\n";
		}
	}

	if (!broken)
	{
		cout << "Thanks for using VPBSA (The Virtual Piggy Bank Savings Account)\n";
		cout << "Have a great day!\n";
		system("pause");
	}

	return 0;
}
*/