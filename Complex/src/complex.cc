double Complex::rho(){}
double Complex::theta(){}
double Complex::re(){}
double Complex::im(){}
ostream& Complex::affiche(){}
Complex& Complex::operator+=(Complex const& z){}
Complex& Complex::operator/=(Complex const& z){}
Complex& Complex::operator-=(Complex const& z){}
Complex& Complex::operator*=(Complex const& z){}
bool Complex::operator==(Complex const& z){}
bool Complex::operator!=(Complex const& z){}
void Complex::operator=(Complex const& z){}

Complex& operator+(Complex z1, Complex const& z2){}
Complex& operator-(Complex z1, Complex const& z2){}
Complex& operator*(Complex z1, Complex const& z2){}
Complex& operator/(Complex z1, Complex const& z2){}
ostream& operator<<(Complex const& z){}
