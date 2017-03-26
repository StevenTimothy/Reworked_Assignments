#include "UnoPlayer.h"
#include "Card.h"
#include "GameState.h"

UnoPlayer::UnoPlayer() {
}

int UnoPlayer::play(vector<Card> hand, Card upCard, Color calledColor, GameState state) {

    return -1;
}

Color UnoPlayer::callColor(vector<Card> hand) {
    return RED;
}
