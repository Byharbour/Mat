#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"Matrix.h"
#include"Matrix_cal.h"
int main()
{
	 Matrix a,b;
	 Matrix_cal m;
	int row1, col1,row2,col2;
	scanf("%d %d",&row1,&col1);
	a.row = row1;
	a.col = col1;
	a.matrix = new double[row1*col1];
	for (int i = 0; i < row1*col1; i++)
	{
		double num1;
		scanf("%lf", &num1);
		a.matrix[i] = num1;
	}
	Matrix c;
	c.row = row1;
	c.col = col1;
	c.matrix = new double[row1*col1];
	c = m.Rotate(a);
	for (int i = 0; i < row1*col1; i++)
		printf("%lf ", c.matrix[i]);
	//scanf("%d %d", &row2, &col2);
	//b.row = row2;
	//b.col = col2;
	//b.matrix = new double[row2*col2];
	//for (int i = 0; i < row2*col2; i++)
	//{
	//	double num2;
	//	scanf("%lf", &num2);
	//	b.matrix[i] = num2;
	//}
	//Matrix c;
	//c.row = row2;
	//c.col = col2;
	//c.matrix = new double[row2*col2];
	////c = m.add(a,b);
	//c=m.multiply(a,b);
	/*for (int i = 0; i < row1*col2; i++)
		printf("%lf ",c.matrix[i]);*/
}