#pragma once

#include <iostream>

using namespace std;

double morethenValue(double value)
{
	double x;
	while (true)
	{
		cout << "x > " << value << " : ";
		cin >> x;
		if (x > value)
			return x;
		cout << "Error data!Tey again ";
		system("pause");
		system("cls");
	}
}

bool isPrimeNumber(int n)
{
	if (!(n % 2))
	{
		return false;
	}
	for (int i = 3; i <= sqrt(n); i += 2)
	{
		if (!(n % i))
		{
			return false;
		}
	}
	return true;
}

void showAllPrimeNumbersBetween(int start, int end)
{
	for (int i = start; i <= end; i++)
	{
		if (isPrimeNumber(i))
		{
			cout << i << " ";
		}
	}
}
