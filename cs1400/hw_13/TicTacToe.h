# ifndef TICTACTOE_H
# define TICTACTOE_H

//This is an enum that holds the status of the game.
enum Status { ONGOING, DRAW, PLAYER_1_WIN, PLAYER_2_WIN };

class TicTacToe
{
private:
	//Private member variables.
	char board[3][3];
	char player[2];
	int numMoves;
	Status status;

	//Private member functions.
	bool checkForWin(char c);

public:
	//Constructors.
	TicTacToe();

	//Public member functions.
	Status getStatus();
	char getPlayer1();
	char getPlayer2();
	char nextToMove();
	void reset();
	void displayInstructions();
	void displayBoard();
	bool move(int cell);
	bool valMove = false;
};

# endif