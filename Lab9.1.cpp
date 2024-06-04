//============================================================================
// Name        : 1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
/*
 * Polynomial.cpp
*/

/*
polynomial + polynomial
constant + polynomial
polynomial + constant
polynomial - polynomial
constant -polynomial
polynomial - constant
polynomial * polynomial
constant * polynomial
polynomial * constant
*/

#include <iostream>
#include <cmath>
#include "polynomial.h"
using namespace std;

Polynomial::Polynomial()
{
	degree = 10;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
		//cout << "initializing coeff[" << i << "] = " << coeff[i] <<endl;
	}
}

Polynomial::Polynomial(int degr)
{
	degree = degr;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial &poly)
{
	degree = poly.get_degree();
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = poly.get_coeff(i);
	}
}

Polynomial::Polynomial(double cf[], int deg)
{
	degree = deg;
	coeff = new double[degree+1];
	for (int i = 0; i <= degree; i++)
	{
		coeff[i] = cf[i];
	}
}

Polynomial::~Polynomial()
{
	delete coeff;
}

int Polynomial::get_degree() const
{
	return degree;
}

double Polynomial::get_coeff(int deg) const
{
	if (degree < deg)
	{
		return 0;
	}
	return get_coeff(deg);
}

void Polynomial::set_coeff(int degr, double val)
{
	if (degree < degr)
	{
		cout << "Degree exceeded." << endl;
		return;
	}
	coeff[degr] = val;
}

double Polynomial::evaluate(double val)
{
	double a=0;
	double b;

	// evaluate polynomial using val
	for (int i=0; i<=degree; i++)
	{
		a += coeff[i] * pow(val, i);
	}
	return a;
}

/*
Polynomial operator=(const Polynomial &poly)
{
	if (this == &poly)
	{
		return;
	}
	// ...
}
*/

Polynomial operator+(const Polynomial &pola, const Polynomial &polb)
{
  int degra = pola.degree;
  int degrb = polb.degree;
  Polynomial poly(max(degra,degrb));

  int i;

  // copy polynomial a into return polynomial
  for (i=0; i<=degra; i++)
  {
    poly.coeff[i] = pola.coeff[i];
  }
  // add poly b to poly a
  for (i=0; i<=degrb; i++)
  {
    poly.coeff[i] += polb.coeff[i];
  }

	return poly;
}

Polynomial operator-(const Polynomial &pola, const Polynomial &polb)
{
  int degra = pola.degree;
  int degrb = polb.degree;
  Polynomial poly(max(degra,degrb));

  int i;

	// copy polynomial a into return polynomial
	for (i=0; i<=degra; i++)
	{
		poly.coeff[i] = pola.coeff[i];
	}
	// subtract poly b from poly a
	for (i=0; i<=degrb; i++)
	{
		poly.coeff[i] -= polb.coeff[i];
	}

	return poly;
}

Polynomial operator*(const Polynomial &pola, const Polynomial &polb)
{
  int degra = pola.degree;
  int degrb = polb.degree;

 Polynomial poly(degra + degrb);


  int i,j;
	for (i=0; i<=degrb; i++)
	{
		for (j=0; j<=degra; j++)
		{

			poly.coeff[i+j] += polb.coeff[i] * pola.coeff[j];
			//poly.coeff[i+j] = poly.coeff[i+j] + polb.coeff[i]*pola.coeff[j];
		}
	}

  return poly;
}

ostream& operator<<(ostream& ost, const Polynomial &poly)
{
	int degr = poly.degree;
	for (int i=degr; i > 0; i--)
	{
		ost << "(" << poly.coeff[i] << ")" << "*x^" << i << " + ";
	}
	ost << "(" << poly.coeff[0] << ") " ;
	return ost;
}

int main()
{
/* official test cases
f = 2*x^3 + 5*x^2 - 3*x
g = -10*x^2 + 7

f + g = 2x^3 - 5x^2 - 3x + 7
f - g = 2x^3 +15x^2 - 3x - 7
f * g = -20x^5   -50x^4   44x^3  35x^2   -21x
*/

	double f[] = {0,-3,5,2};
	Polynomial pola(f, 3);
	cout << "Initializing Polynomial a: " << pola << endl;

	double g[] = {7,0,-10};
  Polynomial polb(g, 2);
	cout << "Initializing Polynomial b: " << polb << endl;

	double k[] = {5};
	Polynomial c(k,0);
  cout << "Initializing Polynomial c: " << c << endl;

	cout << endl;

	cout << "Evaluating Polynomial:  pola(2) = " << pola.evaluate(2) << endl;
	cout << "Evaluating Polynomial:  polb(4) = " << polb.evaluate(4) << endl;
  cout << "Evaluating Polynomial:  c(4) = " << c.evaluate(4) << endl;
	cout << endl;

	cout << "Polynomial Addition: " << endl;
	cout << "Polynomial + Polynomial: Pola + Polb = " << pola + polb << endl;
	cout << "Constant + Polynomial: c + Pola = " << c + pola << endl;
	cout << "Polynomial + Constant: Pola + c = " << pola + c << endl;
	cout << endl;

	cout << "Polynomial Subtraction:" << endl;
	cout << "Polynomial - Polynomial: Pola - Polb = " << pola - polb << endl;
	cout << "Constant + Polynomial: c - Pola = " << c - pola << endl;
  cout << "Polynomial + Constant: Pola - c = " << pola - c << endl;
	cout << endl;

  cout << "Polynomial multiplication: " << endl;
  cout << "Polynomial * Polynomial: Pola * Polb = " << pola * polb << endl;
  cout << "Constant * Polynomial: c * Pola = " << c * pola << endl;
  cout << "Polynomial * Constant: Pola * c = " << pola * c << endl;



	return 0;
}

