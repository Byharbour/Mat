#ifndef MatrixH
#define MatrixH

#include<iostream>

class  Matrix{
public:
	int row;
	int col;
	double *matrix;
public:
	Matrix();
	Matrix(int row, int col, double*matrix);
	Matrix(const Matrix&);
	~Matrix();
};
#endif 