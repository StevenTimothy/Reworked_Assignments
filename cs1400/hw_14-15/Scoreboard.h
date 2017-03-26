#ifndef SCOREBOARD_H
#define SCOREBOARD_H
#include <vector>
#include <iostream>
#include <string>
using namespace std;

/**
 * A Scoreboard is a simple container for player names and their current
 * scores. It can do the obvious things like increment someone's score,
 * find the score for a particular player, and determine the winner at the
 * end of the game.
 * 
 */
class Scoreboard {

public:
	Scoreboard(){};

    /**
     * Instantiate a new Scoreboard object, given an array of player names.
     */
    Scoreboard(vector<string> setPlayerList);

    /**
     * Award points to a particular player.
     * @param player The zero-based player number who just won a game.
     * @param points The number of points to award.
     */
    void addToScore(int player, int points);

    /**
     * Obtain the score of a particular player.
     * @param player The zero-based player number whose score is desired.
     */
    int getScore(int player);

    /**
     * Render the Scoreboard as a string for display during game play.
     */
    void printScoreboard();

    /**
     * Return the list of player names.
     */
    vector<string> getPlayerList();

    /**
     * Return the number of players in the game.
     */
    int getNumPlayers();

    /**
     * Return the zero-based number of the player who has won the game,
     * presuming someone has. (This method should only be called
     * once the end of the entire match has been detected by some other
     * means, and returns the number of the player with the highest score.)
     */
    int getWinner();

private:
    vector<string> playerList;
    vector<int> scores;
};
#endif
