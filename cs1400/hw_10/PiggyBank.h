#ifndef PIGGY_BANK_H
#define PIGGY_BANK_H

#include <iostream>

class PiggyBank
{
private:
	//Private member variables.
	bool broken;
	double savings;

public:
	//Constructors.
	PiggyBank();
	PiggyBank(double s);
	~PiggyBank();

	//Public member functions.
	double countSavings() const;
	bool depositMoney(double money);
	double smash();
	bool getIfBroken() const;
};

#endif

/*# ifndef PIGGYBANK_H
# define PIGGYBANK_H

class PiggyBank
{
private:
	bool broken;
	double savings;

public:
	PiggyBank();
	PiggyBank(bool b, double s);
	~PiggyBank();
	double countSavings();
	void depositMoney(double money);
	double smash();

};

# endif*/