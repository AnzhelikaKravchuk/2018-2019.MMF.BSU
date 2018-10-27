#include <iostream>

using namespace std;

double sin(double value, double accurancy, int& count);
void createTable(double left, double right, double step, double eps);
 
int main()
{
	double x = 4;
	double accurancy = 0.01;
	double actual = sin(x);
	cout << actual << endl;
	int n = 0;
	double expected = sin(x, accurancy, n);
	cout << n << endl;
	cout << expected << endl;
	cout << fabs(actual - expected) << endl;
	double a = -1, b = 1, h = 0.1, eps = 0.0001;
	createTable(a, b, h, eps);
	system("pause");
	return 0;
}

double sin(double x, double accurancy, int& n)
{
	double term = x;

	double sinus = term;

	int i = 1;
	while (fabs(term) > accurancy)
	{
		term *= -(x * x) / (2 * i) / (2 * i + 1);
		sinus += term;
		i++;

	}

	n = i;

	return sinus;
}

void createTable(double left, double right, double step, double eps)
{
	for (double x = left; x <= right; x += step)
	{
		int n = 0;
		cout << x << "  " << sin(x, eps, n) << "  " << sin(x) << "  " << fabs(sin(x, eps, n) - sin(x)) << endl;
	}
}
