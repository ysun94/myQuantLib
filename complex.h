#pragma once
#include <iostream>

class Complex {
private:
	double re, im;
public:
	Complex();
	Complex(double re_, double im_);
	Complex(const Complex& c);
	~Complex(){};

	void set_re(double re);
	void set_im(double im);
	double get_re() const;
	double get_im() const;

	Complex& operator+= (const Complex& other);
	Complex& operator= (const Complex& other);
	bool operator== (const Complex& a) const;
	
};

Complex operator+ (const Complex& a, const Complex& b);
Complex operator- (const Complex& a, const Complex& b);
Complex operator* (const Complex& a, const Complex& b);
std::ostream& operator<< (std::ostream& out, const Complex& c);