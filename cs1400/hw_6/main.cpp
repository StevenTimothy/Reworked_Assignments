/*
PROGRAM: Assignment 6
Written by Steven Timothy
This program is a script based devil's dice game.
Last Modified: 03/23/2017
*/
#include <iostream>
#include <windows.h>								//This is needed for the sleep function.
#include <time.h>									//This is so we can seed the srand with time.

//Declare prototypes.
void game();
void myTurn(int &myScore);
int roll();
void devilsTurn(int &devilsScore);

/************************************************************************
*									MAIN								*
************************************************************************/
int main()
{
	//Seed srand with time null.
	srand(static_cast<unsigned int>(time(NULL)));
	
	game();

	return 0;
}

/************************************************************************
*									game								*
*	This function executes the actual game.								*
************************************************************************/
void game()
{
	//Define and initialize some variables.
	bool gameOver = false;									//This is whether the game has been won or not.
	int myScore = 0;										//This holds the players score.
	int devilsScore = 0;									//This holds the devils score.

	std::cout << "The Devil's Dice!!!\n\n\n";
	Sleep(750);

	while (!gameOver)
	{
		myTurn(myScore);

		if (myScore >= 100)
		{
			std::cout << "Congradulations, you just won the game!\n";
			gameOver = true;
		}
		else if (myScore == -1)
		{
			std::cout << "Sorry, You just lost, the Devil wins the game!\n";
			gameOver = true;
		}

		Sleep(1000);

		if (!gameOver)
		{
			devilsTurn(devilsScore);

			if (devilsScore >= 100)
			{
				std::cout << "Sorry, You just lost, the Devil wins the game!\n";
				gameOver = true;
			}

			Sleep(1000);
		}
	}
}

/************************************************************************
*								myTurn									*
*	This function handles the players turn.								*
************************************************************************/
void myTurn(int &myScore)
{
	//Define and initialize some variables.
	char input;											//This holds the users choice.
	int dice = 0;											//This holds the number for the dice roll.
	int turnPoints = 0;									//This is holds the turns points.	

	std::cout << "It's your Turn!\n\n";
	Sleep(500);

	do
	{
		std::cout << "Would you like to (h)hold, (r)roll, or (f)forfeit: ";
		std::cin >> input;

		switch (input)
		{
		case 'h':
		case 'H':
			myScore += turnPoints;
			Sleep(1000);
			std::cout << "Great! You now have a total of " << myScore << " points locked in.\n\n";
			Sleep(1000);
			break;
		case 'r':
		case 'R':
			std::cout << "\nYou rolled the dice!\n";
			Sleep(1000);

			dice = roll();

			std::cout << "You rolled a ... " << dice << ".\n";

			if (dice == 1)
			{
				std::cout << "Drats! You busted back to " << myScore << " points.\n\n";
			}
			else
			{
				turnPoints += dice;
				std::cout << "You have a total of " << turnPoints << " turn points.\n";
				std::cout << "You have a total of " << myScore << " saved points.\n";
				std::cout << "You have a grand total of " << myScore + turnPoints << " points.\n\n";
			}

			break;
		case 'f':
		case 'F':
			myScore = -1;

			break;
		default:
			std::cout << "\nPlease enter either \"h\", \"r\", or \"f\".\n\n";

			break;
		}
	} while (input != 'h' && dice != 1 && myScore != -1);
}

/************************************************************************
*								devilsTurn								*
*	This function handles the devils turn.								*
************************************************************************/
void devilsTurn(int &devilsScore)
{
	//Define and initialize some variables.
	int dice;											//This holds the number for the dice roll.
	int turnPoints = 0;									//This is holds the turns points.
	int numDevilTries = 0;								//This is the number of tries the devil will try to play.


	std::cout << "It's the Devil's turn.\n\n";
	Sleep(500);

	for (numDevilTries; numDevilTries < 2; numDevilTries++)
	{
		std::cout << "The Devil decided to roll the dice.\n";
		Sleep(1000);

		dice = roll();

		std::cout << "The Devil rolled a ... " << dice << ".\n";

		if (dice == 1)
		{
			std::cout << "The Devil just busted back to " << devilsScore << " points.\n\n";
			break;
		}
		else
		{
			turnPoints += dice;
			std::cout << "The Devil has a total of " << turnPoints << " turn points.\n";
			std::cout << "The Devil has a total of " << devilsScore << " saved points.\n";
			std::cout << "The Devil has a grand total of " << devilsScore + turnPoints << " points.\n\n";
		}
	}
		
	if (numDevilTries == 2)
	{
		devilsScore += turnPoints;
		std::cout << "The devil decided to hold.\n\n";
		std::cout << "The Devil now has a total of " << devilsScore << " points locked in.\n\n";
	}
}

/************************************************************************
*								roll									*
*	This function rolls the dice.										*
************************************************************************/
int roll()
{
	return (rand() % 6) + 1;
}


/*
//Steven Timothy
//02/06/2014

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

int main()
{
	int die = 0;
	int myScore = 0;
	int advanceScore = 0;
	int devilScore = 0;
	int numTries = 0;
	char rollDice;
	bool gameOver = false;
	bool myTurn = true;

	srand((unsigned)time(NULL));

	cout << "The Devil's Dice!!!\n\n\n";
	sleep(750);
	cout << "It's your Turn!\n\n";
	sleep(500);

	while (!gameOver)
	{
		if (myTurn)
		{
			cout << "Would you like to (p)pass or (r)roll\n";
			cin >> rollDice;

			if (rollDice == 'p')
			{
				myScore += advanceScore;
				sleep(1000);
				cout << "Great! You now have a total of " << myScore << " points locked in.\n\n";
				sleep(1000);
				cout << "It's the Devil's turn.\n\n";
				advanceScore = 0;
				myTurn = false;
			}
			else if (rollDice == 'r')
			{
				cout << "\nYou rolled the dice!\n";
				sleep(1000);
				die = (rand() % 6) + 1;
				cout << "You rolled a ... " << die << ".\n";
				if (die == 1)
				{
					cout << "Drats! You busted back to " << myScore << " points.\n\n";
					cout << "It's the Devil's turn.\n\n";
					advanceScore = 0;
					myTurn = false;
				}
				else
				{
					advanceScore += die;
					cout << "You have a total of " << myScore + advanceScore << " points.\n\n";
				}
			}
			else
			{
				cout << "\nPlease enter either \"p\" or \"r\".\n\n";
			}
			if ((myScore + advanceScore) >= 100)
			{
				cout << "Congradulations, you just won the game!\n";
				gameOver = true;
			}
			sleep(1000);
		}
		else
		{
			numTries = 0;
			while (numTries < 2)
			{
				cout << "The Devil decided to roll the dice.\n";
				sleep(1000);
				die = (rand() % 6) + 1;
				cout << "The Devil rolled a ... " << die << ".\n";
				if (die == 1)
				{
					cout << "The Devil just busted back to " << devilScore << " points.\n\n";
					advanceScore = 0;
					break;
				}
				else
				{
					advanceScore += die;
					cout << "The Devil has a total of " << devilScore + advanceScore << " points.\n\n";
				}
				if ((devilScore + advanceScore) >= 100)
				{
					cout << "Sorry, You just lost, the Devil wins the game!\n";
					gameOver = true;
				}
				numTries++;
				sleep(1000);
			}
			if (gameOver == false)
			{
				if (die != 1)
				{
					devilScore += advanceScore;
					cout << "The devil decided to pass.\n\n";
					cout << "The Devil now has a total of " << devilScore << " points locked in.\n\n";
					advanceScore = 0;
				}
				else
				{
					advanceScore = 0;
					cout << "It's your turn!\n\n";
				}
			}
			sleep(1000);
			myTurn = true;
		}
	}

	system("pause");
	return 0;
}
*/