#include "StevenTimothy_UnoPlayer.h"
#include "Card.h"
#include "GameState.h"

StevenTimothy_UnoPlayer::StevenTimothy_UnoPlayer() {
}

int StevenTimothy_UnoPlayer::play(vector<Card> hand, Card upCard, Color calledColor, GameState state)
{
	//TODO: Write code to return a valid card from your hand

	vector<int> possiblePlays;
	vector<int> nonWildPlays;

	for (unsigned int i = 0; i < hand.size(); i++)
	{
		if (hand[i].canPlayOn(upCard, calledColor))
		{
			possiblePlays.push_back(i);
		}
	}
	vector<int> numberOfCards;
	for (int i = 0; i < 4; i++)
	{
		numberOfCards = state.getNumCardsInHandsOfUpcomingPlayers();
		if (numberOfCards[i] == 1)
		{
			for (unsigned int j = 0; j < hand.size(); j++)
			{
				if ((hand[j].getRank() == WILD) || (hand[j].getRank() == WILD_D4))
				{
					return j;
				}
			}
		}
	}
	if (possiblePlays.size() == 0)
	{
		return -1;
	}
	else if (possiblePlays.size() == 1)
	{
		return possiblePlays[0];
	}

	for (unsigned int i = 0; i < possiblePlays.size(); i++)
	{
		Card card = hand[possiblePlays[i]];
		if (card.getRank() != WILD && card.getRank() != WILD_D4)
		{
			nonWildPlays.push_back(possiblePlays[i]);
		}
	}
	if (nonWildPlays.size() == 0)
	{
		return possiblePlays[0];
	}
	int highValue = -1;
	int highIndex = 0;
	for (unsigned int i = 0; i < nonWildPlays.size(); i++)
	{
		Card card = hand[nonWildPlays[i]];
		if (card.getRank() != NUMBER)
		{
			return nonWildPlays[i];
		}
		if (card.getNumber() > highValue)
		{
			highValue = card.getNumber();
			highIndex = i;
		}
	}
	return nonWildPlays[highIndex];
}

Color StevenTimothy_UnoPlayer::callColor(vector<Card> hand) {
    //TODO: Write code to return a more strategic color, rather than always returning BLUE
	int numCardofColor[4] = { 0, 0, 0, 0 };
	
	for (unsigned int i = 0; i < hand.size(); i++)
	{
		if (hand[i].getColor() == RED)
		{
			numCardofColor[0]++;
		}
		if (hand[i].getColor() == YELLOW)
		{
			numCardofColor[1]++;
		}
		if (hand[i].getColor() == GREEN)
		{
			numCardofColor[2]++;
		}
		if (hand[i].getColor() == BLUE)
		{
			numCardofColor[3]++;
		}
	}
	int mostCardColor = 0;

	for (int i = 0; i < 4; i++)
	{
		if (numCardofColor[i] > numCardofColor[mostCardColor])
		{
			mostCardColor = i;
		}
	}

	switch (mostCardColor)
	{
	case 0: return RED;
	case 1: return YELLOW;
	case 2: return GREEN;
	case 3: return BLUE;
	default: return RED;
	}

}
