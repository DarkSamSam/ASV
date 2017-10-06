class Complex
{
public:
	double re();
	double im();
	double rho();
	double theta();
	ostream& affiche(z);
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
}

Complex operator+(Complex z1, Complex const& z2);
Complex operator-(Complex z1, Complex const& z2);
Complex operator*(Complex z1, Complex const& z2);
Complex operator/(Complex z1, Complex const& z2);
ostream& operator<<(ostream& sortie, Complex const& z);

