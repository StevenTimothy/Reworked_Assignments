#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <vector>
#include "Constants.h"

using std::vector;

class Card;
class Game;

/**
 * <p>A GameState object provides programmatic access to certain (legal)
 * aspects of an Uno game, so that interested players can take advantage of
 * that information. Note that not all aspects of a game's state
 * (<i>e.g.</i>, the direction of play, whose turn it is next, the actual
 * cards in each player's hand (!), etc.) are reflected in the GameState
 * object -- only those for which it makes sense for a player to have
 * access.</p>
 * @since 2.0
 */
class GameState {

public:
    /**
     * (Blank constructor, used only during testing.)
     */
    GameState();

    /**
     * Instantiate a new GameState object whose job it is to provide safe
     * access to the Game object passed.
     */
    GameState(Game *game);

    /**
     * Return an array of ints indicating the number of cards each player
     * has remaining. The array is ordered so that index 0 has the count
     * for the player who (barring action cards that might change it) will
     * play next, index 1 the player who (barring action cards) will play
     * second, etc.
     */
    vector<int> getNumCardsInHandsOfUpcomingPlayers();

    /**
     * Return an array of ints indicating the total overall score each
     * player has. The array is ordered so that index 0 has the count
     * for the player who (barring action cards that might change it) will
     * play next, index 1 the player who (barring action cards) will play
     * second, etc.
     */
    vector<int> getTotalScoreOfUpcomingPlayers();

    /**
     * Return the color most recently "called" (after playing a wild) by
     * each opponent. If a given opponent has not played a wild card this
     * game, the value will be Color.NONE. The array is ordered so that
     * index 0 has the count for the player who (barring action cards that
     * might change it) will play next, index 1 the player who (barring
     * action cards) will play second, etc.
     */
    vector<Color> getMostRecentColorCalledByUpcomingPlayers();

    /**
     * Return a list of <i>all</i> cards that have been played since the
     * last time the deck was remixed. This allows players to "card count"
     * if they choose.
     */
    vector<Card> getPlayedCards();

	private:
		Game *theGame;
		vector<int> numCardsInHandsOfUpcomingPlayers;
		vector<Color> mostRecentColorCalledByUpcomingPlayers;
		vector<int> totalScoreOfUpcomingPlayers;
};
#endif
