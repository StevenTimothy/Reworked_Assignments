/*
PROGRAM: Assignment 13
Written by Steven Timothy
This program allows us to play tic tac toe.
Last Modified: 03/26/2017
*/
#include <iostream>
#include <string>

#include "TicTacToe.h"

/************************************************************************
*								MAIN									*
************************************************************************/
int main()
{
	//Initialize a game object.
	TicTacToe game;

	//Initialize some variables.
	char playAgain;										//This is answer for whether the user wants to play again.
	std::string cellStr;
	bool playAgainVal;									//This is the bool that says wheather the player wants to play again.
	int cell = -1;

	do
	{
		//Reset the game.
		game.reset();
		//Display what we need to do.
		game.displayInstructions();
		//Print the board.
		game.displayBoard();

		//Play the game.
		while (game.getStatus() == ONGOING)
		{
			//Until cell is a valid input.
			do
			{
				std::cout << "Enter move for Player " << game.nextToMove() << ": ";
				std::getline(std::cin, cellStr);

				//Check to see if there are enough digits or if you entered a zero.
				if (cellStr.length() != 1 || cellStr == "0")
				{
					std::cout << "Invalid input... Enter a number between 1 and 9." << std::endl;
					cell = -1;
				}
				else
				{
					cell = std::stoi(cellStr.c_str());
				}
			} while (cell == -1);
			std::cout << std::endl;

			//but the new cell on the game.
			if (game.move(cell))
			{
				game.displayBoard();
			}
		}

		if (game.getStatus() == DRAW)
		{
			std::cout << "This game was a draw.\n";
		}
		else if (game.getStatus() == PLAYER_1_WIN)
		{
			std::cout << "Player X wins!\n";
		}
		else if (game.getStatus() == PLAYER_2_WIN)
		{
			std::cout << "Player O wins!\n";
		}

		//ask if you would like ot play again.
		do
		{
			std::cout << "\n\nWould you like to play again (y/n)?";
			std::cin >> playAgain;
			std::cout << std::endl;
			if (playAgain == 'y' || playAgain == 'n')
			{
				playAgainVal = true;
			}
			else
			{
				std::cout << "Invalid answer... Please enter either (y/n)" << std::endl;
				playAgainVal = false;
			}
		} while (playAgainVal == false);
		std::cin.ignore();
	} while (playAgain == 'y');

	return 0;
}