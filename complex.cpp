#include "stdafx.h"
#include "complex.h"

//default constructor
Complex::Complex()
{
	re = 0.0;
	im = 0.0;
}
// constructor with parameters
Complex::Complex(double re_, double im_)
{
	this->re = re_;
	this->im = im_;
}
// copy constructor
Complex::Complex(const Complex& c)
{
	this->re = c.get_re();
	this->im = c.get_im();
}

inline double Complex::get_re() const
{
	return (*this).re;
}

inline double Complex::get_im() const
{
	return (*this).im;
}

inline void Complex::set_re(double re)
{
	this->re = re;
}


inline void Complex::set_im(double im)
{
	this->im = im;
}

Complex& Complex::operator+=(const Complex& other)
{
	this->re += other.re;
	this->im += other.im;
	return *this;
}

Complex& Complex::operator=(const Complex& other)
= default;
/*
 * this->re += other.re;
 * this->im += other.im;
 * return *this;
 */

bool Complex::operator==(const Complex& a) const
{
	return this->re == a.get_re() && this->im == a.get_im();
}

Complex operator+(const Complex& a, const Complex& b)
{
	Complex temp(a.get_re() + b.get_re(),
		a.get_im() + b.get_im());
	return temp;
}

Complex operator-(const Complex& a, const Complex& b)
{
	Complex temp(a.get_re() - b.get_re(), 
		a.get_im() - b.get_im());
	return temp;
}

Complex operator*(const Complex& a, const Complex& b)
{
	Complex temp;
	temp.set_re(a.get_re()*b.get_re() - a.get_im()*b.get_re());
	temp.set_im(a.get_re()*b.get_re() + a.get_im()*b.get_re());
	return  temp;
}

std::ostream& operator<<(std::ostream& out, const Complex& c)
{
	out << "( " << c.get_re() << ", " << c.get_im() << " )";
	return out;
}


