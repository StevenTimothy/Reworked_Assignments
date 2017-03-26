#ifndef HAND_H
#define HAND_H
#include <vector>
#include <iostream>
#include "UnoPlayer.h"

using namespace std;

class Card;
class Game;

/**
 * A Hand of Uno cards, held by a particular player. A Hand object is
 * responsible for playing a Card (i.e., actually choosing a card to
 * play) when the player's turn comes up. To do this, it implements the
 * strategy pattern by which this choice can be delegated to an arbitrary
 * implementer of the UnoPlayer class.
 */
class Hand {

public:
    /**
     * Instantiate a Hand object to be played by the UnoPlayer class, and
     * the player name, passed as arguments. This implements a strategy
     * pattern whereby the constructor accepts various strategies that
     * implement the UnoPlayer interface.
     */
    Hand(UnoPlayer *unoPlayer, string setPlayerName);

    /**
     * Add (draw) a card to the hand.
     */
    void addCard(Card c);

    /**
     * Return the number of cards in the hand.
     */
    int size();

    /**
     * It's your turn: play a card. When this method is called, the Hand
     * object choose a Card from the Hand based on the strategy that is
     * controlling it (<i>i.e.</i>, whose code was passed to the Hand
     * constructor.) If the player cannot legally play any of his/her
     * cards, null is returned.
     * @return The Card object to be played (which has been removed from
     * this Hand as a side effect), or null if no such Card can be played.
     */
    Card play(Game *game);

    /**
     * Designed to be called in response to a wild card having been played
     * on the previous call to this object's play() method. This method
     * will choose one of the four colors based on the strategy controlling
     * it (<i>i.e.</i>, the class whose code was passed to the Hand
     * constructor.)
     * return A Color value, <i>not</i> Color.NONE.
     */
    Color callColor(Game *game);

    /**
     * Return true only if this Hand has no cards, which should trigger a
     * winning condition.
     */
    bool isEmpty();

    /**
     * Prints this Hand. See Card::printCard() for
     * notes about how individual cards are rendered.
     */
    void printHand(bool override=false);

    /**
     * Return the forfeit value of this Hand, as it now stands (in other
     * words, the sum of all the forfeit values of cards still possessed.)
     */
    int countCards();

    /**
     * Return the name of the contestant.
     */
    string getPlayerName();

private:
	vector<Card> cards;
    UnoPlayer *player;
    string playerName;
};
#endif
