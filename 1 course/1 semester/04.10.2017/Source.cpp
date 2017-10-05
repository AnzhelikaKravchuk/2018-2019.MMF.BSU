#include<iostream>

using namespace std;

int main()
{
	/*int n;
	double x;
	while (true)
	{
		cout << "Enter n > 0";
		cin >> n;
		if (n > 0)
		{
			break;
		}
		cout << "Invalid data! Try again!";
		system("pause");
		system("cls");
	}
	cout << "Enter x";
	cin >> x;
	system("cls");

	double term = x, sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i) / (2 * i + 1);
	}

	cout << "sum = " << sum << endl;
	cout << "sin = " << sin(x) << endl;
	system("pause");*/

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

	double term = x, sum = 0;
	int i = 1;
	for (;fabs(term) > eps; i++)
	{
		sum += term;
		term = -term * x * x / (2 * i) / (2 * i + 1);
	}

	cout << x << "  " << sum << "  " << sin(x) << "  " << i << endl;
	//cout << "n = " << i << endl;
	//cout << "sum = " << sum << endl;
	//cout << "sin = " << sin(x) << endl;
	system("pause");
}