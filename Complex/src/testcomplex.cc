#include <iostream>
#include "../include/complex.h"
using namespace std;

int main()
{
	Complex z1(1,2);
	Complex z2(3,4);
	cout << z1 << " " << z2 << endl;
	cout << z1+z2 << endl;
	cout << z1-z2 << endl;
	cout << z1*z2 << endl;
	cout << z1/z2 << endl;
	cout << (z1 == z2) << " " << (z1 != z2) << " " << (z1 == z1) << endl;
	return 0;
}
