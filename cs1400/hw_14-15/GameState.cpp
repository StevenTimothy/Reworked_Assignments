#include "GameState.h"
#include "Card.h"
#include "Game.h"
#include "UnoPlayer.h"
#include "Hand.h"
#include "Deck.h"

    /**
     * (Blank constructor, used only during testing.)
     */
    GameState::GameState() {
        //numCardsInHandsOfUpcomingPlayers = new int[4];
       // mostRecentColorCalledByUpcomingPlayers = new UnoPlayer.Color[4];
        //totalScoreOfUpcomingPlayers = new int[4];
    }

    /**
     * Instantiate a new GameState object whose job it is to provide safe
     * access to the Game object passed.
     */
    GameState::GameState(Game *game) {

        if (game->direction == game->FORWARDS) {
			int handSize=game->h.size();
            for (int i=0; i<handSize; i++) {
                numCardsInHandsOfUpcomingPlayers.push_back( 
					game->h[(game->currPlayer + i + 1) %
                        game->scoreboard->getNumPlayers()].size());
				totalScoreOfUpcomingPlayers.push_back(
                    game->scoreboard->getScore((game->currPlayer + i + 1) %
                        game->scoreboard->getNumPlayers()));
                mostRecentColorCalledByUpcomingPlayers.push_back(
                    game->mostRecentColorCalled[(game->currPlayer + i + 1) %
                        game->scoreboard->getNumPlayers()]);
            }
        }
        else {
            int handSize=game->h.size();
            for (int i=0; i<handSize; i++) {
                numCardsInHandsOfUpcomingPlayers.push_back(
                    game->h[(game->currPlayer - i - 1 +
                        game->scoreboard->getNumPlayers()) %
                        game->scoreboard->getNumPlayers()].size());
                totalScoreOfUpcomingPlayers.push_back(
                    game->scoreboard->getScore((game->currPlayer - i - 1 +
                        game->scoreboard->getNumPlayers()) %
                        game->scoreboard->getNumPlayers()));
				mostRecentColorCalledByUpcomingPlayers.push_back(
                    game->mostRecentColorCalled[(game->currPlayer - i - 1 +
                        game->scoreboard->getNumPlayers()) %
                        game->scoreboard->getNumPlayers()]);
            }
        }
        theGame = game;
    }

    /**
     * Return an array of ints indicating the number of cards each player
     * has remaining. The array is ordered so that index 0 has the count
     * for the player who (barring action cards that might change it) will
     * play next, index 1 the player who (barring action cards) will play
     * second, etc.
     */
    vector<int> GameState::getNumCardsInHandsOfUpcomingPlayers() {
        return numCardsInHandsOfUpcomingPlayers;
    }

    /**
     * Return an array of ints indicating the total overall score each
     * player has. The array is ordered so that index 0 has the count
     * for the player who (barring action cards that might change it) will
     * play next, index 1 the player who (barring action cards) will play
     * second, etc.
     */
    vector<int>  GameState::getTotalScoreOfUpcomingPlayers() {
        return totalScoreOfUpcomingPlayers;
    }

    /**
     * Return the color most recently "called" (after playing a wild) by
     * each opponent. If a given opponent has not played a wild card this
     * game, the value will be Color.NONE. The array is ordered so that
     * index 0 has the count for the player who (barring action cards that
     * might change it) will play next, index 1 the player who (barring
     * action cards) will play second, etc.
     */
    vector<Color> GameState::getMostRecentColorCalledByUpcomingPlayers() {
        return mostRecentColorCalledByUpcomingPlayers;
    }

    /**
     * Return a list of <i>all</i> cards that have been played since the
     * last time the deck was remixed. This allows players to "card count"
     * if they choose.
     */
    vector<Card> GameState::getPlayedCards() {
        if (theGame != NULL) {
            return theGame->deck.getDiscardedCards();
        }
        else {
            // testing only
            vector<Card> emptyVector;
			return emptyVector;
        }

		
    }
