/*
PROGRAM: Assignment 2
Written by Steven Timothy
This program calculates how far you have to pull back an elastic to egg a teacher over old main.
Last Modified: 11/19/2016
*/
#include <iostream>
#include <cmath>																		//This is needed to use sin() function.

//Initializing some constants
//PI is self explanitory,
//M is the mass of the egg,
//K is the elastisity constant,
//and G is the force of gravity.
#define PI 3.14159265
const double M = 0.065;
const float K = 25;
const double G = 9.8;

//This is used to get the data needed for the problem.
void getData(float &d, float &theta)
{
	std::cout << "What is the distance to the professor (meters): ";
	std::cin >> d;

	std::cout << "What is the angle of elevation (Theta, in degrees): ";
	std::cin >> theta;
}

//This is used to change degrees into radians.
float getRadians(float theta)
{
	return (float)((theta * PI) / 180);
}

//This is used to calculate how far the elastic is needed to be pulled back in order to hit the professor with the egg.
float calcPullBack(float d, float radians)
{
	return (float)sqrt((M*G*d) / (K*sin(2 * radians)));
}

//This displays the results.
void dispResults(float x)
{
	std::cout << "You should pull back the elastic " << x << " meters." << std::endl;
}

int main()
{
	float d;												//This is the distance from the sling shot to the professor.
	float theta;											//This is the degree that we are going to shoot the egg at.
	float radians;											//This is the degree in radians for calculating the sin() function.
	float x;												//This is the distance that the elastic is pulled back.

	//Gather data.
	getData(d, theta);

	radians = getRadians(theta);

	//Calculate x
	x = calcPullBack(d, radians);

	//Display results
	dispResults(x);

	return 0;
}

/*
// Steven Timothy
// January 9 2014
// Assignment 2
#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.14159265

int main()
{
double D, Theta, radians, X, M=0.065, K=25, G=9.8;

cout << "Distance to professor (meters) : ";
cin >> D;

cout << "Angle of elevation (Theta, in degrees) : ";
cin >> Theta;

radians = Theta * PI / 180;

X = sqrt((M*G*D)/(K*sin(2*radians)));

cout << "You should pull back " << X << " meters"<<endl;
cin.get();
cin.get();
return 0;
}
*/