#include"Matrix.h"
#include"Matrix_cal.h"
#include<iostream>
#include<vector>
using namespace std;
Matrix_cal::Matrix_cal()
{

}
Matrix_cal::~Matrix_cal()
{

}
Matrix Matrix_cal::add(Matrix a, Matrix b)
{
	int row1 = a.row;
	int col1 = a.col;
	int row2 = b.row;
	int col2 = b.col;
	Matrix c;
	c.row = row1;
	c.col = col1;
	c.matrix= new double[row1*col1];
	//memset(c.matrix, 0, sizeof(c.matrix));
	if (row1 == row2&&col1 == col2)
	{
		for (int i = 0; i < col1*row1; i++)
		{
			c.matrix[i] = 0;
			c.matrix[i] = a.matrix[i] + b.matrix[i];
		}
	}
	else
	{
		printf("error\n");
		exit(0);
	}
	return c;

}

Matrix Matrix_cal::subtract(Matrix a, Matrix b)
{
	int row1 = a.row;
	int col1 = a.col;
	int row2 = b.row;
	int col2 = b.col;
	Matrix c;
	c.row = row1;
	c.col = col1;
	c.matrix = new double[row1*col1];
	//memset(c.matrix, 0, sizeof(c.matrix));

	if (row1 == row2&&col1 == col2)
	{
		for (int i = 0; i < col1*row1; i++)
		{
			c.matrix[i] = 0;
			c.matrix[i] = a.matrix[i] - b.matrix[i];
		}
	}
	else
	{
		exit(0);
		printf("error\n");
	}
	return c;
}
Matrix Matrix_cal::multiply(Matrix a, Matrix b)
{
	int row1 = a.row;
	int row2 = b.row;
	int col1 = a.col;
	int col2 = b.col;
	if (col1 == row2)
	{
		Matrix c;
		int k = 0;
		c.row = row1;
		c.col = col2;
		c.matrix = new double[row1*col2];
	//	memset(c.matrix, 0, sizeof(c.matrix));
		for (int i = 0; i < col2*row1; i++)
		{
			c.matrix[i] = 0;
		}
		for (int i = 0; i < row1; i++)//横着排列
		{
			int p = 0;
			while (p <col2)
			{
				for (int j = i*col1; j < (i + 1)*col1; j++)
				{
					c.matrix[k] += a.matrix[j] * b.matrix[(j - col1*i)*col2 + p];

				} 
				p++;
				k++;
			}
		}
		return c;
	}
	else {
		printf("error\n");
		exit(0);
		
	}
}

Matrix Matrix_cal::divide(Matrix a, Matrix b)
{
	return multiply(a,Inverse(b));
}
Matrix Matrix_cal::DataMult(int a, Matrix b)
{
	int row = b.row;
	int col = b.col;
	Matrix c;
	c.row = row;
	c.col = col;
	c.matrix = new double[row*col];
	memset(c.matrix, 0, sizeof(c.matrix));
	for (int i = 0; i < row*col; i++)
		c.matrix[i] = b.matrix[i] * a;
	return c;
}

Matrix Matrix_cal::Rotate(Matrix a)//转置
{
	int row = a.row;
	int col = a.col;
	int k = 0;
	Matrix c;
	c.row = col;
	c.col = row;
	c.matrix = new double[col*row];
	memset(c.matrix, 0, sizeof(c.matrix));
	for (int i = 0; i < col; i++)
	{
		for (int j = i*row; j < (i + 1)*row; j++)
		{
			c.matrix[k++] = a.matrix[(j - row*i)*col + i];
		}
	}
	return c;
}
double fun(int n,  double **b)//递归用余子式求行列式,复杂度太高！！！！！！！
{
	int flag = 0,flag1=0;
	double sum = 0;
	double **c;
	c = new double*[n];
	for (int i = 0; i < n; i++)
	{
		c[i] = new double[n];
	}
	if (n == 1) return b[0][0];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (j < i) flag = 0;
			else flag = 1;
			for (int k = 0; k < n - 1; k++)
			{
				c[j][k] = b[j + flag][k + 1];//余子式
			}
		}
		if (i % 2 == 0) flag1 = 1;
		else flag1 = -1;
		sum = sum + b[i][0] * fun(n - 1, c);
	}
	return sum;
}

Matrix Matrix_cal::Inverse(Matrix a) //逆矩阵
{
	int row = a.row;
	int col = a.col;
	double **p;
	double determinant;
	p = new double*[row];
	for (int i = 0; i < row; i++)
	{
		p[i] = new double[col];
	}

	/*vector<vector<double>> p(row);
	for (int i = 0; i < row; i++)
	{
	p[i].resize(col);
	}*/
	if (col != row) exit(0);
	else
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				p[i][j] = a.matrix[i*col + j];
			}
		}
		determinant = fun(row, p);//整个矩阵行列式的值。
		double **yzs;
		yzs = new double*[row - 1];
		for (int i = 0; i < row - 1; i++)
		{
			yzs[i] = new double[row - 1];
		}

		if (determinant != 0)
		{
			int num = 0;
			Matrix result;
			result.row = row;
			result.col = col;
			result.matrix = new double[row*row];
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < row; j++)
				{
					int cnt = 0, cnt1 = 0;
					for (int pp = 0; pp < row; pp++)
					{
						for (int qq = 0; qq < row; qq++)
						{
							if (i != pp&&j != qq)
							{
								yzs[cnt++][cnt1++] = p[pp][qq];
							}
						}
					}
					result.matrix[num++] = fun(row - 1, yzs) / determinant;
				}
			}
			return result;
		}
		else exit(0);
	}
}


