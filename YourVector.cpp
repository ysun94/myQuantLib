#include "stdafx.h"
#include "YourVector.h"
#include <iostream>

YourVector::YourVector()
{
	size = 0;
	Name = nullptr;
}

YourVector::YourVector(int size)
{
	if(size < 0)
	{
		this->size = 0;
		this->Name = nullptr;
	}
	this->size = size;
	this->Name = new int[size];
	for(int i = 0; i < size; i++)
	{
		Name[i] = 0;
	}
}

YourVector::YourVector(const YourVector& other)
{
	this->size = other.size;
	if (other.size == 0)
	{
		this->Name = nullptr;
	}
	else 
	{ 
		this->Name = new int[size];
		for(int i = 0; i < size; i++)
		{
			Name[i] = other.Name[i];
		}
	}
	
}

YourVector::~YourVector()
{
	delete[] Name;
}

int YourVector::get_size() const
{
	return this->size;
}

int YourVector::get_name(int i) const
{
	return (*this).Name[i];
}

YourVector& YourVector::operator=(const YourVector& other)
{
	if(&other != this)
	{
		if(size != other.size)
		{
			delete[] Name;
			size = other.size;
			Name = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			Name[i] = other.get_name(i);
		}
	}
	return *this;
}

int& YourVector::operator[](int subscript)
{
	if (subscript >= size || subscript < 0)
	{
		std::cerr << "\nError: Subsvript" << subscript << "out of range" << std::endl;
		exit(1);
	}
	return Name[subscript];
}

const int& YourVector::operator[](int subscript) const
{
	if (subscript >= size || subscript < 0)
	{
		std::cerr << "\nError: Subsvript" << subscript << "out of range" << std::endl;
		exit(1);
	}
	return Name[subscript];
}

bool operator==(const YourVector& left, const YourVector& right)
{
	if (left.get_size() != right.get_size())
	{
		return false;
	}
	for (int i = 0; i < left.get_size(); i++)
	{
		if (left.get_name(i) != right.get_name(i))
		{
			return false;
		}
	}
	return true;
}

bool operator!=(const YourVector& left, const YourVector& right)
{
	return !(left == right);
}


std::ostream& operator<<(std::ostream& out, const YourVector& v)
{
	out << "[ ";
	for (int i = 0; i < v.get_size(); i++)
	{
		out << v[i] << " ";
	}
	out << "]";
	return out;
}