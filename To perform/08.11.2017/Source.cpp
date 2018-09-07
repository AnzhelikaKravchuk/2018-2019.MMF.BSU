#include <iostream>
#include"IntegerExtention.h"

using namespace std;

void GenerateRandomArray(int array[], int n, int range);
void GenerateArray(int array[], int n);
void EnterArray(int array[], int n);
void DisplayArray(int array[], int n);
int FirstMinIndex(int array[], int n);
int FirstMaxIndex(int array[], int n);
void Swap(int&, int&);
void ReverseArray(int array[], int n);
void FindAllPrimeElements(int array[], int n, int newArray[], int& m);

int main()
{
	const int N = 100;
	int array[N] = {0};
	int n;
	cout << rand() << endl;
	while (true)
	{
		cout << "Enter n <= " << N << endl;
		cin >> n;
		if (n >= 1 && n <= N)
		{
			break;
		}
		cout << "try again" << endl;
	}
	system("cls");
	//GenerateRandomArray(array, n, 100);
	cout << "Enter elements of array" << endl;
	//EnterArray(array, n);
	GenerateArray(array,n);
	system("cls");
	cout << "Source array" << endl;
	DisplayArray(array, n);
	int k = FirstMinIndex(array, n), 
		l = FirstMaxIndex(array, n);
	cout << endl << "min = " << array[k] << endl;
	cout << "max = " << array[l] << endl;
	Swap(array[k], array[l]);
	cout << "Source array" << endl;
	DisplayArray(array, n);
	ReverseArray(array, n);
	cout << "Source array" << endl;
	DisplayArray(array, n);
	int primeArray[N] = { 0 };
	int m;
	FindAllPrimeElements(array, n, primeArray, m);
	cout << "Prime array" << endl;
	DisplayArray(primeArray, m);
	system("pause");
}

void GenerateRandomArray(int array[], int n, int range)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % range - range / 2;//0..range - 1
	}
}

void DisplayArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void EnterArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << " a[" << (i + 1) << "] = ";
		cin >> array[i];
	}
}

int FirstMinIndex(int array[], int n)
{
	int min = 0;
	for (int i = 1; i < n; i++)
	{
		if (array[min] > array[i])
		{
			min = i;
		}
	}
	return min;
}

int FirstMaxIndex(int array[], int n)
{
	int max = 0;
	for (int i = 1; i < n; i++)
	{
		if (array[max] < array[i])
		{
			max = i;
		}
	}
	return max;
}

void Swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void GenerateArray(int array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = i + 1;
	}
}

void ReverseArray(int array[], int n)
{
	for (int i = 0; i < n / 2; i++)
	{
		Swap(array[i],array[n - i - 1]);
	}
}

void FindAllPrimeElements(int array[], int n, int newArray[], int& m)
{
	m = 0;
	for (int i = 0; i < n; i++)
	{
		if (isPrimeNumber(array[i]))
		{
			newArray[m] = array[i];
			m++;
		}
	}
}