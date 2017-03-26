#include "Deck.h"
#include "Card.h"


    /**
     * Constructor for a new, full, shuffled Deck.
     */
	Deck::Deck() {
        fillDeck();
        shuffle();
    }

    void Deck::fillDeck() {
        for (int i=1; i<=9; i++) {
            for (int j=0; j<NUMBER_OF_DUP_REGULAR_CARDS; j++) {
                cards.push_back(Card(RED,i));
                cards.push_back(Card(YELLOW,i));
                cards.push_back(Card(BLUE,i));
                cards.push_back(Card(GREEN,i));
            }
        }
        // There are fewer "0" cards than other numbers.
        for (int j=0; j<NUMBER_OF_DUP_ZERO_CARDS; j++) {
            cards.push_back(Card(RED,0));
            cards.push_back(Card(YELLOW,0));
            cards.push_back(Card(BLUE,0));
            cards.push_back(Card(GREEN,0));
        }
        for (int j=0; j<NUMBER_OF_DUP_SPECIAL_CARDS; j++) {
            cards.push_back(Card(RED,SKIP));
            cards.push_back(Card(YELLOW,SKIP));
            cards.push_back(Card(GREEN,SKIP));
            cards.push_back(Card(BLUE,SKIP));
            cards.push_back(Card(RED,REVERSE));
            cards.push_back(Card(YELLOW,REVERSE));
            cards.push_back(Card(GREEN,REVERSE));
            cards.push_back(Card(BLUE,REVERSE));
            cards.push_back(Card(RED,DRAW_TWO));
            cards.push_back(Card(YELLOW,DRAW_TWO));
            cards.push_back(Card(GREEN,DRAW_TWO));
            cards.push_back(Card(BLUE,DRAW_TWO));
        }
        for (int i=0; i<NUMBER_OF_WILD_CARDS; i++) {
            cards.push_back(Card(NONE,WILD));
        }
        for (int i=0; i<NUMBER_OF_WILD_D4_CARDS; i++) {
            cards.push_back(Card(NONE,WILD_D4));
        }
    }

    /**
     * When performed on a Deck that is at least partially filled, the
     * cards are shuffled randomly. Note that this does not fill the Deck,
     * nor does it combine any outstanding cards into the Deck.
     */
    void Deck::shuffle() {
        int numCards= cards.size();
		for (int i=0; i<SHUFFLE_FACTOR * numCards; i++) {
            int x = rand() % numCards;
            int y = rand() % numCards;
            Card temp = cards[x];
            cards[x] = cards[y];
            cards[y] = temp;
        }
    }

    /**
     * Returns true only if the Deck currently has no cards.
     */
    bool Deck::isEmpty() {
        return cards.size() == 0;
    }

    /**
     * Returns the top card of the Deck, and removes it.
     * throws EMPTY_DECK When called on an empty deck.
     */
    Card Deck::draw() {
        if (cards.size() == 0) {
            throw EMPTY_DECK;
        }
		Card returnCard = cards[cards.size()-1];
		cards.pop_back();

        return returnCard;
    }

    /**
     * Discard the Card object passed so that it is out of play until a
     * remix operation.
     */
    void Deck::discard(Card c) { 
        discardedCards.push_back(c);
    }

    /**
     * Remixes the deck by adding all previously discarded cards back into
     * the deck, and shuffling.
     */
    void Deck::remix() {
        cards.insert(cards.end(), discardedCards.begin(), discardedCards.end());
        discardedCards.clear();
        shuffle();
    }

    /**
     * Returns the list of discarded Cards since the last remix.
     */
    vector<Card> Deck::getDiscardedCards() {
        return discardedCards;
    }

	/**
     * Prints the cards in the Deck.
     */
	string Deck::toString() {

		string retval = "";
		int numCards= cards.size();
        for (int i=0; i<numCards; i++) {
			cards[i].printCard();
            if (i<numCards-1) {
               cout<<",";
            }
        }
        return retval;
    }
