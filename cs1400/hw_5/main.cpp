/*
PROGRAM: Assignment 5
Written by Steven Timothy
This program decodes a message for rot13.
Last Modified: 03/23/2017
*/
#include <iostream>
#include <fstream>								//This is for file reading and writing.
#include <string>								//This is for string objects.

//Define and initialize some constants.
const std::string INPUT_FILE = "secretMessage.txt";
const std::string OUTPUT_FILE = "decodedMessage.txt";

//Declare prototypes.
std::string decodeMessage();
void sendToFile(std::string message);

/************************************************************************
*									MAIN								*
************************************************************************/
int main()
{
	//Define some variables.
	std::string message;									//This is going to hold the decoded message.

	message = decodeMessage();

	sendToFile(message);

	return 0;
}

/************************************************************************
*								decodeMessage							*
*	This function pulls characters from a coded message file and		*
*	decodes it, it returns a final decoded message in the end.			*
************************************************************************/
std::string decodeMessage()
{
	//Define and initialize some variables.
	std::string message = "";									//This is going to hold the decoded message.
	char c;														//This holds a single letter from the text file.

	std::ifstream fin(INPUT_FILE);
	//Check to see if it could open the file.
	if (fin.fail())
	{
		std::cout << "Failed to open the secret message file.\n\n";
	}
	else
	{
		while (!fin.eof())
		{
			//Get the next character.
			fin.get(c);

			if ((c >= 'N') && (c <= 'Z'))
			{
				c -= 13;
			}
			else if ((c >= 'A') && (c <= 'M'))
			{
				c += 13;
			}
			else if ((c >= 'n') && (c <= 'z'))
			{
				c -= 13;
			}
			else if ((c >= 'a') && (c <= 'm'))
			{
				c += 13;
			}
			message += c;
		}
	}

	fin.close();

	return message;
}

/************************************************************************
*								sendToFile								*
*	This function takes a message and prints it to a file.				*
************************************************************************/
void sendToFile(std::string message)
{
	//Open the file.
	std::ofstream fout(OUTPUT_FILE);

	fout << message;

	fout.close();
}

/*
//Steven Timothy 
//01/01/2014
#include <iostream> 
#include <string> 
#include <fstream>
using namespace std;
int main() 
{
	ifstream inputFile; 
	ofstream outputFile;
	char ch;
	inputFile.open("secretMessage.txt"); 
	outputFile.open("decodedMessage.txt");
	ch = inputFile.get();
	while (!inputFile.eof()) 
	{
		if ((ch >= 'N') && (ch <= 'Z')) 
		{
			ch -= 13;
		}
		else if ((ch >= 'A') && (ch <= 'M')) 
		{
			ch += 13;
		}
		else if ((ch >= 'n') && (ch <= 'z')) 
		{
			ch -= 13;
		}
		else if ((ch >= 'a') && (ch <= 'm')) 
		{
			ch += 13;
		} 
		outputFile << ch;
		ch = inputFile.get();
	}
	inputFile.close(); 
	outputFile.close();
	system("pause"); 
	return 0;
}
*/