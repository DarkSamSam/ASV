#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
	Complex();
	Complex(double const& a, double const& b);
	double re();
	double im();
	double rho();
	double theta();
	std::ostream& affiche(std::ostream& sortie = std::cout) const;
	Complex& operator+=(Complex const& z);
	Complex& operator-=(Complex const& z);
	Complex& operator*=(Complex const& z);
	Complex& operator/=(Complex const& z);
	bool operator==(Complex const& z);
	bool operator!=(Complex const& z);
	void operator=(Complex const&z);

private:
	double x;
	double y;
};

Complex operator+(Complex z1, Complex const& z2);
Complex operator-(Complex z1, Complex const& z2);
Complex operator*(Complex z1, Complex const& z2);
Complex operator/(Complex z1, Complex const& z2);
std::ostream& operator<<(std::ostream& sortie, Complex const& z);

#endif
