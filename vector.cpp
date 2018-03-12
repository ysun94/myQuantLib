#include "stdafx.h"
#include "vector.h"
#include <iostream>

Vector::Vector()
{
	size = 0;
	capacity = 0;
	ptr = nullptr;
}

Vector::Vector(int size)
{
	if(size < 0)
	{
		this->size = 0;
		this->capacity = 0;
		this->ptr = nullptr;
	}
	else
	{
		this->size = size;
		this->capacity = 2 * size;
		this->ptr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			ptr[i] = 0;
		}
	}
}

Vector::Vector(const Vector& v)
{
	this->size = v.size;
	this->capacity = v.capacity;
	if (this->capacity == 0)
	{
		this->ptr = nullptr;
	}
	else
	{
		this->ptr = new int[capacity];
		for(int i = 0; i < size; i++)
		{
			ptr[i] = v.ptr[i];
		}
	}
	
}//exam


Vector::~Vector()
{
	delete[] ptr;
}

int Vector::max() const
{
	int num = ptr[0];
	for(int i = 1; i < size; i++)
	{
		num = (ptr[i] > num) ? ptr[i] : num;
		/*
		 * if (ptr[i] > num){
		 * num = ptr[i]
		 * }
		 */
	}
	return num;
}

int Vector::sum() const
{
	int num = 0;
	for(int i = 0; i < size; i++)
	{
		num += ptr[i];
	}
	return num;
}

int Vector::get_size() const
{
	return size;
}

void Vector::push_back(int value)
{
	if(capacity == 0)
	{
		capacity = 100;
		ptr = new int[capacity];
	}
	else
	{
		if(size == capacity)
		{
			capacity = 2 * capacity;
			int *temp = new int[capacity];
			for(int i = 0; i < size; i++)
			{
				temp[i] = ptr[i];
			}
			ptr = temp;
			delete[] temp;
		}
	}
	ptr[size] = value;
	size++;
}

void Vector::show() const
{
	std::cout << "[ ";
	for(int j = 0; j < size; j++)
	{
		std::cout << ptr[j] << " ";
	}
	std::cout << "]";
}


