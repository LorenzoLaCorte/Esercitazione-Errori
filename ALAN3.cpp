#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	// calcolo eps in float
	int d = 0;
	float eps, res;

	do
	{
		eps = pow (2, -d);

		res = 1 + eps;		

		d++;

	} while(res > 1);
		
	cout << "eps con singola precisione: " << eps << endl << endl;


	// calcolo eps in double
	d = 0;
	double epsd, resd;

	do
	{
		epsd = pow (2, -d);

		resd = 1 + epsd;		

		d++;

	} while(resd > 1);
		
	cout << "eps con doppia precisione: " << epsd  << endl;

	return 0;
}