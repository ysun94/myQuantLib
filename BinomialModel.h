#pragma once

class BinomialModel
{
private:
	double S0;
	double U;
	double D;
	double R;
public:
	BinomialModel();
	BinomialModel(double S0, double U, double D, double R);

	double get_RiskNeuProb() const;
	double S(int n, int i) const;
	double getR() const;
	double getStock() const;
	double getU() const;
	double getD() const;
	void setR(double R);
	void setStock(double S);
	void setU(double U);
	void setD(double D);
	void CheckData() const;
};