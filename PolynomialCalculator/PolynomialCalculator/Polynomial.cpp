#include "stdafx.h"
#include "Polynomial.h"
#include <iostream>

using namespace std;
//coefficients is a representation of a polynomial with x^0 at coefficients[0] and x^n at coefficients[n]

int max(int a, int b) { return a > b ? a : b; }
int min(int a, int b) { return a < b ? a : b; }

Polynomial::Polynomial(int degree, double *coefficients[])
{
	this->degree = degree;
	this->coefficients = new double[degree + 1];

	for (int i = 0; i <= degree; i++) {
		this->coefficients[i] = (*coefficients)[i];
	}

}
Polynomial::Polynomial(const Polynomial& polynomial)
{
	this->degree = polynomial.degree;
	this->coefficients = new double[polynomial.degree + 1];

	for (int i = 0; i <= polynomial.degree; i++) {
		this->coefficients[i] = polynomial.coefficients[i];
	}
}

Polynomial::~Polynomial()
{
	delete [] this->coefficients;
}

double Polynomial::getCoEff(int power)
{
	return this->coefficients[power];
}

double Polynomial::getComputedValue(double x)
{
	double total = this->coefficients[0];
	for (int i = 1; i <= degree; i++) {
		double newX = x;
		for (int j = 1; j <= i; j++) {
			newX *= x;
		}
		total += newX * coefficients[i];
	}
	return total;
}

Polynomial Polynomial::operator=(const Polynomial& rhs)
{
	return Polynomial(rhs);
}

Polynomial Polynomial::operator+(Polynomial rhs)
{
	int highestDegree = max(rhs.degree, this->degree);

	double *newCoEffs = new double[highestDegree + 1];

	for (int i = 0; i <= highestDegree; i++) {
			newCoEffs[i] = (i <= this->degree ? this->coefficients[i] : 0)
				+ (i <= rhs.degree ? rhs.coefficients[i]: 0);
	}

	return Polynomial(highestDegree, &newCoEffs);
}

Polynomial Polynomial::operator-(Polynomial rhs)
{
	int highestDegree = max(rhs.degree, this->degree);

	double *newCoEffs = new double[highestDegree + 1];

	for (int i = 0; i <= highestDegree; i++) {
		newCoEffs[i] = (i <= this->degree ? this->coefficients[i] : 0)
			- (i <= rhs.degree ? rhs.coefficients[i] : 0);
	}

	return Polynomial(highestDegree, &newCoEffs);
}

Polynomial Polynomial::operator*(Polynomial rhs)
{
	int newDegree = rhs.degree + this->degree;

	double *newCoEffs = new double[newDegree + 1];
	for (int i = 0; i <= newDegree; i++) {
		newCoEffs[i] = 0;
	}

	for (int i = 0; i <= this->degree; i++) {
		for (int j = 0; j <= rhs.degree; j++) {
			newCoEffs[i + j] += (this->coefficients[i] * rhs.coefficients[j]);
		}
	}

	return Polynomial(newDegree, &newCoEffs);
}

Polynomial & Polynomial::operator+=(Polynomial rhs)
{
	int highestDegree = max(rhs.degree, this->degree);

	double *newCoEffs = new double[highestDegree + 1];

	for (int i = 0; i <= highestDegree; i++) {
		newCoEffs[i] = (i <= this->degree ? this->coefficients[i] : 0)
			+ (i <= rhs.degree ? rhs.coefficients[i] : 0);
	}
	this->degree = highestDegree;
	this->coefficients = newCoEffs;

	return *this;
}

Polynomial & Polynomial::operator-=(Polynomial rhs)
{

	int highestDegree = max(rhs.degree, this->degree);

	double *newCoEffs = new double[highestDegree + 1];

	for (int i = 0; i <= highestDegree; i++) {
		newCoEffs[i] = (i <= this->degree ? this->coefficients[i] : 0)
			- (i <= rhs.degree ? rhs.coefficients[i] : 0);
	}
	this->degree = highestDegree;
	this->coefficients = newCoEffs;

	return *this;
}

Polynomial & Polynomial::operator*=(Polynomial rhs)
{
	int newDegree = rhs.degree + this->degree;

	double *newCoEffs = new double[newDegree + 1];
	for (int i = 0; i <= newDegree + 1; i++) {
		newCoEffs[i] = 0;
	}

	for (int i = 0; i <= this->degree; i++) {
		for (int j = 0; j <= rhs.degree; j++) {
			newCoEffs[i + j] += (this->coefficients[i] * rhs.coefficients[j]);
		}
	}
	
	this->degree = newDegree;
	this->coefficients = newCoEffs;

	return *this;
}

bool Polynomial::operator==(Polynomial rhs)
{
	if (this->degree != rhs.degree) {
		return false;
	}
	for (int i = 0; i <= this->degree; i++) {
		if (this->coefficients[i] != rhs.coefficients[i]) {
			return false;
		}
	}
	return true;
}

bool Polynomial::operator!=(Polynomial rhs)
{
	if (this->degree != rhs.degree) {
		return true;
	}
	for (int i = 0; i <= this->degree; i++) {
		if (this->coefficients[i] != rhs.coefficients[i]) {
			return true;
		}
	}
	return false;
}

std::istream & operator>>(std::istream & inStream, Polynomial & polynomial)
{
	cout << "Type the Degree of your Polynomial:";
	inStream >> polynomial.degree;
	double* inputCoEffs = new double[polynomial.degree+1];
	cout << "Type in your Coefficients starting from Ax^N + Bx^N-1 ...";
	for (int i = 0; i <= polynomial.degree; i++) 
	{
		bool valid = false;
		while (!valid)
		{
			double input;
			inStream >> input;
			if (inStream)
			{
				inputCoEffs[polynomial.degree - i] = input;
				valid = true;
			}
		}

	}
	polynomial.coefficients = inputCoEffs;

	return inStream;
}

std::ostream & operator<<(std::ostream & outStream, const Polynomial & polynomial)
{
	for (int i = 0; i <= polynomial.degree; i++) {
		outStream << polynomial.coefficients[polynomial.degree - i] << "x^" << polynomial.degree - i << " + ";
	}
	return outStream;
}
