#include "stdafx.h"
#include "Quadratic.h"

#include <iostream>

using namespace std;
	Quadratic::Quadratic(double a, double b, double c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}

	double Quadratic::getCoEff(int power)
	{
		switch (power) {
		case 0:
			return c;
			break;
		case 1:
			return b;
			break;
		case 2:
			return a;
			break;
		default:
			throw std::invalid_argument("received power of x is not between 0 - 2");
			break;
		}
	}

	double Quadratic::getComputedValue(double x)
	{
		return c + (x*b) + ((x*x)*a);
	}

	Quadratic Quadratic::operator+(Quadratic rhs)
	{
		double newA = this->a + rhs.a;
		double newB = this->b + rhs.b;
		double newC = this->c + rhs.c;

		return Quadratic(newA, newB, newC);
	}

	Quadratic Quadratic::operator-(Quadratic rhs)
	{
		double newA = this->a - rhs.a;
		double newB = this->b - rhs.b;
		double newC = this->c - rhs.c;

		return Quadratic(newA, newB, newC);
	}

	Quadratic& Quadratic::operator+=(Quadratic rhs)
	{
		this->a = this->a + rhs.a;
		this->b = this->b + rhs.b;
		this->c = this->c + rhs.c;

		return *this;
	}

	Quadratic& Quadratic::operator-=(Quadratic rhs)
	{
		this->a = this->a - rhs.a;
		this->b = this->b - rhs.b;
		this->c = this->c - rhs.c;

		return *this;
	}

	bool Quadratic::operator==(Quadratic rhs)
	{
		if (this->a == rhs.a && this->b == rhs.b && this->c == rhs.c) {
			return true;
		}
		return false;
	}

	bool Quadratic::operator!=(Quadratic rhs)
	{
		if (this->a == rhs.a && this->b == rhs.b && this->c == rhs.c) {
			return false;
		}
		return true;
	}

	istream & operator>>(istream& inStream, Quadratic& quadratic)
	{
		inStream >> quadratic.a >> quadratic.b >> quadratic.c;
		return inStream;
	}

	ostream & operator<<(ostream& outStream, const Quadratic& quadratic)
	{
		outStream << quadratic.a << quadratic.b << quadratic.c;
		return outStream;
	}