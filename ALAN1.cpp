#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// Ferrari, Matricola 4784573
	// dichiaro d0 e d1
	const double d0 = 3;
	const double d1 = 7;

	double a, b, c;
	double r1, r2;

	for(int i=0; i<=6; i++)
	{
		cout << "Per i=" << i << endl;

		a = (d0 + 1)*pow (10, i);
		b = (d1 + 1)*pow (10, 20);
		c = -b;

		cout << "a = " << a << endl;
		cout << "b = " << b << endl;
		cout << "c = " << c << endl;

		r1 = (a+b) + c;
		r2 = a + (b+c);

		cout << "(a+b) + c = " << r1 << endl;
		cout << "a + (b+c) = " << r2 << endl;

		cout << endl;
	}

	return 0;
}