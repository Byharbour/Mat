#include"Matrix.h"
#include<iostream>

Matrix::Matrix()
{
	row = 0;
	col = 0;
	matrix = NULL;
}

Matrix::Matrix(int row, int col, double* p)
{
	matrix = new double[row*col];
	for (int i = 0; i < row*col; i++)
	{
		matrix[i] = p[i];
	}
}
Matrix::Matrix(const Matrix& p)
{
	row = p.row;
	col = p.col;
	matrix = new double[row*col];
	for (int i = 0; i < row*col; i++)
	{
		matrix[i] = p.matrix[i];
	}

}

Matrix::~Matrix()
{
	/*if (matrix != NULL)
	{
		delete[] matrix;
		matrix = NULL;

	}*/
}