#ifndef DUMBPLAYER_H
#define DUMBPLAYER_H
#include "UnoPlayer.h"

class DumbPlayer: public UnoPlayer { 

public:
	DumbPlayer();   // default constructor

	bool canPlayOn(Card card, Card upCard, Color calledColor);

	int play(vector<Card> hand, Card upCard, Color calledColor, GameState state);

    Color callColor(vector<Card> hand);
};
#endif
