#include "Enigma.h"

#include <string>

/************************************************************************
*									Enigma								*
*	This is the default constructor for the enigma class. It sets the	*
*	roders and the alignment to default values.							*
************************************************************************/
Enigma::Enigma()
{
	innerRotor = "#GNUAHOVBIPWCJQXDKRYELSZFMT";
	middleRotor = "#EJOTYCHMRWAFKPUZDINSXBGLQV";
	outerRotor = "#BDFHJLNPRTVXZACEGIKMOQSUWY";

	innerAlignment = 0;
	middleAlignment = 0;
	initialInnerAlignment = 0;
}

/************************************************************************
*									Enigma								*
*	This is the overloaded constructor for the enigma class. It sets the*
*	roders and the alignment to user values except the exterior roter.	*
*	That is always the same.											*
************************************************************************/
Enigma::Enigma(std::string inner, std::string middle, char innerAlignChar, char middleAlignChar)
{
	//Define some variables.
	unsigned int pos;											//This is the temp position that allows us to know where the align chars are.

	//Set outer roter to default value.
	outerRotor = "#BDFHJLNPRTVXZACEGIKMOQSUWY";

	//Set middle and inner roters to user entered values.
	innerRotor = inner;
	middleRotor = middle;

	//find where the inner roter position is.
	for (pos = 0; pos < innerRotor.length(); pos++)
	{
		if (innerRotor[pos] == innerAlignChar)
		{
			break;
		}
	}
	
	//Set inner roter alignment to position found to contain the align char.
	innerAlignment = pos;

	initialInnerAlignment = innerAlignment;							//Dont remember what this is for yet.

	//Find middle allign position.
	for (pos = 0; pos < middleRotor.length(); pos++)
	{
		if (middleRotor[pos] == middleAlignChar)
		{
			break;
		}
	}
	middleAlignment = pos;
}

/************************************************************************
*									encode()							*
*	This is a function that encodes a message enigma style.				*
************************************************************************/
char Enigma::encode(char encodeChar)
{
	//Define some variables.
	unsigned int pos;										//This is a temperary variable that finds the position of the letter on the 
															//inner and middle roters.

	//Find the position of the letter in the inner roter.
	for (pos = 0; pos < innerRotor.length(); pos++)
	{
		if (innerRotor[pos] == encodeChar)
		{
			break;
		}
	}

	//This finds a character in the outer rotor that was in the same position as the inner rotor.
	//take the position and add a complete loop around so that the mod by the length will work.
	//Inner alignment starts at 0 but as the inner rotor rotates this will have a value.
	encodeChar = outerRotor[(pos + 27 - innerAlignment) % outerRotor.length()];

	//Find the new character on the middle rotor.
	for (pos = 0; pos < middleRotor.length(); pos++)
	{
		if (middleRotor[pos] == encodeChar)
		{
			break;
		}
	}

	//Now find that character on the outer rotor, same formula as before.
	encodeChar = outerRotor[(pos + 27 - middleAlignment) % outerRotor.length()];

	//Now rotate the inner alignment.
	if (innerAlignment)
	{
		innerAlignment--;
	}
	else
	{
		innerAlignment = 26;
	}

	//If we've made a completer rotation of the inner rotor, rotate the middle rotor once.
	if (innerAlignment == initialInnerAlignment)
	{
		if (middleAlignment)
		{
			middleAlignment--;
		}
		else
		{
			middleAlignment = 26;
		}
	}

	//Return the new character.
	return encodeChar;
}

/************************************************************************
*									decode()							*
*	This is a function that decodes a message enigma style.				*
************************************************************************/
char Enigma::decode(char decodeChar)
{
	//Define some variables.
	unsigned int pos;									//This is the position that the character was found at.

	//Find that character on the outer rotor.
	for (pos = 0; pos < outerRotor.length(); pos++)
	{
		if (outerRotor[pos] == decodeChar)
		{
			break;
		}
	}

	//change the character to be whatever was in the middle rotor at the time.
	decodeChar = middleRotor[(pos + middleAlignment) % 27];

	//Find that new character on the inner rotor.
	for (pos = 0; pos < outerRotor.length(); pos++)
	{
		if (outerRotor[pos] == decodeChar)
		{
			break;
		}
	}

	//Find that new character on the inner rotor.
	decodeChar = innerRotor[(pos + innerAlignment) % 27];

	//Rotate the inner rotor.
	if (innerAlignment)
	{
		innerAlignment--;
	}
	else
	{
		innerAlignment = 26;
	}

	//If there was a complete rotation of the inner then rotate the middle.
	if (innerAlignment == initialInnerAlignment)
	{
		if (middleAlignment)
		{
			middleAlignment--;
		}
		else
		{
			middleAlignment = 26;
		}
	}

	return decodeChar;
}