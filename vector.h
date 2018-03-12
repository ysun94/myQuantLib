#pragma once


class  Vector
{
public:
	Vector();
	Vector(int size);
	Vector(const Vector& v);
	~Vector();

	int max() const;
	int sum() const;
	int get_size() const;
	void push_back(int value);
	void show() const;

private:
	int* ptr;
	int size;
	int capacity; //larger than size

protected:
};
