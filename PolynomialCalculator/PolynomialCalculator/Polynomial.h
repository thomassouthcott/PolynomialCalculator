#include <iostream>

class Polynomial
{
public:
	Polynomial(int degree, double *coefficients[]);
	Polynomial(const Polynomial& polynomial);
	~Polynomial();

	//Member Functions
	double getCoEff(int power);
	double getComputedValue(double x);

	//Assignment Operator
	Polynomial operator=(const Polynomial& rhs);

	//Arithmetic Operators
	Polynomial operator+(Polynomial rhs);
	Polynomial operator-(Polynomial rhs);
	Polynomial operator*(Polynomial rhs);

	//Update Operators
	Polynomial& operator+=(Polynomial rhs);
	Polynomial& operator-=(Polynomial rhs);
	Polynomial& operator*=(Polynomial rhs);

	//Relational Operators
	bool operator==(Polynomial rhs);
	bool operator!=(Polynomial rhs);

	friend std::istream& operator>>(std::istream&  inStream, Polynomial& polynomial);
	friend std::ostream& operator<<(std::ostream& outStream, const Polynomial& polynomial);

protected:
	int degree;
	double *coefficients;
};

