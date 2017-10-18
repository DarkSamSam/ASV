#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex
{
public:
	Complex();
	Complex(double const& a, double const& b);
	double re() const;
	double im() const;
	double rho() const;
	double theta() const;
	std::ostream& affiche(std::ostream& sortie = std::cout) const;
	const Complex& operator+=(Complex const& z);
	const Complex& operator-=(Complex const& z);
	const Complex& operator*=(Complex const& z);
	const Complex& operator/=(Complex const& z);
	bool operator==(Complex const& z) const;
	bool operator!=(Complex const& z) const;
	void operator=(Complex const&z);

private:
	double x;
	double y;
};

const Complex operator+(Complex z1, Complex const& z2);
const Complex operator-(Complex z1, Complex const& z2);
const Complex operator*(Complex z1, Complex const& z2);
const Complex operator/(Complex z1, Complex const& z2);
std::ostream& operator<<(std::ostream& sortie, Complex const& z);

#endif
