#pragma once

class Option
{
private:
	int N;
public:
	void setN(int);
	int getN() const;
	virtual double Payoff(double S) const = 0;
	virtual ~Option() {};
};

class EurOption : public virtual Option
{
//private:
//	int N;
public:
	// I have defined a base class named Option
	// the functions below are not need to define but they are inherited from the base class
	/*void setN(int);
	int getN() const;
	virtual double Payoff(double S) const = 0;*/
	double PriceByCRR(const BinomialModel& model) const;
	virtual ~EurOption(){};

};

class AmOption : public virtual Option
{
//private:
//	int N;
public:
	// I have defined a base class named Option
	// the functions below are not need to define but they are inherited from the base class
	 /*void setN(int N);
	 int getN() const;
	 virtual double Payoff(double S) const = 0;*/
	double PriceBySnell(const BinomialModel& model) const;
	virtual ~AmOption(){};
};

class Call: public EurOption, public AmOption
{
private:
	double K; // strike price
public:
	double getK() const;
	void setK(double K);
	double Payoff(double S) const;
	~Call() {};
};

class Put : public EurOption, public AmOption
{
private:
	double K; // strike price
public:
	double getK() const;
	void setK(double K);
	double Payoff(double S) const override;
	~Put() {};
};

