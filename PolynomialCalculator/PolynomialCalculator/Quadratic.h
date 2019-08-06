#include <iostream>

class Quadratic
{
public:
	//Constructor
	Quadratic(double a, double b, double c);

	//Member Functions
	double getCoEff(int power);
	double getComputedValue(double x);

	//Arithmetic Operators
	Quadratic operator+(Quadratic rhs);
	Quadratic operator-(Quadratic rhs);

	//Update Operators
	Quadratic& operator+=(Quadratic rhs);
	Quadratic& operator-=(Quadratic rhs);

	//Relational Operators
	bool operator==(Quadratic rhs);
	bool operator!=(Quadratic rhs);

	friend std::istream& operator>>(std::istream&  inStream, Quadratic& quadratic);
	friend std::ostream& operator<<(std::ostream& outStream, const Quadratic& quadratic);

private:
	double a;
	double b;
	double c;
};
