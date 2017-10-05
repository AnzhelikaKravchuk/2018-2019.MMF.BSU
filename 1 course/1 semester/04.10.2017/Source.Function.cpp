#include<iostream>

using namespace std;

double sinTaylor(double , double );

int main()
{
	double x, eps;
	while (true)
	{
		cout << "Enter 0 < epsilon < 1 :";
		cin >> eps;
		if (eps > 0 && eps < 1)
		{
			break;
		}
		cout << "Invalid data! Try again!";
		system("pause");
		system("cls");
	}
	cout << "Enter x ";
	cin >> x;
	system("cls");
	cout << "sum = " << sinTaylor(x,eps) << endl;
	cout << "sin = " << sin(x) << endl;
	system("pause");
}

double sinTaylor(double x, double eps)
{
	double term = x, sum = 0;
	for (int i = 1; fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i) / (2 * i + 1);
	}
	return sum;
}