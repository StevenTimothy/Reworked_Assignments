#ifndef CONSTANTS_H  
#define CONSTANTS_H

	enum Color { RED, YELLOW, GREEN, BLUE, NONE };
    enum Rank { NUMBER, SKIP, REVERSE, DRAW_TWO, WILD, WILD_D4 };
	
	// An error message
	const int EMPTY_DECK = 10;

	// If PRINT_VERBOSE is true the game will output a play by play
	const bool PRINT_VERBOSE = true;

    /**
     * For terminals that support it, setting PRINT_IN_COLOR to true will
     * enable printing in color.
     */
    static const bool PRINT_IN_COLOR = true;

#endif
