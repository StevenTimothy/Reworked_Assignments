#include "Card.h"
#include "UnoPlayer.h"
#include "Game.h"
#include "Hand.h"
// Uncomment if you are trying to print in color on a Windows machine
#include <windows.h>

/**
 * A Card in an Uno deck. Each Card knows its particular type, which is
 * comprised of a 3-tuple (color, rank, number). Not all of these values
 * are relevant for every particular type of card, however; for instance,
 * wild cards have no color (getColor() will return Color.NONE) or number
 * (getNumber() will return -1).
 * A Card knows its forfeit cost (i.e., how many points it counts
 * against a loser who gets stuck with it) and how it should act during
 * game play (whether it permits the player to change the color, what
 * effect it has on the game state, etc.)
 */
	/**
     * Constructor for non-number cards (skips, wilds, etc.)
     */
    Card::Card() {
        //Initialize to an invalid card
		color = NONE;
        rank = NUMBER;
        number = -1;
    }
	
    /**
     * Constructor for non-number cards (skips, wilds, etc.)
     */
    Card::Card(Color setColor, Rank setRank) {
        color = setColor;
        rank = setRank;
        number = -1;
    }

    /**
     * Constructor for number cards.
     */
    Card::Card(Color setColor, int setNumber) {
        color = setColor;
        rank = NUMBER;
        number = setNumber;
    }

    /**
     * Constructor to explicitly set entire card state.
     */
	Card::Card(Color setColor, Rank setRank, int setNumber) {
        color = setColor;
        rank = setRank;
        number = setNumber;
    }

    /**
     * Render this Card object as a string. Whether the string comes out
     * with ANSI color codes is controlled by the PRINT_IN_COLOR static
     * class variable.
     */
    void Card::printCard(bool override) {
        string retval = "";

		// Don't print the Card to the screen if the PRINT_VERBOSE flag is false
		if (!PRINT_VERBOSE && !override)
			return;
		
		//Uncomment if you are using a Windows Machine
		HANDLE  hConsole;
	
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		if (PRINT_IN_COLOR) {
			switch (color) {
				case RED:
                    SetConsoleTextAttribute(hConsole, 12);
                    break;
                case YELLOW:
                    SetConsoleTextAttribute(hConsole, 14);
                    break;
                case GREEN:
                    SetConsoleTextAttribute(hConsole, 10);
                    break;
                case BLUE:
                    SetConsoleTextAttribute(hConsole, 9);
                    break;
                case NONE:
                    SetConsoleTextAttribute(hConsole, 15);
                    break;
            }
		}

		// Uncomment if you are using a Mac or Linux machine
		// Note that this will not Print colors to the XCode console
        /*
		if (PRINT_IN_COLOR) {
            switch (color) {
				case RED:
                    retval += "\033[31m";
                    break;
                case YELLOW:
                    retval += "\033[33m";
                    break;
                case GREEN:
                    retval += "\033[32m";
                    break;
                case BLUE:
                    retval += "\033[34m";
                    break;
                case NONE:
                    retval += "\033[1m";
                    break;
            }
        }*/

		if (!PRINT_IN_COLOR) {
			switch (color) {
				case RED:
                    retval += "Red";
					break;
                case YELLOW:
                    retval += "Yellow";
					break;
                case GREEN:
                    retval += "Green";
					break;
                case BLUE:
                    retval += "Blue";
					break;
            }
        }

        switch (rank) {
            case NUMBER:
                switch (number)
				{
					case 0: retval+="0"; break;
					case 1: retval+="1"; break;
					case 2: retval+="2"; break;
					case 3: retval+="3"; break;
					case 4: retval+="4"; break;
					case 5: retval+="5"; break;
					case 6: retval+="6"; break;
					case 7: retval+="7"; break;
					case 8: retval+="8"; break;
					case 9: retval+="9"; break;
				}
                break;
            case SKIP:
                retval += "S";
                break;
            case REVERSE:
                retval += "R";
                break;
            case WILD:
                retval += "W";
                break;
            case DRAW_TWO:
                retval += "+2";
                break;
            case WILD_D4:
                retval += "W4";
                break;
        }

		// Uncomment if you are using a Mac or Linux machine
		// Note that this will not Print colors to the XCode console
        /*
        if (PRINT_IN_COLOR) {
            retval += "\033[37m\033[0m";
			cout<<retval;
        }*/
		
		//Uncomment if you are using a Windows Machine
		if (PRINT_IN_COLOR)
		{
			cout<<retval;
			SetConsoleTextAttribute(hConsole, 15);
		}
		
		if (!PRINT_IN_COLOR) {
			cout<<retval;
		}

    }

    /**
     * Returns the number of points this card will count against a player
     * who holds it in his/her hand when another player goes out.
     */
    int Card::forfeitCost() {
        if (rank == SKIP || rank == REVERSE ||
            rank == DRAW_TWO) {
            return 20;
        }
        if (rank == WILD || rank == WILD_D4) {
            return 50;
        }
        if (rank == NUMBER) {
            return number;
        }
        cout<<"Illegal card!!"<<endl;
        return -10000;
    }

    /**
     * Returns true only if this Card can legally be played on the up card
     * passed as an argument. The second argument is relevant only if the
     * up card is a wild.
     * @param c An "up card" upon which the current object might (or might
     * not) be a legal play.
     * @param calledColor If the up card is a wild card, this parameter
     * contains the color the player of that color called.
     */ 
    bool Card::canPlayOn(Card c, Color calledColor) {
        if (rank == WILD ||
            rank == WILD_D4 ||
            color == c.color ||
            color == calledColor ||
            (rank == c.rank && rank != NUMBER) ||
            number == c.number && rank == NUMBER && c.rank == NUMBER)
        {
            return true;
        }
        return false;
    }

    /**
     * Returns true only if playing this Card object would result in the
     * player being asked for a color to call. (In the standard game, this
     * is true only for wild cards.)
     */
    bool Card::followedByCall() {
        return rank == WILD || rank == WILD_D4;
    }

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
    void Card::performCardEffect(Game *game) { //throws EmptyDeckException {
        switch (rank) {
            case SKIP:
                game->advanceToNextPlayer();
                game->advanceToNextPlayer();
                break;
            case REVERSE:
                game->reverseDirection();
                game->advanceToNextPlayer();
                break;
            case DRAW_TWO:
                nextPlayerDraw(game);
                nextPlayerDraw(game);
                game->advanceToNextPlayer();
                game->advanceToNextPlayer();
                break;
            case WILD_D4:
                nextPlayerDraw(game);
                nextPlayerDraw(game);
                nextPlayerDraw(game);
                nextPlayerDraw(game);
                game->advanceToNextPlayer();
                game->advanceToNextPlayer();
                break;
            default:
                game->advanceToNextPlayer();
                break;
        }
    }

   void Card::nextPlayerDraw(Game *game) { //throws EmptyDeckException {
        int nextPlayer = game->getNextPlayer();
        Card drawnCard;
        try {
            drawnCard = game->deck.draw();
        }
        catch (int i) {
			if(i==EMPTY_DECK)
			{
				game->print("Deck exhausted! This game is a draw.\n");
			}
        }
        game->h[nextPlayer].addCard(drawnCard);
        game->print("  ");
		game->print(game->h[nextPlayer].getPlayerName());
		game->print(" draws ");
		drawnCard.printCard();
		game->println(".");
    }

    /**
     * Returns the color of this card, which is Color.NONE in the case of
     * wild cards.
     */
    Color Card::getColor() {
        return color;
    }

    /**
     * Returns the rank of this card, which is Rank.NUMBER in the case of
     * number cards (calling getNumber() will retrieve the specific
     * number.)
     */
	Rank Card::getRank() {
        return rank;
    }

    /**
     * Returns the number of this card, which is guaranteed to be -1 for
     * non-number cards (cards of non-Rank.NUMBER rank.)
     */
    int Card::getNumber() {
        return number;
    }
