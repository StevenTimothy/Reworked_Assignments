#ifndef StevenTimothy_UNOPLAYER_H
#define StevenTimothy_UNOPLAYER_H
#include "UnoPlayer.h"


/**
 * An interface that Uno-playing strategies implement in order to
 * compete in an Uno tournament. It consists of two methods which the
 * simulator calls each time a player's turn arises: play(), which chooses
 * a card from the hand according to some custom algorithm, and callColor()
 * (which is only called if the user chooses to play a wild) that asks the
 * player what color to "call."
 */
class StevenTimothy_UnoPlayer: public UnoPlayer { 

public:
	StevenTimothy_UnoPlayer();   // default constructor

	/**
     * This method is called when it's your turn and you need to
     * choose what card to play.
     *
     * The hand parameter tells you what's in your hand. You can call
     * getColor(), getRank(), and getNumber() on each of the cards it
     * contains to see what it is. The color will be the color of the card,
     * or "NONE" if the card is a wild card. The rank will be
     * "NUMBER" for all numbered cards, and another value (e.g.,
     * "SKIP," "REVERSE," etc.) for special cards. The value of
     * a card's "number" only has meaning if it is a number card. 
     * (Otherwise, it will be -1.)
     *
     * The upCard parameter works the same way, and tells you what the 
     * up card (in the middle of the table) is.
     *
     * The calledColor parameter only has meaning if the up card is a
     * wild, and tells you what color the player who played that wild card
     * called.
     *
     * Finally, the state parameter is a GameState object on which you
     * can invoke methods if you choose to access certain detailed
     * information about the game (like who is currently ahead, what colors
     * each player has recently called, etc.)
     *
     * You must return a value from this method indicating which card you
     * wish to play. If you return a number 0 or greater, that means you
     * want to play the card at that index. If you return -1, that means
     * that you cannot play any of your cards (none of them are legal plays)
     * in which case you will be forced to draw a card (this will happen
     * automatically for you.)
     */
	int play(vector<Card> hand, Card upCard, Color calledColor, GameState state);
	
	/**
     * This method will be called when you have just played a
     * wild card, and is your way of specifying which color you want to 
     * change it to.
     *
     * You must return a valid Color value from this method. You must
     * not return the value NONE under any circumstances.
     */
    Color callColor(vector<Card> hand);

};
#endif
