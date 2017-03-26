/*
PROGRAM: Assignment 11-12
Written by Steven Timothy
This program decodes and codes messages like the enigma machine.
Last Modified: 03/26/2017
*/
#include <iostream>
#include <string>

#include "Enigma.h"

/************************************************************************
*									MAIN								*
************************************************************************/
int main()
{
	//Define some variables.
	std::string message;								//This is the message that we are going to decode or code.
	Enigma defaultEnigma;								//This is the enigma class object that we will use to decode a message.

	message = "OKNNWRDHGERPILRLAMFZF#FMUCJIMGZR#CWCSDXQJMCJUSJLE#";

	// should decode to CONGRATULATIONS#YOU#GOT#IT#NOW#DONT#YOU#FEEL#PROUD
	for (unsigned int i = 0; i < message.length(); i++)
	{
		std::cout << defaultEnigma.decode(message[i]);
	}

	std::cout << std::endl;

	Enigma newEnigma("#EJOTYCHMRWAFKPUZDINSXBGLQV", "#GNUAHOVBIPWCJQXDKRYELSZFMT", 'E', 'G');

	message = "A#SIMPLE#ENIGMA#MODEL";

	// The encoded message should look like: WYJULPCBBGNNBUDFOEBEK
	for (unsigned int i = 0; i < message.length(); i++)
	{
		std::cout << newEnigma.encode(message[i]);
	}
	std::cout << std::endl;

	return 0;
}