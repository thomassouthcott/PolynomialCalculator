// Coursework.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Polynomial.h"
#include "Quadratic.h"

#include <iostream>

using namespace std;

int main()
{
	cout << "Quadratic Tests \n";
	Quadratic q = Quadratic(1, 2, 4);
	cout << q << "\n";

	Quadratic q2 = Quadratic(1,1,1);
	cin >> q2;

	cout << q2 << "\n";


	cout << "Polynomial Tests \n";
	double *dArr = new double[5];

	dArr[0] = 12;
	dArr[1] = 5;
	dArr[2] = 6;
	dArr[3] = 78;
	dArr[4] = 32;

	Polynomial p = Polynomial(4, &dArr);

	cout << p << " P1 \n";



	double *d2Arr = new double[4];

	d2Arr[0] = 10;
	d2Arr[1] = 2;
	d2Arr[2] = 3;
	d2Arr[3] = 1;

	Polynomial p2 = Polynomial(3, &d2Arr);

	cout << p2 << " P2 \n";


	cout << "Get CoEff " << p.getCoEff(4) << "\n";

	cout << "Get Computed Value " << p.getComputedValue(2) << "\n";

	cout << p + p2 << " + \n";

	cout << p - p2<< " - \n";

	cout << p * p2 << " * \n";

	Polynomial p3 = Polynomial(p2);
	p3 += p;
	cout << p3 << " += \n";

	Polynomial p4 = p2;
	p4 -= p;
	cout << p4 << " -= \n";

	Polynomial p5 = p2;

	p5 *= p;
	cout << p5 << " *= \n";

	bool output;

	Polynomial p6 = Polynomial(p2);
	output = p6 == p2;
	cout << output << " == \n";

	output = p6 != p;
	cout << output << " != \n";


	int x;
	cin >> x;
    return 0;
}

