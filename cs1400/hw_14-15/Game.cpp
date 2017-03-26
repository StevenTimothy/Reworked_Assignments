#include "Game.h"
#include "Hand.h"
#include "UnoPlayer.h"

    /**
     * Main constructor to instantiate a Game of Uno. Provided must be two
     * objects indicating the player roster: a Scoreboard, and a class
     * list. This constructor will deal hands to all players, select a
     * non-action up card, and reset all game settings so that play() can
     * be safely called.
     * @param scoreboard A fully-populated Scoreboard object that contains
     * the names of the contestants, in order.
     * @param playerClassList[] An array of Strings, each of which is a
     * fully-qualified package/class name of a class that implements the
     * UnoPlayer interface.
     */
    Game::Game(Scoreboard *setScoreboard, vector<UnoPlayer *> playerClassList) {
        scoreboard = setScoreboard;
        deck = Deck();
		currPlayer = rand() % scoreboard->getNumPlayers();
		try {
			
            for (int i=0; i<scoreboard->getNumPlayers(); i++) {
                h.push_back(Hand(playerClassList[i],
                    scoreboard->getPlayerList()[i]));
				mostRecentColorCalled.push_back(NONE);
                
            }

			// Alternate which player gets their cards first
			for (int i=0; i<scoreboard->getNumPlayers(); i++) {
                for (int j=0; j<INIT_HAND_SIZE; j++) {
                    h[(i+currPlayer)%scoreboard->getNumPlayers()].addCard(deck.draw());
                }
			}
            upCard = deck.draw();
            while (upCard.followedByCall()) {
                deck.discard(upCard);
                upCard = deck.draw();
            }
		}
        catch (int i) {
			if(i==EMPTY_DECK)
			{
				print("Can't deal initial hands!n");
			}
        }

        direction = FORWARDS;
        calledColor = NONE;
    }

   void Game::printState() {
	    // Don't print the State to the screen if the PRINT_VERBOSE flag is false
		if (!PRINT_VERBOSE)
			return;

        for (int i=0; i<scoreboard->getNumPlayers(); i++) {
			cout<<"Hand #"<< i <<": ";
			h[i].printHand();
			cout<<endl;
        }
    }

    /**
     * Return the number of the <i>next</i> player to play, provided the
     * current player doesn't jack that up by playing an action card.
     * @return An integer from 0 to scoreboard.getNumPlayers()-1.
     */
    int Game::getNextPlayer() {
        if (direction == FORWARDS) {
            return (currPlayer + 1) % scoreboard->getNumPlayers();
        }
        else {
            if (currPlayer == 0) {
                return scoreboard->getNumPlayers() - 1;
            }
            else {
                return currPlayer - 1;
            }
        }
    }

    /**
     * Go ahead and advance to the next player.
     */
    void Game::advanceToNextPlayer() {
        currPlayer = getNextPlayer();
    }

    /**
     * Change the direction of the game from clockwise to counterclockwise
     * (or vice versa.)
     */
    void Game::reverseDirection() {
        if (direction == FORWARDS) {
            direction = BACKWARDS;
        }
        else {
            direction = FORWARDS;
        }
    }

    /**
     * Play an entire Game of Uno from start to finish. Hands should have
     * already been dealt before this method is called, and a valid up card
     * turned up. When the method is completed, the Game's scoreboard object
     * will have been updated with new scoring favoring the winner.
     */
    void Game::play() {
		print("Initial upcard is ");
		upCard.printCard();
		println(".");

        try {
            while (true) {
                print(h[currPlayer].getPlayerName() + " (");
				h[currPlayer].printHand();
				print(")");
                Card playedCard = h[currPlayer].play(this);
				if ((playedCard.getColor() == NONE) && (playedCard.getRank() == NUMBER) &&
					(playedCard.getNumber() == -1)) {
                    Card drawnCard=Card();
                    try {
                        drawnCard = deck.draw();
                    }
                    catch (int i) {
						if(i==EMPTY_DECK)
						{
							print("...deck exhausted, remixing...");
							deck.remix();
							drawnCard = deck.draw();
						}
                    }
                    h[currPlayer].addCard(drawnCard);
					print(" has to draw (");
					drawnCard.printCard();
					print(").");
                    playedCard = h[currPlayer].play(this);
                }
				// Test to make sure the playedCard is valid
				if (!(playedCard.getRank() == WILD ||
					playedCard.getRank() == WILD_D4 ||
					playedCard.getColor() == upCard.getColor() ||
					playedCard.getColor() == calledColor ||
					(playedCard.getRank() == upCard.getRank() &&
						playedCard.getRank() != NUMBER) ||
					(playedCard.getNumber() == upCard.getNumber() &&
						playedCard.getRank() == NUMBER &&
						upCard.getRank() == NUMBER)))
				{
					cout<<"\n\nWhoops -- "<<h[currPlayer].getPlayerName()<<"\'s play() method has an error!\n";
					cout<<"You were given this hand: (";

					h[currPlayer].printHand(true);
					cout<<")\nand the up card was: ";
					upCard.printCard(true);
					if (upCard.getRank() == WILD ||
						upCard.getRank() == WILD_D4) {
						string color;
						switch (calledColor)
						{
							case RED: color="Red"; break;
							case GREEN: color="Green"; break;
							case BLUE: color="Blue"; break;
							case YELLOW: color="Yellow"; break;
							default: color="None";
						}

						cout<<"\nand the called color was: "<<color<<endl;
					}
					cout<<"\nand you (wrongly) returned ";
					playedCard.printCard(true);
					cout<<".\n";
					return;
				}
				if (!((playedCard.getColor() == NONE) && (playedCard.getRank() == NUMBER) &&
					(playedCard.getNumber() == -1))) {
					print(" plays ");
					playedCard.printCard();
					print(" on ");
					upCard.printCard();
					print(".");

                    deck.discard(upCard);
                    upCard = playedCard;
                    if (upCard.followedByCall()) {
                        calledColor = h[currPlayer].callColor(this);
                        mostRecentColorCalled[currPlayer] = calledColor;
						string color;
						switch (calledColor)
						{
							case RED: color="Red"; break;
							case GREEN: color="Green"; break;
							case BLUE: color="Blue"; break;
							case YELLOW: color="Yellow"; break;
							default: color="None";
						}

                        print(" (and calls " + color +
                            ").");
                    }
                    else {
                        calledColor = NONE;
                    }
                }
                if (h[currPlayer].isEmpty()) {
                    int roundPoints = 0;
                    for (int j=0; j<scoreboard->getNumPlayers(); j++) {
                        roundPoints += h[j].countCards();
                    }
					if (PRINT_VERBOSE) {
						cout<<"\n"<<h[currPlayer].getPlayerName()<<" wins! (and collects ";
						cout<<roundPoints<<" points.)\n";
					}
                    scoreboard->addToScore(currPlayer,roundPoints);
					if (PRINT_VERBOSE) {
						println("---------------\n" );
						scoreboard->printScoreboard();
					}
                    return;
                }
                if (h[currPlayer].size() == 1) {
                    print(" UNO!");
                }
                println("");
                if (!((playedCard.getNumber()==-1) && (playedCard.getColor()==NONE)) || (playedCard.getRank()==WILD_D4)) {
                    playedCard.performCardEffect(this);
                }
                else {
                    advanceToNextPlayer();
                }
            }
        }
        catch (int i) {
			if(i==EMPTY_DECK)
			{
				print("Deck exhausted! This game is a draw.\n");
			}
        }
    }

    void Game::print(string s) {
        if (PRINT_VERBOSE) {
            cout<<s;
        }
    }

    void Game::println(string s) {
        if (PRINT_VERBOSE) {
            cout<<s<<endl;
        }
    }

    /**
     * Return the GameState object, through which the state of the game can
     * be accessed and safely manipulated.
     */
    GameState Game::getGameState() {

        return GameState(this);
    }

    /**
     * Return the Card that is currently the "up card" in the game.
     */
    Card Game::getUpCard() {
        return upCard;
    }
