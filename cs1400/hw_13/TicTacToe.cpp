#include "TicTacToe.h"

#include <iostream>

/************************************************************************
*								TicTacToe()								*
*	This is the default constructor for TicTacToe class. It starts a	*
*	new game.															*
************************************************************************/
TicTacToe::TicTacToe()
{
	player[0] = 'X';
	player[1] = 'O';

	//Reset game.
	reset();
}

/************************************************************************
*								reset()									*
*	This function resets the game board and stats.						*
************************************************************************/
void TicTacToe::reset()
{
	numMoves = 0;
	status = ONGOING;

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			board[row][col] = ' ';
		}
	}
}

/************************************************************************
*								getStatus								*
*	This function returns the status of the game.						*
************************************************************************/
Status TicTacToe::getStatus()
{
	return status;
}

/************************************************************************
*								getPlayer1								*
*	This function returns the player ones character.					*
************************************************************************/
char TicTacToe::getPlayer1()
{
	return player[0];
}

/************************************************************************
*								getPlayer2								*
*	This function returns the player twos character.					*
************************************************************************/
char TicTacToe::getPlayer2()
{
	return player[1];
}

/************************************************************************
*								nextToMove								*
*	This function prints the character for the next person to play.		*
************************************************************************/
char TicTacToe::nextToMove()
{
	int playerIndex = numMoves % 2;
	return player[playerIndex];
}

/************************************************************************
*							displayInstructions							*
*	This function prints the instructions that we must follow.			*
************************************************************************/
void TicTacToe::displayInstructions()
{
	std::cout << "Tic Tac Toe\n\n";
	std::cout << "In this game X will go first.\n";
	std::cout << "To place your piece in the game choose the correct place\n";
	std::cout << "by entering in the number to which that space corresponds.\n";
	std::cout << "The spaces are numbered as such:\n\n";
	std::cout << "1 | 2 | 3\n";
	std::cout << "---------\n";
	std::cout << "4 | 5 | 6\n";
	std::cout << "---------\n";
	std::cout << "7 | 8 | 9\n\n";
}

/************************************************************************
*								displayBoard							*
*	This function prints the board.										*
************************************************************************/
void TicTacToe::displayBoard()
{

	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 3; col++)
		{
			std::cout << board[row][col];
			if (col == 0 || col == 1)
			{
				std::cout << "|";
			}
		}
		std::cout << std::endl;
		if (row == 0 || row == 1)
		{
			std::cout << "-----\n";
		}
	}
	std::cout << std::endl;
}

/************************************************************************
*									move								*
*	This function checks for a draw and places the values on the		*
*	board.																*
************************************************************************/
bool TicTacToe::move(int cell)
{
	//define some variables.
	int row = 0, col = 0;						//This is the row and col for the position

	switch (cell)
	{
	case 1: row = 0; col = 0; break;
	case 2: row = 0; col = 1; break;
	case 3: row = 0; col = 2; break;
	case 4: row = 1; col = 0; break;
	case 5: row = 1; col = 1; break;
	case 6: row = 1; col = 2; break;
	case 7: row = 2; col = 0; break;
	case 8: row = 2; col = 1; break;
	case 9: row = 2; col = 2; break;
	default: row = -1; col = -1; std::cout << "Invalid input... Enter a number between 1 and 9." << std::endl; break;
	}

	//Check if there was already a character there.
	if (board[row][col] == 'X' || board[row][col] == 'O')
	{
		if (board[row][col] == 'X' || board[row][col] == 'O')
		{
			valMove = false;
			std::cout << "Invalid input... This space is already been played." << std::endl;
		}
		else if (board[-1][-1])
		{
			valMove = false;
		}
	}
	else
	{
		board[row][col] = nextToMove();
		valMove = true;
	}	

	//Increase num moves if it was a valid move.
	if (valMove != false && !checkForWin(nextToMove()))
	{
		numMoves++;
	}

	//If all the cell are filled there was a draw.
	if (numMoves == 9)
	{
		status = DRAW;
	}

	return true;
}

/************************************************************************
*								checkForWin								*
*	This function checks whether a player has won or not.				*
************************************************************************/
bool TicTacToe::checkForWin(char c)
{
	if (board[0][0] == 'X' && board[0][1] == 'X' && board[0][2] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[1][0] == 'X' && board[1][1] == 'X' && board[1][2] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[2][0] == 'X' && board[2][1] == 'X' && board[2][2] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[0][0] == 'X' && board[1][0] == 'X' && board[2][0] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[0][1] == 'X' && board[1][1] == 'X' && board[2][1] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[0][2] == 'X' && board[1][2] == 'X' && board[2][2] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X')
	{
		status = PLAYER_1_WIN;
		return true;
	}
	else if (board[0][0] == 'O' && board[0][1] == 'O' && board[0][2] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	else if (board[1][0] == 'O' && board[1][1] == 'O' && board[1][2] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	else if (board[2][0] == 'O' && board[2][1] == 'O' && board[2][2] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	else if (board[0][0] == 'O' && board[1][0] == 'O' && board[2][0] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	else if (board[0][1] == 'O' && board[1][1] == 'O' && board[2][1] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	else if (board[0][2] == 'O' && board[1][2] == 'O' && board[2][2] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	else if (board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	else if (board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O')
	{
		status = PLAYER_2_WIN;
		return true;
	}
	return false;
}