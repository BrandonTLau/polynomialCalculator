#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
using namespace std;

// class to implement polynomial operations
class Polynomial
{
public:
	Polynomial();
	Polynomial(int degr);
	Polynomial(const Polynomial &poly);
	Polynomial(double cf[], int degr);
	Polynomial(double ct);
	~Polynomial();
	int get_degree() const;
	double get_coeff(int index) const;
	void set_coeff(int index, double val);
	//friend Polynomial operator=(const Polynomial &poly);
	friend Polynomial operator+(const Polynomial &polya, const Polynomial &polyb);
	friend Polynomial operator-(const Polynomial &polya, const Polynomial &polyb);
 	friend Polynomial operator*(const Polynomial &polya, const Polynomial &polyb);
	friend ostream& operator<<(ostream& ost, const Polynomial &poly);
	double evaluate(double val);
private:
	double* coeff;
	int degree;
};

#endif /* POLYNOMIAL_H_ */
