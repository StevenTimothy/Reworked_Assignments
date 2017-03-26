#include "DumbPlayer.h"
#include "Card.h"
#include "GameState.h"

DumbPlayer::DumbPlayer() {
}

bool DumbPlayer::canPlayOn(Card card, Card upCard, Color calledColor) {

    if (card.getRank() == WILD ||
        card.getRank() == WILD_D4 ||
        card.getColor() == upCard.getColor() ||
        card.getColor() == calledColor ||
        (card.getRank() == upCard.getRank() &&
            card.getRank() != NUMBER) ||
        card.getNumber() == upCard.getNumber() &&
            card.getRank() == NUMBER &&
            upCard.getRank() == NUMBER) {
        return true;
    }
    return false;
}


int DumbPlayer::play(vector<Card> hand, Card upCard, Color calledColor, GameState state) {

    int handSize=hand.size();
	
	// returns the first valid card that can be played
    for (int i=0; i<handSize; i++) {
        if (canPlayOn(hand[i], upCard, calledColor)) {
            return i;
        }
    }
    return -1;
}

Color DumbPlayer::callColor(vector<Card> hand) {
    // always returns RED as the call color
	return RED;
}
