/*
PROGRAM: Assignment 7/8
Written by Steven Timothy
This program is the devils dice game.
Last Modified: 03/23/2017
*/
#include <iostream>
#include <Windows.h>								//This is needed for the sleep function.
#include <time.h>									//This is so we can seed the srand with time.
#include <iomanip>									//This is for stream manipulations.
#include <string>									//This is for string objects.
#include <fstream>									//This is for reading and writing to a file.

//Define and initialize some constants.
const std::string FILE_ = "devilDiceRecord.txt";

//Declare prototypes.
void game();
void myTurn(int &myScore, const int devilsScore);
int roll();
void devilsTurn(int &devilsScore, const int myScore);
void printScreen(const bool isMyTurn, const int myScore, const int devilsScore, const int turnPoints, const int die);
void printResults(const bool playerWins);

/************************************************************************
*									MAIN								*
************************************************************************/
int main()
{
	//Seed srand with time null.
	srand(static_cast<unsigned int>(time(NULL)));
	
	//Define some variables.
	char input;
	
	do
	{
		game();

		std::cout << "Would you like to play again (y or n)?\n";
		std::cout << "-> ";
		std::cin >> input;

	} while (toupper(input) == 'Y');

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
	bool playerWins = false;								//This is for the printResult function.

	while (!gameOver)
	{
		myTurn(myScore, devilsScore);

		if (myScore >= 100)
		{
			gameOver = true;
			playerWins = true;
			printScreen(true, myScore, devilsScore, 0, 0);
		}
		else if (myScore == -1)
		{
			gameOver = true;
			playerWins = false;
			printScreen(true, myScore, devilsScore, 0, 0);
		}

		if (!gameOver)
		{
			Sleep(1000);
			devilsTurn(devilsScore, myScore);

			if (devilsScore >= 100)
			{
				gameOver = true;
				playerWins = false;
				printScreen(false, myScore, devilsScore, 0, 0);
			}
		}
	}

	printResults(playerWins);
}

/************************************************************************
*								myTurn									*
*	This function handles the players turn.								*
************************************************************************/
void myTurn(int &myScore, const int devilsScore)
{
	//Define and initialize some variables.
	char input;											//This holds the users choice.
	int dice = 0;											//This holds the number for the dice roll.
	int turnPoints = 0;									//This is holds the turns points.	

	do
	{
		printScreen(true, myScore, devilsScore, turnPoints, dice);
		std::cout << "Would you like to (h)hold, (r)roll, or (f)forfeit: ";
		std::cin >> input;

		switch (input)
		{
		case 'h':
		case 'H':
			myScore += turnPoints;
			break;
		case 'r':
		case 'R':
			dice = roll();

			if (dice == 1)
			{
				turnPoints = 0;

				printScreen(true, myScore, devilsScore, turnPoints, dice);
			}
			else
			{
				turnPoints += dice;
			}

			break;
		case 'f':
		case 'F':
			myScore = -1;

			break;
		default:
			std::cout << "\nPlease enter either \"h\", \"r\", or \"f\".\n\n";

			system("pause");
			break;
		}
	} while (input != 'h' && dice != 1 && myScore != -1);
}

/************************************************************************
*								devilsTurn								*
*	This function handles the devils turn.								*
************************************************************************/
void devilsTurn(int &devilsScore, const int myScore)
{
	//Define and initialize some variables.
	int dice = 0;										//This holds the number for the dice roll.
	int turnPoints = 0;									//This is holds the turns points.
	int numDevilTries = 0;								//This is the number of tries the devil will try to play.

	printScreen(false, myScore, devilsScore, turnPoints, dice);
	Sleep(1000);

	for (numDevilTries; numDevilTries < 2; numDevilTries++)
	{
		dice = roll();
		printScreen(false, myScore, devilsScore, turnPoints, dice);
		Sleep(1000);

		if (dice == 1)
		{
			break;
		}
		else
		{
			turnPoints += dice;
		}
		
		Sleep(1000);
	}

	if (numDevilTries == 2)
	{
		devilsScore += turnPoints;
		printScreen(false, myScore, devilsScore, turnPoints, dice);
		Sleep(1000);
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

/************************************************************************
*								printScreen								*
*	This function prints the screen for the current game stats.			*
************************************************************************/
void printScreen(const bool isMyTurn, const int myScore, const int devilsScore, const int turnPoints, const int die)
{
	system("CLS");

	std::cout << std::right << std::setw(34) << "The Devil\'s Dice!\n\n";

	if (isMyTurn)
	{
		std::cout << std::setw(13) << "***\n";
	}
	else
	{
		std::cout << std::setw(43) << "***\n";
	}

	std::cout << std::setw(12) << "you" << std::setw(32) << "devil\n";
	std::cout << std::setw(12) << "---" << std::setw(32) << "-----\n";

	for (int i = 100; i >= 0; i -= 5)
	{
		//Print myScore counter.
		if ((myScore >= i) && (myScore < i + 5))
		{
			std::cout << std::right <<  std::setw(5) << myScore << std::setw(3) << "->";
		}
		else
		{
			std::cout << std::setw(8) << "";
		}

		//Print the left player's score increments.
		std::cout << std::left << std::setw(3) << "--" << std::setw(3) << i;

		//Print my turnpoints.
		if (isMyTurn && (turnPoints >= 100) && (turnPoints < i + 6))
		{
			std::cout << std::right << std::setw(3) << "<-" << std::setw(3) << turnPoints;
		}
		else if (isMyTurn && (turnPoints >= i) && (turnPoints < i + 5))
		{
			std::cout << std::setw(3) << "<-" << std::setw(3) << turnPoints;
		}
		else
		{
			std::cout << std::setw(6) << "";
		}

		if (i == 90)
		{
			std::cout << std::right << std::setw(7) << "die" << std::setw(4) << "";
		}
		else if (i == 85 || i == 75)
		{
			std::cout << std::right << std::setw(7) << "---" << std::setw(4) << "";
		}
		else if (i == 80)
		{
			std::cout << std::right << std::setw(4) << "|" << " " << die << " " << std::left << std::setw(4) << "|";
		}
		else if (i == 65 && myScore >= 100)
		{
			std::cout << std::right << std::setw(7) << "you" << std::setw(4) << "";
		}
		else if ((i == 65 && devilsScore >= 100) || (((i == 65 && devilsScore >= 100) || myScore == -1) && i == 65))
		{
			std::cout << std::right << std::setw(8) << "Devil" << std::setw(3) << "";
		}
		else if (i == 60 && myScore >= 100)
		{
			std::cout << std::right << std::setw(8) << "win!" << std::setw(3) << "";
		}
		else if ((i == 60 && devilsScore >= 100) || (((i == 60 && devilsScore >= 100) || myScore == -1) && i == 60))
		{
			std::cout << std::right << std::setw(8) << "wins!" << std::setw(3) << "";
		}
		else if (i == 55 && myScore >= 100)
		{
			std::cout << std::right << std::setw(7) << "<<<" << std::setw(4) << "";
		}
		else if ((i == 55 && devilsScore >= 100) || (((i == 55 && devilsScore >= 100) || myScore == -1) && i == 55))
		{
			std::cout << std::right << std::setw(7) << ">>>" << std::setw(4) << "";
		}
		else
		{
			std::cout << std::setw(11) << "";
		}

		//Print devil's turn points.
		if (!isMyTurn && (turnPoints >= 100) && (turnPoints < i + 6))
		{
			std::cout << std::setw(3) << turnPoints << std::setw(3) << "->";
		}
		else if (!isMyTurn && (turnPoints >= i) && (turnPoints < i + 5))
		{
			std::cout << std::setw(3) << turnPoints << std::setw(3) << "->";
		}
		else
		{
			std::cout << std::setw(6) << "";
		}

		std::cout << std::right << std::setw(3) << i << std::setw(3) << "--";

		if ((devilsScore >= i) && (devilsScore < i + 5))
		{
			std::cout << std::left << std::setw(3) << "<-" << devilsScore;
		}
		std::cout << std::endl;
	}
}

/************************************************************************
*								printResults							*
*	This function prints the wins losses record by reading and writing	*
*	to a file.															*
************************************************************************/
void printResults(const bool playerWins)
{
	//Define some variables.
	int wins;
	int losses;

	std::ifstream fin(FILE_);
	if (fin.fail())
	{
		std::cout << "Could not find devils dice record file...\n";
	}
	else
	{
		fin >> wins >> losses;
	}

	fin.close();

	if (playerWins)
	{
		wins++;
	}
	else
	{
		losses++;
	}

	std::cout << "You won: " << wins << " times\n";
	std::cout << "You lost: " << losses << " times\n";

	std::cout << std::fixed << std::showpoint << std::setprecision(2);

	std::cout << "Percentage of wins: " << (static_cast<double>(wins) / (wins + losses)) * 100 << "%\n";

	std::ofstream fout(FILE_);

	fout << wins << " " << losses;

	fout.close();
}

/*
//Steven Timothy
//02/17/2014
# include <iostream>
# include <iomanip>
# include <fstream>
# include <cstdlib>
# include <ctime>
# include <time.h>
# include <string>

using namespace std;

void printScreen(int die, int myScore, int devilScore, int advanceScore, bool myTurn)
{
	cout << string(50, '\n');
	cout << "                 The Devil's Dice!\n";
	cout << "\n";
	cout << setw(13);
	if (myTurn)
	{
		cout << "***\n";
	}
	else
	{
		cout << setw(43) << "***\n";
	}
	cout << setw(12) << "you" << setw(32) << "devil\n";
	cout << setw(12) << "---" << setw(32) << "-----\n";
	for (int i = 100; i >= 0; i -= 5)
	{
		//print MyScore counter
		if ((myScore >= i) && (myScore < i + 5))
		{
			cout << setw(5) << right << myScore << " > ";
		}
		else
		{
			cout << "        ";
		}

		// print left player's score increments
		cout << "-- " << left << setw(3) << i;

		// print my advance counter
		if (myTurn && (advanceScore >= 100) && (advanceScore < i + 6))
		{
			cout << " < " << setw(3) << advanceScore;
		}
		else if (myTurn && (advanceScore >= i) && (advanceScore < i + 5))
		{
			cout << " < " << setw(3) << advanceScore;
		}
		else
		{
			cout << "      ";
		}

		// print die in the middle, and the win message else nothing
		if (i == 90)
		{
			cout << "    die    ";
		}
		else if (i == 85 || i == 75)
		{
			cout << "    ---    ";
		}
		else if (i == 80)
		{
			cout << "   | " << die << " |   ";
		}
		else if (i == 65 && advanceScore >= 100)
		{
			if (myTurn)
			{
				cout << "    you    ";
			}
			else
			{
				cout << "   devil   ";
			}
		}
		else if (i == 60 && advanceScore >= 100)
		{
			if (myTurn)
			{
				cout << "    win!   ";
			}
			else
			{
				cout << "   wins!   ";
			}
		}
		else if (i == 55 && advanceScore >= 100)
		{
			if (myTurn)
			{
				cout << "    <<<    ";
			}
			else
			{
				cout << "   >>>>    ";
			}
		}
		else
		{
			cout << "           ";
		}

		// print devil's advance counter
		if (!myTurn && (advanceScore >= 100) && (advanceScore < i + 6))
		{
			cout << setw(3) << right << advanceScore << " > ";
		}
		else if (!myTurn && (advanceScore >= i) && (advanceScore < i + 5))
		{
			cout << setw(3) << right << advanceScore << " > ";
		}
		else
			cout << "      ";

		// print devil's score increments
		cout << setw(3) << right << i << " --";


		//print the devil's current score
		if ((devilScore >= i) && (devilScore<i + 5))
			cout << " < " << devilScore;

		cout << endl;

	}

}

void sleep(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}

int main()
{
	ifstream fin;
	ofstream fout;
	char action;
	char rollDice;
	int wins;
	int losses;
	int die = 1;
	int myScore = 0;
	int advanceScore = 0;
	int devilScore = 0;
	int numTries = 0;
	bool gameOver = false;
	bool myTurn = true;
	srand((unsigned)time(NULL));

	//score keeping


	fin.open("devilDiceRecord.txt");
	if (fin.fail())
	{
		wins = 0;
		losses = 0;
	}
	else
	{
		fin >> wins;
		fin >> losses;
		fin.close();
	}

	do
	{
		//print screen
		//printScreen(die, myScore, devilScore, advanceScore, myTurn);
		do
		{
			if (myTurn)
			{
				advanceScore = myScore;
				printScreen(die, myScore, devilScore, advanceScore, myTurn);
				while (myTurn)
				{
					cout << "\nWould you like to (r)roll or (p)pass or (f)forfeit\n";
					cin >> rollDice;
					if (rollDice == 'r')
					{
						die = (rand() % 6) + 1;
						if (die == 1)
						{
							advanceScore = myScore;
							printScreen(die, myScore, devilScore, advanceScore, myTurn);
							cout << "                 Drats! You busted!\n";
							sleep(2500);
							myTurn = false;
						}
						else
						{
							advanceScore += die;
							printScreen(die, myScore, devilScore, advanceScore, myTurn);
						}
					}
					else if (rollDice == 'p')
					{
						myScore = advanceScore;
						printScreen(die, myScore, devilScore, advanceScore, myTurn);
						sleep(1000);
						myTurn = false;
					}
					else if (rollDice == 'f')
					{
						printScreen(die, myScore, devilScore, advanceScore, myTurn);
						myTurn = false;
						gameOver = true;
					}
					else
					{
						cout << "\nPlease enter either \"r\", \"p\", or \"f\".\n\n";
					}
					if ((advanceScore) >= 100)
					{
						printScreen(die, myScore, devilScore, advanceScore, myTurn);
						wins++;
						myTurn = false;
						gameOver = true;
					}
				}
			}
			else
			{
				advanceScore = devilScore;
				printScreen(die, myScore, devilScore, advanceScore, myTurn);
				while (!myTurn)
				{
					numTries = 0;
					while (numTries < 2)
					{
						die = (rand() % 6) + 1;
						if (die == 1)
						{
							advanceScore = devilScore;
							printScreen(die, myScore, devilScore, advanceScore, myTurn);
							cout << "                 The Devil Busted!\n";
							sleep(1500);
							myTurn = true;
							numTries = 2;
						}
						else
						{
							advanceScore += die;
							printScreen(die, myScore, devilScore, advanceScore, myTurn);
						}
						if ((advanceScore) >= 100)
						{
							printScreen(die, myScore, devilScore, advanceScore, myTurn);
							devilScore = advanceScore;
							losses++;
							numTries = 2;
							myTurn = true;
							gameOver = true;
						}
						if (myTurn)
						{
							advanceScore = myScore;
						}
						numTries++;
						sleep(1500);
					}
					if (gameOver == false)
					{
						if (die != 1)
						{
							devilScore = advanceScore;
							printScreen(die, myScore, devilScore, advanceScore, myTurn);
							sleep(1500);
							myTurn = true;
							advanceScore = myScore;
						}
					}
				}
				advanceScore = myScore;
				myTurn = true;
			}
		} while (!gameOver);
		//score keeping
		fout.open("devilDiceRecord.txt");
		fout << wins << "\n";
		fout << losses;
		fout.close();
		cout << "\n";
		cout << "            win/loss record: " << wins << "/" << losses;
		cout << "  (" << 100 * wins / (wins + losses) << "%)\n\n";
		myTurn = true;
		gameOver = false;
		cout << "Do you want to play again? (y/n):";
		cin >> action;
		myScore = 0;
		advanceScore = 0;
		devilScore = 0;
	} while (action == 'y');

	return 0;
}*/