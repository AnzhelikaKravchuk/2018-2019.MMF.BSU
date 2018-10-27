#include<iostream>
//#include "IntegerExtention.h"

bool isPrimeNumber(int n);
void showAllPrimeNumbersBetween(int start, int end);

using namespace std;

int main()
{
	showAllPrimeNumbersBetween(100, 1000);
	system("pause");
	return 0;
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