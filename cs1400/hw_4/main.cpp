/*
PROGRAM: Assignment 4
Written by Steven Timothy
This program acts as a vintage gum vending machine, that you can deposit money and get gum.
Last Modified: 03/23/2017
*/

#include <iostream>
#include <iomanip>									//This is for stream manipulation.

#include "VendingMachine.h"

//Declare prototypes.
void menu(VendingMachine &machine);

/************************************************************************
*									MAIN								*
************************************************************************/
int main()
{
	VendingMachine machine;

	menu(machine);

	return 0;
}

/************************************************************************
*									menu								*
*	This program prints the menu and lets the user choose the action	*
*	that he would like to make.											*
************************************************************************/
void menu(VendingMachine &machine)
{
	//Define some variables.
	char input;												//This is what is going to catch the user input.
	int result;												//This holds the result of buying a piece of gum.

	do
	{
		//Clear the screen.
		system("CLS");

		//Print the menu.
		std::cout << "Vintage Gum Vending Machine!\n";
		std::cout << "$0.75 for each pack of gum\n\n";
		std::cout << "S - Report the machine status\n";
		std::cout << "D - Drop in a quarter\n";
		std::cout << "1 - Pull the 1st tab\n";
		std::cout << "2 - Pull the 2nd tab\n";
		std::cout << "3 - Pull the 3rd tab\n";
		std::cout << "4 - Pull the 4th tab\n";
		std::cout << "R - Restock the machine\n";
		std::cout << "Q - Quit\n";

		//Get the user input.
		std::cin >> input;

		//Validate input and do appropriate function calls depending on what the user chose.
		switch (input)
		{
		case 's':
		case 'S':
			system("CLS");

			//Manipulate output.
			std::cout << std::fixed << std::showpoint << std::setprecision(2);

			std::cout << machine.printStatus();

			std::cout << "There is $" << machine.getTotalMoney() << " in the machine.\n";
			std::cout << "And so far you have inserted $" << machine.getTotalInserted() * QUARTER << " in the machine.\n\n";

			system("pause");
			break;
		case 'd':
		case 'D':
			system("CLS");

			std::cout << "Chaching!\n\n";
			machine.depositMoney();
			system("pause");
			break;
		case '1':
			result = machine.purchaseGum(0);						//This determines what if statment to go to.

			system("CLS");

			if (result == 1)
			{
				std::cout << "Kerchunk...\n\n";
				std::cout << "A pack of " << machine.getGumName(0) << " pops out.\n\n";
			}
			else if (result == 0)
			{
				std::cout << "You hear the mechanical clanking, but no gum appears. \n\n";
			}
			else if (result == -1)
			{
				std::cout << "(nothing happens)\n\n";
			}
			else
			{
				std::cout << "Something went terribly wrong!!!\n\n";
			}

			system("pause");
			break;
		case '2':
			result = machine.purchaseGum(0);						//This determines what if statment to go to.

			system("CLS");

			if (result == 1)
			{
				std::cout << "Kerchunk...\n\n";
				std::cout << "A pack of " << machine.getGumName(0) << " pops out.\n\n";
			}
			else if (result == 0)
			{
				std::cout << "You hear the mechanical clanking, but no gum appears. \n\n";
			}
			else if (result == -1)
			{
				std::cout << "(nothing happens)\n\n";
			}
			else
			{
				std::cout << "Something went terribly wrong!!!\n\n";
			}

			system("pause");
			break;
		case '3':
			result = machine.purchaseGum(0);						//This determines what if statment to go to.

			system("CLS");

			if (result == 1)
			{
				std::cout << "Kerchunk...\n\n";
				std::cout << "A pack of " << machine.getGumName(0) << " pops out.\n\n";
			}
			else if (result == 0)
			{
				std::cout << "You hear the mechanical clanking, but no gum appears. \n\n";
			}
			else if (result == -1)
			{
				std::cout << "(nothing happens)\n\n";
			}
			else
			{
				std::cout << "Something went terribly wrong!!!\n\n";
			}

			system("pause");
			break;
		case '4':
			result = machine.purchaseGum(0);						//This determines what if statment to go to.

			system("CLS");

			if (result == 1)
			{
				std::cout << "Kerchunk...\n\n";
				std::cout << "A pack of " << machine.getGumName(0) << " pops out.\n\n";
			}
			else if (result == 0)
			{
				std::cout << "You hear the mechanical clanking, but no gum appears. \n\n";
			}
			else if (result == -1)
			{
				std::cout << "(nothing happens)\n\n";
			}
			else
			{
				std::cout << "Something went terribly wrong!!!\n\n";
			}

			system("pause");
			break;
		case 'r':
		case 'R':
			system("CLS");

			std::cout << "A grouchy-looking attendant shows up, opens the back, fiddles around a bit, closes it, and leaves.\n\n";
			machine.restock();

			system("pause");
			break;
		case 'q':
		case 'Q':
			system("CLS");

			std::cout << "See you later!\n\n";

			system("pause");
			break;
		default:
			system("CLS");

			std::cout << "I don't understand you!\n\n";
			system("pause");
			break;
		}
	} while (toupper(input) != 'Q');
}





/*
//Steven Timothy //Vintage Gum Vending Machine
#include <iostream> 
#include <iomanip> 
using namespace std;
int main() 
{
	char input; 
	bool done = false; 
	int numBeemans = 10; 
	int numDentyne = 10; 
	int numChiclets = 10; 
	int numCarefree = 10; 
	double moneyInMachine = 0; 
	int coinsDeposited = 0;
	cout << "Vintage Gum Vending Machine!\n"; 
	cout << "$0.75 for each pack of gum\n\n"; 
	cout << "s - Report the machine status\n"; 
	cout << "d - Drop in a quarter\n"; 
	cout << "1 - Pull the 1st tab\n"; 
	cout << "2 - Pull the 2nd tab\n"; 
	cout << "3 - Pull the 3rd tab\n"; 
	cout << "4 - Pull the 4th tab\n"; 
	cout << "r - Restock the machine\n"; 
	cout << "q - Quit\n";
	while (!done) 
	{
		cin >> input;
		switch (input) 
		{
		case 's':
			cout << "1: " << numBeemans << " packs of Beemans.\n"; 
			cout << "2: " << numDentyne << " packs of Dentyne.\n"; 
			cout << "3: " << numChiclets << " packs of Chiclets.\n"; 
			cout << "4: " << numCarefree << " packs of Carefree.\n"; 
			cout << "There is $" << fixed << showpoint << setprecision(2) << moneyInMachine << " in the machine.\n"; 
			system("pause");
			cout << "\n\nVintage Gum Vending Machine!\n"; 
			cout << "$0.75 for each pack of gum\n\n"; 
			cout << "s - Report the machine status\n"; 
			cout << "d - Drop in a quarter\n"; 
			cout << "1 - Pull the 1st tab\n"; 
			cout << "2 - Pull the 2nd tab\n"; 
			cout << "3 - Pull the 3rd tab\n"; 
			cout << "4 - Pull the 4th tab\n"; 
			cout << "r - Restock the machine\n"; 
			cout << "q - Quit\n"; 
			break;
		case 'd':
			cout << "Chaching!\n"; 
			coinsDeposited++; 
			moneyInMachine += 0.25; 
			break;
		case '1':
			if (coinsDeposited >= 3) 
			{
				cout << "Kerchunk\n";

				if (numBeemans > 3) 
				{
					numBeemans--;
					coinsDeposited = 0; 
					cout << "A pack of Beemans pops out.\n";
				}
				else 
				{
					cout << "You hear the mechanical clanking, but no gum appears. \n";
					coinsDeposited = 0;
				}
			}
			else 
			{
				cout << "(nothing happens)\n";
			} 
			system("pause");
			cout << "\n\nVintage Gum Vending Machine!\n"; 
			cout << "$0.75 for each pack of gum\n\n"; 
			cout << "s - Report the machine status\n"; 
			cout << "d - Drop in a quarter\n"; 
			cout << "1 - Pull the 1st tab\n"; 
			cout << "2 - Pull the 2nd tab\n"; 
			cout << "3 - Pull the 3rd tab\n"; 
			cout << "4 - Pull the 4th tab\n"; 
			cout << "r - Restock the machine\n"; 
			cout << "q - Quit\n"; 
			break;
		case '2':
			if (coinsDeposited >= 3) 
			{
				cout << "Kerchunk\n"; 
				if (numDentyne > 3)
				{
					numDentyne--; 
					coinsDeposited = 0;
					cout << "A pack of Dentyne pops out.\n";
				}
				else 
				{
					cout << "You hear the mechanical clanking, but no gum appears. \n";
					coinsDeposited = 0;
				}
			}
			else 
			{
				cout << "(nothing happens)\n";
			} 
			system("pause");
			cout << "\n\nVintage Gum Vending Machine!\n"; 
			cout << "$0.75 for each pack of gum\n\n"; 
			cout << "s - Report the machine status\n"; 
			cout << "d - Drop in a quarter\n"; 
			cout << "1 - Pull the 1st tab\n"; 
			cout << "2 - Pull the 2nd tab\n"; 
			cout << "3 - Pull the 3rd tab\n"; 
			cout << "4 - Pull the 4th tab\n"; 
			cout << "r - Restock the machine\n"; 
			cout << "q - Quit\n"; 
			break;

		case '3':
			if (coinsDeposited >= 3) 
			{
				cout << "Kerchunk\n"; 
				if (numChiclets > 3)
				{
					numChiclets--; 
					coinsDeposited = 0; 
					cout << "A pack of Chiclets pops out.\n";
				}
				else 
				{
					cout << "You hear the mechanical clanking, but no gum appears. \n";
					coinsDeposited = 0;
				}
			}
			else 
			{
				cout << "(nothing happens)\n";
			} 
			system("pause");
			cout << "\n\nVintage Gum Vending Machine!\n"; 
			cout << "$0.75 for each pack of gum\n\n"; 
			cout << "s - Report the machine status\n"; 
			cout << "d - Drop in a quarter\n"; 
			cout << "1 - Pull the 1st tab\n"; 
			cout << "2 - Pull the 2nd tab\n"; 
			cout << "3 - Pull the 3rd tab\n"; 
			cout << "4 - Pull the 4th tab\n"; 
			cout << "r - Restock the machine\n"; 
			cout << "q - Quit\n"; 
			break;
		case '4':
			if (coinsDeposited >= 3) 
			{
				cout << "Kerchunk\n"; 
				if (numCarefree > 3)
				{
					numCarefree--; 
					coinsDeposited = 0; 
					cout << "A pack of Carefree pops out.\n";
				}
				else
				{
					cout << "You hear the mechanical clanking, but no gum appears. \n";
					coinsDeposited = 0;
				}
			}
			else 
			{
				cout << "(nothing happens)\n";
			} 
			system("pause");
			cout << "\n\nVintage Gum Vending Machine!\n"; 
			cout << "$0.75 for each pack of gum\n\n"; 
			cout << "s - Report the machine status\n"; 
			cout << "d - Drop in a quarter\n";
			cout << "1 - Pull the 1st tab\n"; 
			cout << "2 - Pull the 2nd tab\n";
			cout << "3 - Pull the 3rd tab\n";

			cout << "4 - Pull the 4th tab\n";
			cout << "r - Restock the machine\n";
			cout << "q - Quit\n"; 
			break;
		case 'r':
			cout << "A grouchy-looking attendant shows up, opens the back, fiddles around a bit, closes it, and leaves.\n";
			numBeemans = 10; 
			numDentyne = 10; 
			numChiclets = 10; 
			numCarefree = 10; 
			moneyInMachine = 0; 
			coinsDeposited = 0; 
			system("pause");
			cout << "\n\nVintage Gum Vending Machine!\n"; 
			cout << "$0.75 for each pack of gum\n\n"; 
			cout << "s - Report the machine status\n";
			cout << "d - Drop in a quarter\n"; 
			cout << "1 - Pull the 1st tab\n";
			cout << "2 - Pull the 2nd tab\n"; 
			cout << "3 - Pull the 3rd tab\n"; 
			cout << "4 - Pull the 4th tab\n";
			cout << "r - Restock the machine\n"; 
			cout << "q - Quit\n"; 
			break;
		case 'q':
			cout << "See you later!\n";
			done = true; 
			break;
		default: 
			cout << "I don't understand you!\n";
			system("pause");
			cout << "\n\nVintage Gum Vending Machine!\n";
			cout << "$0.75 for each pack of gum\n\n";
			cout << "s - Report the machine status\n"; 
			cout << "d - Drop in a quarter\n";
			cout << "1 - Pull the 1st tab\n"; 
			cout << "2 - Pull the 2nd tab\n";
			cout << "3 - Pull the 3rd tab\n";
			cout << "4 - Pull the 4th tab\n"; 
			cout << "r - Restock the machine\n"; 
			cout << "q - Quit\n";
		}
	}
	system("pause"); 
	return 0;
}
*/