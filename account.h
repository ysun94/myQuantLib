#pragma once
#include <iostream>

class Account
{
protected:
	double balance;
public:
	Account();
	Account(double bal);
	void deposit(double amt);
	double get_balance() const;
};

std::ostream& operator<<(std::ostream& out, Account& sa);