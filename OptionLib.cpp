#include "stdafx.h"
#include <iostream>
#include "BinomialModel.h"
#include  "Option.h"
#include <vector>

// define a binomial model to simulate the evolution of the share price
// the fundamental parameters are initial price, increasing rate, decreasing rate and the risk free rate
BinomialModel::BinomialModel()
{
	S0 = 0.0;
}


BinomialModel::BinomialModel(double S0, double U, double D, double R)
{
	this->S0 = S0;
	this->U = U;
	this->D = D;
	this->R = R;
}

inline double BinomialModel::get_RiskNeuProb() const
{
	return (R - D) / (U - D);
}

inline double BinomialModel::S(int n, int i) const
{
	return S0 * pow(1 + U, i) * pow(1 + D, n - i);
}

inline double BinomialModel::getR() const
{
	return R;
}

inline double BinomialModel::getStock() const
{
	return S0;
}

inline double BinomialModel::getU() const
{
	return U;
}

inline double BinomialModel::getD() const
{
	return D;
}

inline void BinomialModel::setR(double R)
{
	this->R = R;
}

inline void BinomialModel::setStock(double S)
{
	this->S0 = S;
}

inline void BinomialModel::setU(double U)
{
	this->U = U;
}

inline void BinomialModel::setD(double D)
{
	this->D = D;
}

inline void BinomialModel::CheckData() const
{
	// check if the parameters are valid
	if (S0 < 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <=-1.0)
	{
		std::cout << "Illegal data ranges.\n";
		std::cout << "Terminating the program.\n";
		exit(1);
	}
	// check if arbitrage oppotunity exists
	if (R >= U || R <= D)
	{
		std::cout << "Arbitrage exits.\n";
		std::cout << "Terminating the program.\n";
		exit(1);
	}
}

//
void Option::setN(int N)
{
	this->N = N;
}

int Option::getN() const
{
	return N;
}

// if there is no base class of EurOption:
// here are the function definitions of European option
//void EurOption::setN(int N)
//{
//	this->N = N;
//}
//
//int EurOption::getN() const
//{
//	return N;
//}

double EurOption::PriceByCRR(const BinomialModel& model) const
{
	int N = this->getN();
	double q = model.get_RiskNeuProb(); // get the risk-neutral rate
	std::vector<double> Payoffs(N + 1);
	for(int i = 0; i < N+1; i++)
	{
		Payoffs[i] = Payoff(model.S(N, i));
	}
	for(int n = N-1; n >= 0; n--)
	{
		for(int i = 0; i < n+1; i++)
		{
			Payoffs[i] = (q*Payoffs[i+1] + (1 - q)*Payoffs[i]) / (1 + model.getR());
		}
	}
	return Payoffs[0];
}

//void AmOption::setN(int N)
//{
//	this->N = N;
//}
//
//int AmOption::getN() const
//{
//	return N;
//}

double AmOption::PriceBySnell(const BinomialModel& model) const
{
	int N = this->getN();
	double q = model.get_RiskNeuProb();
	std::vector<double> Payoffs(N + 1);
	for(int i = 0; i < N+1; i++)
	{
		Payoffs[i] = Payoff(model.S(N, i));
	}
	for (int n = N-1; n >= 0; n--)
	{
		for (int i = 0; i <= n; i++)
		{
			double temp = (q*Payoffs[i + 1] + (1 - q)*Payoffs[i]) / (1 + model.getR());
			Payoffs[i] = (temp > Payoff(model.S(n, i))) ? temp : Payoff(model.S(n, i));
		}
	}
	return Payoffs[0];
}

double Call::getK() const
{
	return K;
}

void Call::setK(double K)
{
	this->K = K;
}

double Call::Payoff(double S) const
{
	return (S > K) ? (S - K) : 0.0;
}

double Put::getK() const
{
	return K;
}

void Put::setK(double K)
{
	this->K = K;
}

double Put::Payoff(double S) const
{
	return (K > S) ? (K - S) : 0.0;
}

