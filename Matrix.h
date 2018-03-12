#pragma once
#include <iostream>

class Matrix
{
private:
	int nrows;
	int ncols;
	double* data;
	double* endPointer;
	
public:
	Matrix();
	Matrix(int nrows, int ncols);
	Matrix(const Matrix& other);
	~Matrix();



	inline int nRows() const;
	inline int nCols() const;

	inline double get(int i, int j) const;

	inline int offset(int i, int j) const;
};