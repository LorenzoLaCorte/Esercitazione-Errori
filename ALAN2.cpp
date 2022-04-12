#include <iostream>
#include <math.h>

using namespace std;

double factorial(double n) 
{
    if (n == 0)
       return 1;
    return n * factorial(n - 1);
}

double taylor(double x, double N) 
{
	double sum = 0;	

	for(double n=0; n<=N; n++)
	{
		double xallan = pow(x, n);
		double nfact = factorial(n);
		double res = xallan / nfact;

		sum += res;
	}

	return sum;
}



int main()
{
	int size_x = 4;

	int size_N = 5;
	
	double x[size_x]={0.5, 30, -0.5, -30};

	double N[size_N]={3, 10, 50, 100, 150};

	// Algoritmo 1
	cout << endl << "Algoritmo 1:" << endl << endl;

	for(int i=0; i<size_x; i++)
	{
		for(int j=0; j<size_N; j++)
		{
			double esp = exp(x[i]);
			double res = taylor(x[i], N[j]); 

			double err_a = res - esp;
			double err_r = (res - esp) / esp;

			cout << "Errore assoluto con x=" << x[i] << " e N=" << N[j] << ": " << err_a << endl;
			
		}	

		cout << endl;

		for(int j=0; j<size_N; j++)
		{
			double esp = exp(x[i]);
			double res = taylor(x[i], N[j]); 

			double err_a = res - esp;
			double err_r = (res - esp) / esp;

			cout << "Errore relativo con x=" << x[i] << " e N=" << N[j] << ": " << err_r << endl;
		}	

		cout << endl << endl;
	}

	// Algoritmo 2
	cout << "Algoritmo 2:" << endl << endl;

	// lo trovo solo per 0.5 e 30 per poi fare il reciproco
	for(int i=0; i<2; i++)
	{
		for(int j=0; j<size_N; j++)
		{
			// confronto l'esp dei negativi (shifto i di 2)
			double esp = exp(x[i+2]);

			// con il reciproco del risultato della taylor sui positivi
			double res = 1/taylor(x[i], N[j]); 

			// cout << "Taylor: " << res << endl;

			double err_a = res - esp;
			double err_r = (res - esp) / esp;

			cout << "Errore assoluto con x=" << x[i+2] << " e N=" << N[j] << ": " << err_a << endl;
		}	

		cout << endl;

		for(int j=0; j<size_N; j++)
		{
			// confronto l'esp dei negativi (shifto i di 2)
			double esp = exp(x[i+2]);

			// con il reciproco del risultato della taylor sui positivi
			double res = 1/taylor(x[i], N[j]); 

			// cout << "Taylor: " << res << endl;

			double err_a = res - esp;
			double err_r = (res - esp) / esp;

			cout << "Errore relativo con x=" << x[i+2] << " e N=" << N[j] << ": " << err_r << endl;
		}	

		cout << endl;
	}

	return 0;
}