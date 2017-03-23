#include "VendingMachine.h"

/************************************************************************
*							VendingMachine()							*
*	This is the default constructor for the Vending Machine class, It	*
*	initializes the Gum structs with the proper names and amounts of	*
*	items for each gum. It also sets the number of coins inserted to 0	*
*	and the total amount of coins in the machine to 0.					*
************************************************************************/
VendingMachine::VendingMachine()
{
	for (int i = 0; i < NUM_GUM; i++)
	{
		gumArray[i].name = GUM_NAMES[i];
		gumArray[i].numItems = GUM_AMOUNT;
	}

	totalMoney = 0;
	totalInserted = 0;
}

/************************************************************************
*								printStatus								*
*	This function prints the status of the machine. How much of each	*
*	gum there is, the amount of coins inserted already, and the total	*
*	amount of money in the machine.										*
************************************************************************/
std::string VendingMachine::printStatus() const
{
	//Define and initialize some variables.
	std::string output = "";								//This is the string that we are going to send back.

	for (int i = 0; i < NUM_GUM; i++)
	{
		output += std::to_string(i + 1) + ": " + std::to_string(gumArray[i].numItems) + " packs of " + gumArray[i].name + ".\n";
	}
	
	return output;
}

/************************************************************************
*								depositMoney							*
*	This function inserts a quarter into the machine.					*
************************************************************************/
void VendingMachine::depositMoney()
{
	totalInserted++;
}

/************************************************************************
*								purchaseGum								*
*	This function validates and tries to purchase a piece of gum, if	*
*	there was not enough money inserted, or there wasn't enough gum in	*
*	the machine the machine will eat your money because it is vintage.	*
************************************************************************/
int VendingMachine::purchaseGum(int type)
{
	if (totalInserted < 3)
	{
		totalMoney += (totalInserted * QUARTER);
		totalInserted = 0;

		return -1;
	}
	else
	{
		switch (type)
		{
		case 0:
			if (gumArray[type].numItems < 1)
			{
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 0;
			}
			else
			{
				gumArray[type].numItems--;
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 1;
			}

			break;
		case 1:
			if (gumArray[type].numItems < 1)
			{
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 0;
			}
			else
			{
				gumArray[type].numItems--;
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 1;
			}

			break;
		case 2:
			if (gumArray[type].numItems < 1)
			{
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 0;
			}
			else
			{
				gumArray[type].numItems--;
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 1;
			}

			break;
		case 3:
			if (gumArray[type].numItems < 1)
			{
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 0;
			}
			else
			{
				gumArray[type].numItems--;
				totalMoney += (totalInserted * QUARTER);
				totalInserted = 0;

				return 1;
			}

			break;
		default:
			totalMoney += (totalInserted * QUARTER);
			totalInserted = 0;

			return -2;
		}
	}
}

/************************************************************************
*								getGumName								*
*	This function returns the name of a specific gum.					*
************************************************************************/
std::string VendingMachine::getGumName(int type) const
{
	return gumArray[type].name;
}

/************************************************************************
*								restock									*
*	This function returns the name of a specific gum.					*
************************************************************************/
void VendingMachine::restock()
{
	for (int i = 0; i < NUM_GUM; i++)
	{
		gumArray[i].numItems = GUM_AMOUNT;
	}

	totalMoney = 0;
	totalInserted = 0;
}

/************************************************************************
*								getTotalMoney							*
*	This function returns the total money amount.						*
************************************************************************/
double VendingMachine::getTotalMoney() const
{
	return totalMoney;
}

/************************************************************************
*							getTotalInserted							*
*	This function returns the total inserted amount.					*
************************************************************************/
int VendingMachine::getTotalInserted() const
{
	return totalInserted;
}