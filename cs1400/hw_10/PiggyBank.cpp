#include "PiggyBank.h"

/************************************************************************
*								PiggyBank()								*
*	This is the default constructor, it sets broken to false and		*
*	savings to 0.														*
************************************************************************/
PiggyBank::PiggyBank()
{
	broken = false;
	savings = 0;
}

/************************************************************************
*						PiggyBank(double savings)						*
*	This is the overloaded constructor, it sets broken to false and		*
*	savings to user input.												*
************************************************************************/
PiggyBank::PiggyBank(double s)
{
	broken = false;

	if (s >= 0)
	{
		savings = s;
	}
	else
	{
		savings = 0;
	}
}

/************************************************************************
*								~PiggyBank()							*
*	This is the deconstructor, it checks to see if the piggy bank was	*
*	broken and prints out a message if it was.							*
************************************************************************/
PiggyBank::~PiggyBank()
{
	if (broken)
	{
		std::cout << "The piggy bank was broken.\n";
	}
}

/************************************************************************
*								countSavings							*
*	This is an accessor function that returns the amount in the piggy	*
*	bank.																*
************************************************************************/
double PiggyBank::countSavings() const
{
	if (!broken)
	{
		return savings;
	}
	else
	{
		std::cout << "The Piggy Bank is broken.\n";
		return 0;
	}
}

/************************************************************************
*								depositMoney							*
*	This function adds money to the piggy bank if it is not broken.		*
************************************************************************/
bool PiggyBank::depositMoney(double money)
{
	if (!broken && money >= 0)
	{
		savings += money;
		return true;
	}
	else
	{
		if (broken)
		{
			std::cout << "You cant add money to a broken piggy bank.\n";
		}
		else
		{
			std::cout << "You cant add negative numbers to the piggy bank.\n";
		}

		return false;
	}
}

/************************************************************************
*								smash									*
*	This function breaks the piggy bank and returns the amount inside.	*
************************************************************************/
double PiggyBank::smash()
{
	//define some variables.
	double temp;									//This holds the savings amount so we can return it.

	if (!broken)
	{
		broken = true;

		temp = savings;
		savings = 0;

		return temp;
	}
	else
	{
		std::cout << "You cant break a broken piggy bank.\n";
		return 0;
	}
}

/************************************************************************
*								getIfBroken								*
*	This function checks to see if the piggyBank was broken.			*
************************************************************************/
bool PiggyBank::getIfBroken() const
{
	return broken;
}

/*
# include <iostream>
# include <fstream>
# include "PiggyBank.h"

using namespace std;

PiggyBank::PiggyBank()
{
	broken = false;
	savings = 0;
}

PiggyBank::PiggyBank(bool b, double s)
{
	broken = b;
	savings = s;
}

PiggyBank::~PiggyBank()
{
	if (broken)
	{
		cout << "Your Virtual Piggy Bank is now broken!!!\n";
		cout << "Thanks for using VPBSA (The Virtual Piggy Bank Savings Account)\n";
		cout << "Have a great day!\n";
		system("pause");
	}
}

double PiggyBank::countSavings()
{
	return savings;
}

void PiggyBank::depositMoney(double money)
{
	ofstream fout;
	double mySavings;

	if (!broken && money > 0)
	{
		savings += money;
		mySavings = savings;
		fout.open("savings.txt");
		fout << mySavings;
		fout.close();
	}
	else if (!broken && money == 0)
	{
		cout << "Haha, you cant put money in the bank if you aint got none!\n";
	}
	else if (!broken && money < 0)
	{
		cout << "There's no such thing as saving negative amounts of money, jeez!!!\n";
	}
	else if (broken)
	{
		cout << "You cant put money into a broken Piggy Bank, dummy!!!\n";
	}
}

double PiggyBank::smash()
{
	double savingsVal = savings;
	broken = true;
	savings = 0;
	return savingsVal;
}
*/