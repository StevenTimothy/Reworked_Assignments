#include "Scoreboard.h"
    /**
     * Create a new Scoreboard object, given an array of player names.
     */
    Scoreboard::Scoreboard(vector<string> setPlayerList) {
		int numPlayers=setPlayerList.size();
			
        for (int i=0; i<numPlayers; i++) {
            scores.push_back(0);
        }
        playerList = setPlayerList;
    }

    /**
     * Award points to a particular player.
     * @param player The zero-based player number who just won a game.
     * @param points The number of points to award.
     */
    void Scoreboard::addToScore(int player, int points) {
        scores[player] += points; 
    }

    /**
     * Obtain the score of a particular player.
     * @param player The zero-based player number whose score is desired.
     */
    int Scoreboard::getScore(int player) {
        return scores[player];
    }

    /**
     * Render the Scoreboard as a string for display during game play.
     */
    void Scoreboard::printScoreboard() {
        string retval = "";
		int numScores=scores.size();
        for (int i=0; i<numScores; i++) {
            cout<<playerList[i]<<": "<<scores[i]<<"\n";
        }
    }

    /**
     * Return the list of player names.
     */
    vector<string> Scoreboard::getPlayerList() {
        return playerList;
    }

    /**
     * Return the number of players in the game.
     */
    int Scoreboard::getNumPlayers() {
        return playerList.size(); 
    }

    /**
     * Return the zero-based number of the player who has won the game,
     * presuming someone has. (This method should only be called
     * once the end of the entire match has been detected by some other
     * means, and returns the number of the player with the highest score.)
     */
    int Scoreboard::getWinner() {
        int winner = 0;
        int topScore = scores[0];
    
        int numScores=scores.size();
        for (int i=1; i<numScores; i++) {
            if (scores[i] > topScore) {
                topScore = scores[i];
                winner = i;
            }
        }
        return winner;
    }
