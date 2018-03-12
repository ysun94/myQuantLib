#include "stdafx.h"
#include "Matrix.h"
#include "assert.h"

Matrix::Matrix()
{
	this->nrows = 1;
	this->ncols = 1;
	int size = nrows * ncols;
	data = new double[size];
	endPointer = data + size;
	*data = 0.0;
}

Matrix::Matrix(int nrows, int ncols)
{
	this->nrows = nrows;
	this->ncols = ncols;
	int size = nrows * ncols;
	this->data = new double[size];
	this->endPointer = data + size;
	memset(data, 0, sizeof(double)*size);
	//memset is an optimized low level function
	//that should be faster than looping
}

Matrix::~Matrix()
{
	delete[] data;
}

inline int Matrix::nRows() const
{
	return this->nrows;
}

inline int Matrix::nCols() const
{
	return this->ncols;
}

double Matrix::get(int i, int j) const
{
	return data[ offset(i, j) ];
}

int Matrix::offset(int i, int j) const
{
	assert(i >= 0 && i < nrows &&
		j >= 0 && j < ncols);
	return j * nrows + i;
}
