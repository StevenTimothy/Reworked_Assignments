#ifndef GAME_H  
#define GAME_H
#include <vector>
#include "Card.h"
#include "Deck.h"
#include "GameState.h"
#include "Hand.h"
#include "Scoreboard.h"
#include "Constants.h"

/**
 * A Game object represents a single game of Uno in an overall match (of
 * possibly many games). Games are instantiated by providing them with a
 * roster of players, including a Scoreboard object through which scores
 * can be accumulated. The play() method then kicks off the game, which
 * will proceed from start to finish and update the Scoreboard. Various
 * aspects of the game's state (e.g., whether the direction of play
 * is currently clockwise or counterclockwise, whose player's turn is next)
 * can be accessed and controlled through functions in this class.
 * A GameState object can be obtained through the getGameState() function,
 * which allows UnoPlayers to selectively and legally examine certain
 * aspects of the game's state.
 */
class Game {

public:
    /**
     * The number of cards each player will be dealt at start of game.
     */
    static const int INIT_HAND_SIZE = 7;

    enum Direction { FORWARDS, BACKWARDS };


    /* variables to simplify access between Game and
     * GameState classes 
	 */
    Deck deck;
    vector<Hand> h;
    Card upCard;
    Direction direction;
    int currPlayer;
    Color calledColor;
    Scoreboard *scoreboard;
    vector<Color> mostRecentColorCalled;

    /**
     * Main constructor to instantiate a Game of Uno. Provided must be two
     * objects indicating the player roster: a Scoreboard, and a class
     * list. This constructor will deal hands to all players, select a
     * non-action up card, and reset all game settings so that play() can
     * be safely called.
     * @param scoreboard A fully-populated Scoreboard object that contains
     * the names of the contestants, in order.
     * @param playerClassList[] An array of Strings, each of which is a
     * fully-qualified package/class name of a class that implements the
     * UnoPlayer interface.
     */
    Game(Scoreboard *scoreboard, vector<UnoPlayer *> playerClassList);


    /**
     * Return the number of the next player to play, provided the
     * current player doesn't change things by playing an action card.
     */
    int getNextPlayer();

    /**
     * Go ahead and advance to the next player.
     */
    void advanceToNextPlayer();

    /**
     * Change the direction of the game from clockwise to counterclockwise
     * (or vice versa.)
     */
    void reverseDirection();

    /**
     * Play an entire Game of Uno from start to finish. Hands should have
     * already been dealt before this method is called, and a valid up card
     * turned up. When the method is completed, the Game's scoreboard object
     * will have been updated with new scoring favoring the winner.
     */
    void play();

    void print(string s);

    void println(string s);

    /**
     * Return the GameState object, through which the state of the game can
     * be accessed and safely manipulated.
     */
    GameState getGameState();

    /**
     * Return the Card that is currently the "up card" in the game.
     */
    Card getUpCard();

	
	private:

	/**
     * An object representing the state of the game at any point in time.
     * Note that much of the "state" is represented in the Game object
     * itself, and that this object provides a double-dispatch vehicle
     * through which select methods can access that state.
     */
    GameState state;

	void printState();
};
#endif
