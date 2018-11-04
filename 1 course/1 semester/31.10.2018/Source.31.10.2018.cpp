#include<iostream>

using namespace std;

void swap(int&, int&);
void swap(int*, int*);
void inputArray(int*, int);
void displayArray(int*, int);
void findMinAndMax(int*, int, int&, int&);

int main()
{
	const int N = 100;// max dimention

	int array[N] = { 0 };
	
	int n;//real dimention

	while (true)
	{
		cout << "Enter dimention of array <= " << N << " :";
		cin >> n;
		if (n >= 1 && n <= N)
		{
			break;
		}

		cout << "Invalid data!";
	}

	inputArray(array, n);
	system("cls");
	cout << "Source array" << endl;
	displayArray(array, n);
	int min, max;
	findMinAndMax(array, n, min, max);
	cout << "Result array" << endl;

	swap(array[min], array[max]);

	displayArray(array, n);
	//array[i] <=> *(array + i)

	//int x = 11, y = 22;
	//
	//cout << " x = " << x << " y = " << y << endl;

	//swap(x, y);

	//cout << " x = " << x << " y = " << y << endl;
	//int* px = &x;
	//swap(px, &y);

	//cout << " x = " << x << " y = " << y << endl;

	return 0;
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void inputArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
}

void displayArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}
}

void findMinAndMax(int* array, int n, int& min, int& max)
{
	min = max = 0;

	for (int i = 1; i < n; i++)
	{
		if (array[min] > array[i])
		{
			min = i;
		}

		if (array[max] < array[i])
		{
			max = i;
		}
	}
}