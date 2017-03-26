#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include "Constants.h"

/**
 * provide a prototype of class Game instead of including "Game.h" which
 * will cause a circular reference
 */
class Game;

using namespace std;

/**
 * comprised of a 3-tuple (color, rank, number). Not all of these values
 * are relevant for every particular type of card, however; for instance,
 * wild cards have no color (getColor() will return Color.NONE) or number
 * (getNumber() will return -1).
 *
 * A Card knows its forfeit cost (i.e., how many points it counts
 * against a loser who gets stuck with it) and how it should act during
 * game play (whether it permits the player to change the color, what
 * effect it has on the game state, etc.)
 */
class Card {


public:

	/**
     * Default Constructor
     */
	Card();

	/**
     * Constructor for non-number cards (skips, wilds, etc.)
     */
	Card(Color setColor, Rank setRank);

    /**
     * Constructor for number cards.
     */
	Card(Color setColor, int setNumber);

    /**
     * Constructor to explicitly set entire card state.
     */
	Card(Color setColor, Rank setRank, int setNumber);

    /**
     * Render this Card object as a string. Whether the string comes out
     * with ANSI color codes is controlled by the PRINT_IN_COLOR static
     * class variable.
     */
    void printCard(bool override=false);

    /**
     * Returns the number of points this card will count against a player
     * who holds it in his/her hand when another player goes out.
     */
    int forfeitCost();

    /**
     * Returns true only if this Card can legally be played on the up card
     * passed as an argument. The second argument is relevant only if the
     * up card is a wild.
     * @param c An "up card" upon which the current object might (or might
     * not) be a legal play.
     * @param calledColor If the up card is a wild card, this parameter
     * contains the color the player of that color called.
     */ 
    bool canPlayOn(Card c, Color calledColor);

    /**
     * Returns true only if playing this Card object would result in the
     * player being asked for a color to call. (In the standard game, this
     * is true only for wild cards.)
     */
    bool followedByCall();

    /**
     * This method should be called immediately after a Card is played,
     * and will trigger the effect peculiar to that card. For most cards,
     * this merely advances play to the next player. Some special cards
     * have other effects that modify the game state. Examples include a
     * Skip, which will advance <i>twice</i> (past the next player), or a
     * Draw Two, which will cause the next player to have to draw cards.
     * @param game The Game being played, whose state may be modified by
     * this card's effect.
     * @throws EmptyDeckException Thrown only in very exceptional cases
     * when a player must draw as a result of this card's effect, yet the
     * draw cannot occur because of un-shufflable deck exhaustion.
     */
    void performCardEffect(Game *game); // throws EmptyDeckException;

    /**
     * Returns the color of this card, which is Color.NONE in the case of
     * wild cards.
     */
	Color getColor();

    /**
     * Returns the rank of this card, which is Rank.NUMBER in the case of
     * number cards (calling getNumber() will retrieve the specific
     * number.)
     */
	Rank getRank();

    /**
     * Returns the number of this card, which is guaranteed to be -1 for
     * non-number cards (cards of non-Rank.NUMBER rank.)
     */
    int getNumber();

private:
	Color color;
    Rank rank;
    int number;

	void nextPlayerDraw(Game *game); // throws EmptyDeckException;

};
#endif
