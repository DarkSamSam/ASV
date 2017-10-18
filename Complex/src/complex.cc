#include "../include/complex.h"
#include <cmath>
using namespace std;

Complex::Complex(): x(0.0), y(0.0) {}
Complex::Complex(double const& a, double const& b): x(a), y(b) {}

double Complex::rho() const
{
	return sqrt(x*x + y*y);
}

double Complex::theta() const
{
	double const module(rho());
	double const precision(1e-15);
	if(abs(module) < precision)
	{
		return 0.0;
	}
	else if ((abs(y) < precision) && (x < 0.0))
	{
		return M_PI;
	}
	else
	{
		return 2.0 * atan(y/(x+module));
	}
}

double Complex::re() const
{
	return x;
}

double Complex::im() const
{
	return y;
}

ostream& Complex::affiche(ostream& sortie) const
{
	sortie << "(" << x << "," << y << ")";
	return sortie;
}

const Complex& Complex::operator+=(Complex const& z)
{
	x += z.x;
	y += z.y;
	return *this;
}

const Complex& Complex::operator/=(Complex const& z)
{
	double a = (x*z.x - y*z.x)/(z.x*z.x + z.y*z.y);
	double b = (x*z.y + y*z.x)/(z.x*z.x + z.y*z.y);
	x=a;
	y=b;
	return *this;
}

const Complex& Complex::operator-=(Complex const& z)
{
	x -= z.x;
	y -= z.y;
	return *this;
}

const Complex& Complex::operator*=(Complex const& z)
{
	double a = x*z.x - y*z.y;
	double b = x*z.y + y*z.x;
	x=a;
	y=b;
	return *this;
}

bool Complex::operator==(Complex const& z) const
{
	if(x == z.x && y == z.y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Complex::operator!=(Complex const& z) const
{
	return !(operator==(z));
}

void Complex::operator=(Complex const& z)
{
	x = z.x;
	y = z.y;
}

const Complex operator+(Complex z1, Complex const& z2)
{
	z1 += z2;
	return z1;
}

const Complex operator-(Complex z1, Complex const& z2)
{
	z1 -= z2;
	return z1;
}

const Complex operator*(Complex z1, Complex const& z2)
{
	z1 *= z2;
	return z1;
}

const Complex operator/(Complex z1, Complex const& z2)
{
	z1 /= z2;
	return z1;
}

ostream& operator<<(ostream& sortie, Complex const& z)
{
	return z.affiche(sortie);
}
