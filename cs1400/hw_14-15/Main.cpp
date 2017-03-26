#include <iostream>
#include <string>
#include <ctime>
#include "Scoreboard.h"
#include "Constants.h"
#include "StevenTimothy_UnoPlayer.h"
#include "DumbPlayer.h"
#include "Game.h"

using namespace std;

static vector<string> playerNames;
static vector<UnoPlayer *> playerClasses;

int main()
{
	// Seed the random number generator which is used to 
	// shuffle the deck and pick which player starts the game.
	srand((unsigned)time(NULL));
	
    // This indicates how many games to play. Start with
	// 1 game and get your code working properly before
	// increasing the number of games.
	int numGames = 1;
    
	// You may customize the names of your players
    playerNames.push_back("Player 1");
	playerNames.push_back("Player 2");
	playerNames.push_back("Player 3");
	playerNames.push_back("Player 4");

	// Create an instance of an UnoPlayer object for each player
	// To start you off I have created a game with the class you
	// are asked to implement and 3 dumb players. A DumbPlayer 
	// always returns valid moves, but has no strategy.
	playerClasses.push_back(new StevenTimothy_UnoPlayer());
	playerClasses.push_back(new DumbPlayer());
	playerClasses.push_back(new DumbPlayer());
	playerClasses.push_back(new DumbPlayer());

	Scoreboard s = Scoreboard(playerNames);
    for (int i=0; i<numGames; i++) {
        Game g = Game(&s,playerClasses);
        g.play();
    }

	cout<<"\nScore after "<<numGames<<" Game(s):\n";
	s.printScoreboard();
	
    return 0;
}
