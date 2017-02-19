/*
	PROGRAM: Assignment 3
	Written by Steven Timothy
	This program helps you decide if you should squash a bug or not.
	Last Modified: 11/19/2016
*/
#include <iostream>

void run()
{
	char input;
	int legs = 0;
	bool done = false;

	//Is it freaking you out?
	std::cout << "Should you squish this bug?...well\n\n";
	std::cout << "Is it freaking you out? (y or n): ";

	//Is it freaking you out?... Response
	while (!done)
	{
		std::cin >> input;

		if (input == 'y' || input == 'n')
		{
			done = true;
		}
		else
		{
			std::cout << "Please enter a valid input... ";
		}
	}

	done = false;

	//Is it freaking you out?...Yes
	if (input == 'y')
	{
		//Does it bite or suck blood?
		std::cout << "Does it bite or suck blood? (y or n): ";

		//Does it bite or suck blood?...Response
		while (!done)
		{
			std::cin >> input;

			if (input == 'y' || input == 'n')
			{
				done = true;
			}
			else
			{
				std::cout << "Please enter a valid input... ";
			}
		}

		done = false;

		//Does it bite or suck blood?...Yes
		if (input == 'y')
		{
			//Will it make an unfortunate noise or mess if squished?
			std::cout << "Will it make an unfortunate noise or mess if squished? (y or n): ";

			//Will it make an unfortunate noise or mess if squished?...Response
			while (!done)
			{
				std::cin >> input;

				if (input == 'y' || input == 'n')
				{
					done = true;
				}
				else
				{
					std::cout << "Please enter a valid input... ";
				}
			}

			done = false;

			//Will it make an unfortunate noise or mess if squished?...Yes
			if (input == 'y')
			{
				std::cout << "Put it in a cup or flush it down the toilet.\n\n";
			}
			//Will it make an unfortunate noise or mess if squished?...No
			else if (input == 'n')
			{
				//Will you feel bad if you squish it?
				std::cout << "Will you feel bad if you squish it? (y or n): ";

				//Will you feel bad if you squish it?...Response
				while (!done)
				{
					std::cin >> input;

					if (input == 'y' || input == 'n')
					{
						done = true;
					}
					else
					{
						std::cout << "Please enter a valid input... ";
					}
				}

				done = false;
				
				//Will you feel bad if you squish it?...Yes
				if (input == 'y')
				{
					std::cout << "Put it in a cup or flush it down the toilet.\n\n";
				}
				//Will you feel bad if you squish it?...No
				else if (input == 'n')
				{
					std::cout << "Squish!!!\n\n";
				}
				//Will you feel bad if you squish it?...Error
				else
				{
					std::cout << "Error!!!\n\n";
				}
			}
			//Will it make an unfortunate noise or mess if squished?...Error
			else
			{
				std::cout << "Error!!!\n\n";
			}
		}
		//Does it bite or suck blood?...No
		else if (input == 'n')
		{
			//How many legs?
			std::cout << "How many legs?: ";

			//How many legs?...Response
			while (!done)
			{
				std::cin >> legs;

				if (legs >= 0)
				{
					done = true;
				}
				else
				{
					std::cout << "Please enter a valid input... ";
				}
			}

			done = false;

			//How many legs?...0
			if (legs == 0)
			{
				std::cout << "Leave the poor thing alone.\n\n";
			}
			//How many legs?...1-7
			else if (0 < legs && legs < 8)
			{
				//Does it hiss?
				std::cout << "Does it hiss? (y or n): ";

				//Does it hiss?...Response
				while (!done)
				{
					std::cin >> input;

					if (input == 'y' || input == 'n')
					{
						done = true;
					}
					else
					{
						std::cout << "Please enter a valid input... ";
					}
				}

				done = false;

				//Does it hiss?...Y
				if (input == 'y')
				{
					std::cout << "Squish.\n\n";
				}
				//Does it hiss?...N
				else if (input == 'n')
				{
					//Is it a ladybug or a praying mantis?
					std::cout << "Is it a ladybug or a praying mantis? (y or n): ";

					//Is it a ladybug or a praying mantis?...Response
					while (!done)
					{
						std::cin >> input;

						if (input == 'y' || input == 'n')
						{
							done = true;
						}
						else
						{
							std::cout << "Please enter a valid input... ";
						}
					}

					done = false;

					//Is it a ladybug or a praying mantis?...Y
					if (input == 'y')
					{
						std::cout << "Put it in a cup and take it outside.\n\n";
					}
					//Is it a ladybug or a praying mantis?...N
					else if (input == 'n')
					{
						//Do you believe in reincarnation?
						std::cout << "Do you believe in reincarnation? (y or n): ";

						//Do you believe in reincarnation?...Response
						while (!done)
						{
							std::cin >> input;

							if (input == 'y' || input == 'n')
							{
								done = true;
							}
							else
							{
								std::cout << "Please enter a valid input... ";
							}
						}

						done = false;

						//Do you believe in reincarnation?...Y
						if (input == 'y')
						{
							std::cout << "Put it in a cup and take it outside.\n\n";
						}
						//Do you believe in reincarnation?...N
						else if (input == 'n')
						{
							std::cout << "Squish.\n\n";
						}
						//Do you believe in reincarnation?...Error
						else
						{
							std::cout << "Error!!!\n\n";
						}
					}
					//Is it a ladybug or a praying mantis?...Error
					else
					{
						std::cout << "Error!!!\n\n";
					}
				}
				//Does it hiss?...Error
				else
				{
					std::cout << "Error!!!\n\n";
				}
			}
			//How many legs?...8+
			else if (legs >= 8)
			{
				//Is it a caterpillar?
				std::cout << "Is it a caterpillar? (y or n): ";

				//Is it a caterpillar?...Response
				while (!done)
				{
					std::cin >> input;

					if (input == 'y' || input == 'n')
					{
						done = true;
					}
					else
					{
						std::cout << "Please enter a valid input... ";
					}
				}

				done = false;

				//Is it a caterpillar?...Y
				if (input == 'y')
				{
					std::cout << "Make a nice home for it in a shoebox.\n\n";
				}
				//Is it a caterpillar?...N
				else if (input == 'n')
				{
					//Has is spelled out words in a web?
					std::cout << "Has is spelled out words in a web? (y or n): ";

					//Has is spelled out words in a web?...Response
					while (!done)
					{
						std::cin >> input;

						if (input == 'y' || input == 'n')
						{
							done = true;
						}
						else
						{
							std::cout << "Please enter a valid input... ";
						}
					}

					done = false;

					//Has is spelled out words in a web?...Y
					if (input == 'y')
					{
						std::cout << "Some bug!\n\n";
					}
					//Has is spelled out words in a web?...N
					else if (input == 'n')
					{
						std::cout << "Squish.\n\n";
					}
					//Has is spelled out words in a web?...Error
					else
					{
						std::cout << "Error!!!\n\n";
					}
				}
				//Is it a caterpillar?...Error
				else
				{
					std::cout << "Error!!!\n\n";
				}
			}
			//How many legs?...Error
			else
			{
				std::cout << "Error!!!\n\n";
			}
		}
		//Does it bite or suck blood?...Error
		else
		{
			std::cout << "Error!!!\n\n";
		}
	}
	//Is it freaking you out?...No
	else if (input == 'n')
	{
		//Why not?
		std::cout << "Why not? (a: \"I\'m nine\" or b: \"I\'m an entomologist\"): ";

		//Why not?...Response
		while (!done)
		{
			std::cin >> input;

			if (input == 'a' || input == 'b')
			{
				done = true;
			}
			else
			{
				std::cout << "Please enter a valid input... ";
			}
		}

		done = false;

		//Why not?...I'm nine
		if (input == 'a')
		{
			std::cout << "Put it in a cup and freak someone out with it.\n\n";
		}
		//Why not?...I'm an entomologist
		else if (input == 'b')
		{
			std::cout << "Cool. Don't look over there. <-\n\n";
		}
		//Why not?..Error
		else
		{
			std::cout << "Error!!!\n\n";
		}
	}
	//Is it freaking you out?...Error
	else
	{
		std::cout << "Error!!!\n\n";
	}
}

int main()
{
	run();

	return 0;
}







/*
//Steven Timothy
//Section number:1400-002
//01/16/2014
#include <iostream>
using namespace std;
int main()
{
char input;
int numLegs;
cout << "Should I squish this bug?...\n\n";
cout << "Is it freaking you out? (y/n)\n";
cin >> input;
if (input == 'y')
{
cout << "Does it bite or suck blood? (y/n)\n";
cin >> input;
if (input == 'n')
{
cout << "How many Legs?\n";
cin >> numLegs;
if (numLegs == 0)
{
cout << "Leave the poor thing alone.\n";
}
else if (numLegs >=1 && numLegs <=7)
{
cout << "Does it hiss? (y/n)\n";
cin >> input;
if (input == 'n')
{
cout << "Is it a ladybug or a praying mantis? (y/n)\n";
cin >> input;
if (input == 'y')
{
cout << "Put it in a cup and take it outside.\n";
}
else if (input == 'n')
{
cout << "Do you believe in reincarnation? (y/n)\n";
cin >> input;
if (input == 'y')
{
cout << "Put it in a cup and take it outside.\n";
}
else if (input == 'n')
{
cout << "Squish.\n";
}
}
}
else if (input == 'y')
{
cout << "Squish.\n";
}
}
else if (numLegs >= 8)
{
cout << "Is it a caterpillar? (y/n)\n";
cin >> input;
if (input == 'y')
{
cout << "Make a nice home for it in a shoebox.\n";
}
else if (input == 'n')
{
cout << "Has it spelled out words in a web? (y/n)\n";
cin >> input;
if (input == 'y')
{
cout << "Some bug!\n";
}
else if (input == 'n')
{
cout << "Squish.\n";
}
}
}
}
else if (input == 'y')
{
cout << "Will it make an unfortunate noise or mess if squished? (y/n)\n";
cin >> input;
if (input == 'y')
{
cout << "Put it in a cup or flush it down the toilet.\n";
}
else if (input == 'n')
{
cout << "Will you feel bad if you squish it? (y/n)\n";
cin >> input;
if (input == 'y')
{
cout << "Put it in a cup or flush it down the toilet.\n";
}
else if (input == 'n')
{
cout << "Squish.\n";
}
}
}
}
else if (input == 'n')
{
cout << "Why not?\na: I'm nine.\nb: I'm an entomologist.\n";
cin >> input;
if (input == 'a')
{
cout << "Put it in a cup and freak someone out with it.\n";
}
else if (input == 'b')
{
cout << "Cool. Don't look over there. <--\n";
}
}

return 0;
}
*/