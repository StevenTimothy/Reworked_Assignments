#ifndef DECK_H  
#define DECK_H  
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

class Card;

/**
 * A Deck of Uno cards, consisting of both a draw and discard pile. The
 * methods draw() and discard() act in concert to (a) remove and return the
 * top card of the Deck, and (b) recycle a previously drawn Card to the
 * discard pile. remix() puts all discarded cards back in play and
 * reshuffles the deck.
 *
 * The values of static member variables can be changed to adjust the
 * content of the deck.
 */
class Deck {

public:
	/**
     * The number of non-zero number cards of each suit in the deck.
     */
    static const int NUMBER_OF_DUP_REGULAR_CARDS = 2;

    /**
     * The number of zero number cards of each suit in the deck.
     */
    static const int NUMBER_OF_DUP_ZERO_CARDS = 1;

    /**
     * The number of "special" cards (aka "action cards") of each suit in
     * the deck. These include, for instance, Skips and Reverses.
     */
    static const int NUMBER_OF_DUP_SPECIAL_CARDS = 2;

    /**
     * The number of (standard, non-Draw-4) wild cards in the deck.
     */
    static const int NUMBER_OF_WILD_CARDS = 4;

    /**
     * The number of Wild-Draw-4 in the deck.
     */
    static const int NUMBER_OF_WILD_D4_CARDS = 4;

    /**
     * In a shuffle, the number of deck-sizes that two cards in random
     * positions will be swapped. (Empirically, setting only to 1 gives a
     * good shuffle, but theoretically increasing this will lead to more
     * thoroughly shuffled decks.)
     */
    static const int SHUFFLE_FACTOR = 1;

    
    /**
     * Constructor for a new, full, shuffled Deck.
     */
    Deck();

    void fillDeck();

    /**
     * When performed on a Deck that is at least partially filled,
     * shuffles its cards randomly. Note that this does not fill the Deck,
     * nor does it combine any outstanding cards into the Deck.
     */
    void shuffle();

    /**
     * Returns true only if the Deck currently has no cards.
     */
    bool isEmpty();

    /**
     * Returns the top card of the Deck, and removes it.
     * @throws EmptyDeckException When called on an empty deck.
     * @see isEmpty
     */
    Card draw();

    /**
     * Discard the Card object passed so that it is out of play until a
     * remix operation.
     */
    void discard(Card c);

    /**
     * Remixes the deck by adding all previously discarded cards back into
     * the deck, and shuffling.
     */
    void remix();

    /**
     * Returns the list of discarded Cards since the last remix.
     */
    vector<Card> getDiscardedCards();

	string toString();

private:
	vector<Card> cards;
    vector<Card> discardedCards;
};
#endif
