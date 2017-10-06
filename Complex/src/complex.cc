#include "../include/complex.h"
#include <cmath>
using namespace std;

Complex::Complex(): x(0.0), y(0.0) {}
Complex::Complex(double const& a, double const& b): x(a), y(b) {}

double Complex::rho()
{
	return sqrt(x*x + y*y);
}

double Complex::theta()
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

double Complex::re()
{
	return x;
}

double Complex::im()
{
	return y;
}

ostream& Complex::affiche(ostream& sortie) const
{
	sortie << "(" << x << "," << y << ")";
	return sortie;
}

Complex& Complex::operator+=(Complex const& z)
{
	x += z.x;
	y += z.y;
	return *this;
}

Complex& Complex::operator/=(Complex const& z)
{
	double a = (x*z.x - y*z.x)/(z.x*z.x + z.y*z.y);
	double b = (x*z.y + y*z.x)/(z.x*z.x + z.y*z.y);
	x=a;
	y=b;
	return *this;
}

Complex& Complex::operator-=(Complex const& z)
{
	x -= z.x;
	y -= z.y;
	return *this;
}

Complex& Complex::operator*=(Complex const& z)
{
	double a = x*z.x - y*z.y;
	double b = x*z.y + y*z.x;
	x=a;
	y=b;
	return *this;
}

bool Complex::operator==(Complex const& z)
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

bool Complex::operator!=(Complex const& z)
{
	return !(operator==(z));
}

void Complex::operator=(Complex const& z)
{
	x = z.x;
	y = z.y;
}

Complex operator+(Complex z1, Complex const& z2)
{
	z1 += z2;
	return z1;
}

Complex operator-(Complex z1, Complex const& z2)
{
	z1 -= z2;
	return z1;
}

Complex operator*(Complex z1, Complex const& z2)
{
	z1 *= z2;
	return z1;
}

Complex operator/(Complex z1, Complex const& z2)
{
	z1 /= z2;
	return z1;
}

ostream& operator<<(ostream& sortie, Complex const& z)
{
	return z.affiche(sortie);
}
