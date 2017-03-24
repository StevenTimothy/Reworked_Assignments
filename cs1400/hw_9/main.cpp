/*
PROGRAM: Assignment 9
Written by Steven Timothy
This program un does a distortion on 3 images.
Last Modified: 03/23/2017
*/
#include <iostream>
#include <fstream>								//This is for reading and writing to a file.
#include <string>								//This is used for a string object.
#include <iomanip>								//This is for stream manipulation.

#include "Color.cpp"

//Declare prototypes.
void getFileNames(std::string &inputFileName, std::string &outputFileName);
void unDistort(const std::string inputFileName, const std::string outputFileName);
void correctBronze(Color &color);
void correctSilver(Color &color);
void correctGold(Color &color);

/************************************************************************
*								MAIN									*
************************************************************************/
int main()
{
	//Define some variables.
	std::string inputFileName;
	std::string outputFileName;

	getFileNames(inputFileName, outputFileName);
	
	unDistort(inputFileName, outputFileName);
	return 0;
}

/************************************************************************
*								getFileNames							*
*	This function gets the file names that we would like to decode and	*
*	send to.															*
************************************************************************/
void getFileNames(std::string &inputFileName, std::string &outputFileName)
{
	std::cout << "Portable Pixmap (PPM) Image Decoder!\n\n";

	std::cout << "Enter name of distorted image file: ";
	std::getline(std::cin, inputFileName);

	std::cout << "Enter name of corrected image file: ";
	std::getline(std::cin, outputFileName);
}

/************************************************************************
*								unDistort								*
*	This function gets asks the user which undistortion method they		*
*	would like to use.													*
************************************************************************/
void unDistort(const std::string inputFileName, const std::string outputFileName)
{
	//Define some variables.
	char input;													//This is the input from the user.
	std::string P3;												//Some constants.
	int width, height;											//Some constants.
	int max_color;												//Some constants.
	Color color;												//This holds the color of a pixel.
	int count = 0;												//Number of pixels in a row.

	do
	{
		std::cout << "Enter the distortion method(b = Bronze, s = Silver, g = Gold): ";
		std::cin >> input;
		
		if (toupper(input) != 'B' && toupper(input) != 'S' && toupper(input) != 'G')
		{
			std::cout << "Invalid input... Please enter b, s, or g.\n\n";
		}
	} while (toupper(input) != 'B' && toupper(input) != 'S' && toupper(input) != 'G');

	//Open files.
	std::ifstream fin(inputFileName);
	if (fin.fail())
	{
		std::cout << "Could not find the file...\n\n";
	}
	else
	{
		std::ofstream fout(outputFileName);

		fin >> P3;
		fin >> width >> height;
		fin >> max_color;

		fout << P3 << std::endl;
		fout << width << " " << height << std::endl;
		fout << max_color << std::endl;

		switch (input)
		{
		case 'b':
		case 'B':
			while (!fin.eof())
			{
				fin >> color.red;
				fin >> color.green;
				fin >> color.blue;

				correctBronze(color);

				fout << std::left << std::setw(4) << color.red << " " << std::setw(4) << color.green << " " << std::setw(6) << color.blue << " ";
				count++;

				if (count == width)
				{
					count = 0;
					fout << std::endl;
				}
			}
			break;
		case 's':
		case 'S':
			while (!fin.eof())
			{
				fin >> color.red;
				fin >> color.green;
				fin >> color.blue;

				correctSilver(color);

				fout << std::left << std::setw(4) << color.red << " " << std::setw(4) << color.green << " " << std::setw(6) << color.blue << " ";
				count++;

				if (count == width)
				{
					count = 0;
					fout << std::endl;
				}
			}
			break;
		case 'g':
		case 'G':
			while (!fin.eof())
			{
				fin >> color.red;
				fin >> color.green;
				fin >> color.blue;

				correctGold(color);

				fout << std::left << std::setw(4) << color.red << " " << std::setw(4) << color.green << " " << std::setw(6) << color.blue << " ";
				count++;

				if (count == width)
				{
					count = 0;
					fout << std::endl;
				}
			}
			break;
		default:
			std::cout << "Something went wrong...\n\n";
			break;
		}

		fout.close();
	}

	fin.close();
}

/************************************************************************
*								correctBronze							*
*	This function the three colors and does a bronze manipulation on	*
*	them to obtain the real image.										*
************************************************************************/
void correctBronze(Color &color)
{
	color.red *= 10;
	color.green = 0;
	color.blue = 0;
}

/************************************************************************
*								correctSilver							*
*	This function the three colors and does a silver manipulation on	*
*	them to obtain the real image.										*
************************************************************************/
void correctSilver(Color &color)
{
	color.red  = 0;
	color.green *= 20;
	color.blue *= 20;
}

/************************************************************************
*								correctGold								*
*	This function the three colors and does a gold manipulation on		*
*	them to obtain the real image.										*
************************************************************************/
void correctGold(Color &color)
{
	color.blue = color.red % 1000;
	color.red /= 1000;
	color.green = color.red % 1000;
	color.red /= 1000;
}

/*
//Steven Timothy
//03/01/2014
# include <iostream>
# include <string>
# include <fstream>

using namespace std;

void correctBronze(int &R, int &G, int &B)
{
	G = 0;
	B = 0;
	R *= 10;
}

void correctSilver(int &R, int &G, int &B)
{
	R = 0;
	B *= 20;
	G *= 20;
}

void correctGold(int &R, int &G, int &B)
{
	B = 0;
	G = 0;
	B = R % 1000;
	R /= 1000;
	G = R % 1000;
	R /= 1000;
}

int main()
{
	ofstream outputFile;
	ifstream inputFile;
	string fileDestorted;
	string fileCorrected;
	string magic;
	string input;
	string output;
	char distMethod;
	int row = 0;
	int col = 0;
	int maxValue = 0;
	int R = 0;
	int G = 0;
	int B = 0;

	cout << "Portable Pixmap (PPM) Image Decoder!\n\n";
	cout << "Enter name of distorted image file: ";
	getline(cin, input);
	cout << "Enter name of corrected image file: ";
	getline(cin, output);
	cout << "Enter the distortion method(b = Bronze, s = Silver, g = Gold): ";
	cin >> distMethod;

	inputFile.open(input);
	outputFile.open(output);

	if (distMethod == 'b')
	{
		inputFile >> magic;
		inputFile >> row;
		inputFile >> col;
		inputFile >> maxValue;

		outputFile << magic << endl;
		outputFile << row << " " << col << endl;
		outputFile << maxValue << endl;

		for (int i = 0; i < row * col; i++)
		{
			inputFile >> R;
			inputFile >> G;
			inputFile >> B;

			correctBronze(R, G, B);

			outputFile << R << " ";
			outputFile << G << " ";
			outputFile << B << " ";

		}
	}
	else if (distMethod == 's')
	{
		inputFile >> magic;
		inputFile >> row;
		inputFile >> col;
		inputFile >> maxValue;

		outputFile << magic << endl;
		outputFile << row << " " << col << endl;
		outputFile << maxValue << endl;

		for (int i = 0; i < row * col; i++)
		{
			inputFile >> R;
			inputFile >> G;
			inputFile >> B;

			correctSilver(R, G, B);

			outputFile << R << " ";
			outputFile << G << " ";
			outputFile << B << " ";

		}
	}
	else if (distMethod == 'g')
	{
		inputFile >> magic;
		inputFile >> row;
		inputFile >> col;
		inputFile >> maxValue;

		outputFile << magic << endl;
		outputFile << row << " " << col << endl;
		outputFile << maxValue << endl;

		for (int i = 0; i < row * col; i++)
		{
			inputFile >> R;
			inputFile >> G;
			inputFile >> B;

			correctGold(R, G, B);

			outputFile << R << " ";
			outputFile << G << " ";
			outputFile << B << " ";

		}
	}
	else
	{
		cout << "No such type of distortion method exists!\n";
	}

	inputFile.close();
	outputFile.close();

	system("pause");
	return 0;
}*/