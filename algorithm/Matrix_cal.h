#ifndef Matrix_calH
#define Matrix_calH

#include "Matrix.h"
class Matrix_cal{
public:
	Matrix_cal();
	~Matrix_cal();
	
	Matrix add(Matrix a, Matrix b);
	Matrix subtract(Matrix a, Matrix b);
	Matrix multiply(Matrix a, Matrix b);
	Matrix divide(Matrix a, Matrix b);

	Matrix multiply(int a, Matrix b);
	Matrix DataMult(int a, Matrix b); //Êı³Ë
	Matrix Rotate(Matrix a);//×ªÖÃ

	Matrix Inverse(Matrix a); //Äæ¾ØÕó
};
#endif