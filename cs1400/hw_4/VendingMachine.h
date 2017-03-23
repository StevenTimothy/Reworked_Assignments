#ifndef VENDING_MACHINE_H
#define VENDING_MACHINE_H

#include "Gum.cpp"

//Define and initialize some constants.
const int NUM_GUM = 4;
const std::string GUM_NAMES[NUM_GUM] = { "Beemans", "Dentyne", "Chiclets", "Carefree" };
const int GUM_AMOUNT = 10;
const double QUARTER = .25;

//Declare typedefs.
typedef Gum GumArray[NUM_GUM];

class VendingMachine
{
private:
	//Private member variables.
	GumArray gumArray;
	double totalMoney;
	int totalInserted;

public:
	//Constructors.
	VendingMachine();

	//Public member functions.
	std::string printStatus() const;
	void depositMoney();
	int purchaseGum(int type);
	std::string getGumName(int type) const;
	void restock();
	double getTotalMoney() const;
	int getTotalInserted() const;
};

#endif