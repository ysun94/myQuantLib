#pragma once
#include <iostream>

class YourVector
{
private:
	int size;
	int* Name;
public:
	YourVector();
	YourVector(int size);
	YourVector(const YourVector& other);
	~YourVector();

	int get_size() const;
	int get_name(int i) const;

	YourVector& operator= (const YourVector& other);
	int& operator[] (int subscript);
	const int& operator[] (int subscript) const;

};

bool operator== (const YourVector& left, const YourVector& right);
bool operator!= (const YourVector& left, const YourVector& right);
std::ostream& operator<< (std::ostream& out, const YourVector& v);