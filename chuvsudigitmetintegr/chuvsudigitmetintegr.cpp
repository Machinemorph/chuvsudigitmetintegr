// chuvsudigitmetintegr.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

inline double func(double x)
{
	return 1 / cos(x);
}

void trapec(double a, double b, double h)
{
	int start = clock();
	double x = a + h;
	double res = 0;
	while (x < b)
	{
		res += func(x);
		x += h;
	}
	//res += 0.5 * (func(a) + func(b));
	//res = res * h;
	cout << "trapecii:" << endl << h * (res + 0.5 * (func(a) + func(b))) << endl;
	cout << "zatracheno " << clock() - start << endl << endl;
}

void simpson(double a, double b, double h)
{
	int start = clock();
	//int n = (int)(b - a) / h;
	double s1 = 0, s2 = 0;
	double x = a + h;
	cout << "simpson:" << endl;
	//if (n % 2 == 0)
	//{
		while (x < b)
		{
			s1 += func(x);
			x += h;
			s2 += func(x);
			x += h;
		}
		cout << h * (func(a) + func(b) + 4 * s1 + 2 * s2) / 3 << endl;
	//}
	//else cout << "izmenite tochnost'" << endl;
	cout << "zatracheno " << clock() - start << endl << endl;
}

int main()
{
	//0.881373587019
	int start = clock();
	double a = 0, b = 3.1415926 / 4;
	double h = 0.0000001;
	trapec(a, b, h);
	simpson(a, b, h);
	cout << "zatracheno " << clock() - start << endl;
	system("pause");
	return 0;
}

