#include "Hand.h"
#include "Card.h"
//#include "UnoPlayer.h"
#include "Game.h"
    /**
     * Instantiate a Hand object to be played by the UnoPlayer class, and
     * the player name, passed as arguments. This implements a strategy
     * pattern whereby the constructor accepts various strategies that
     * implement the UnoPlayer interface.
     */
	Hand::Hand(UnoPlayer *unoPlayer, string setPlayerName) {
		player = unoPlayer;
		playerName = setPlayerName;
        cards.clear();
    }

    /**
     * Add (draw) a card to the hand.
     */
    void Hand::addCard(Card c) {
		cards.push_back(c);
    }

    /**
     * Return the number of cards in the hand.
     */
    int Hand::size() {
        return cards.size();
    }

    /**
     * It's your turn: play a card. When this method is called, the Hand
     * object choose a Card from the Hand based on the strategy that is
     * controlling it (<i>i.e.</i>, whose code was passed to the Hand
     * constructor.) If the player cannot legally play any of his/her
     * cards, null is returned.
     * @return The Card object to be played (which has been removed from
     * this Hand as a side effect), or null if no such Card can be played.
     */
    Card Hand::play(Game *game) {
        int playedCard;
        playedCard = player->play(cards, game->getUpCard(), game->calledColor,
            game->getGameState());
        if (playedCard == -1) {
			Card invalidCard=Card();
            return invalidCard;
        }
        else {
            Card toPlay = cards[playedCard];
			if (toPlay.getRank() == WILD ||
					toPlay.getRank() == WILD_D4 ||
					toPlay.getColor() == game->getUpCard().getColor() ||
					toPlay.getColor() == game->calledColor ||
					(toPlay.getRank() == game->getUpCard().getRank() &&
						toPlay.getRank() != NUMBER) ||
					(toPlay.getNumber() == game->getUpCard().getNumber() &&
						toPlay.getRank() == NUMBER &&
						game->getUpCard().getRank() == NUMBER))
				{
					cards.erase(cards.begin()+playedCard);
				}
			
            return toPlay;
        }
    }

    /**
     * Designed to be called in response to a wild card having been played
     * on the previous call to this object's play() method. This method
     * will choose one of the four colors based on the strategy controlling
     * it (<i>i.e.</i>, the class whose code was passed to the Hand
     * constructor.)
     * @return A Color value, <i>not</i> Color.NONE.
     */
    Color Hand::callColor(Game *game) {
        return player->callColor(cards);
    }

    /**
     * Return true only if this Hand has no cards, which should trigger a
     * winning condition.
     */
    bool Hand::isEmpty() {
        return cards.size() == 0;
    }

    /**
     * Prints this Hand. See Card::printCard() for
     * notes about how individual cards are rendered.
     */
    void Hand::printHand(bool override) {
        // Don't print the Hand to the screen if the PRINT_VERBOSE flag is false
		if (!PRINT_VERBOSE && !override)
			return;

		int numCards= cards.size();
        for (int i=0; i<numCards; i++) {
			cards[i].printCard(override);
            if (i<numCards-1) {
                cout<<",";
            }
        }
    }

    /**
     * Return the forfeit value of this Hand, as it now stands (in other
     * words, the sum of all the forfeit values of cards still possessed.)
     */
    int Hand::countCards() {
        int total = 0;
        int numCards= cards.size();
        for (int i=0; i<numCards; i++) {
            total += cards[i].forfeitCost();
        }
        return total;
    }

    /**
     * Return the name of the contestant.
     */
    string Hand::getPlayerName() {
        return playerName;
    }
