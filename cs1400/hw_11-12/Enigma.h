#ifndef ENIGMA_H
#define ENIGMA_H

#include <string>

class Enigma
{
private:
	//Private member variables.
	std::string innerRotor;
	std::string middleRotor;
	std::string outerRotor;
	int innerAlignment;
	int middleAlignment;
	int initialInnerAlignment;


public:
	//Constructors.
	Enigma();
	Enigma(std::string inner, std::string middle, char innerAlignChar, char middleAlignChar);

	//Public member functions.
	// This function encrypts the given character using the current Enigma machine settings
	char encode(char encodeChar);

	// This function decrypts the given character using the current Enigma machine settings      
	char decode(char decodeChar);
};

#endif