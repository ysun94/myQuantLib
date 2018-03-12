#include "stdafx.h"
#include "account.h"
#include "SavingAccount.h"

Account::Account()
{
	balance = 0.0;
}

Account::Account(double bal)
{
	balance = bal;
}

void Account::deposit(double amt)
{
	balance += amt;
}

double Account::get_balance() const
{
	return this->balance;
}

std::ostream& operator<<(std::ostream& out, Account& sa)
{
	out << "The current balance is " << sa.get_balance() << '\n';
	return out;
}

SavingAccount::SavingAccount()
{
	Account();  // NOLINT
	rate = 0.0;
}

SavingAccount::SavingAccount(double bal, double rate):Account(bal)
{
		this->rate = rate;
}

double SavingAccount::compound()
{
	double const interest = balance * rate;
	balance += interest;
	return interest;
}

std::ostream& operator<<(std::ostream& out, SavingAccount& sa)
{
	out << "The current balance is " << sa.get_balance() << '\n'
		<< "The compound is " << sa.compound() << '\n';
	return out;
}






