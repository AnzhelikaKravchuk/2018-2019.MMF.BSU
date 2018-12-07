#pragma once

#include<iostream>

using namespace std;

const int M = 100;

void swap(int&, int&);

void initMatrix(int[][M], int, int);

void displayMatrix(int[][M], int, int);

void transpose(int [][M], int);

void initMatrix(int a[][M], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			//cout << "a[" << i + 1 << "," << j + 1 << "] = ";
			//cin >> a[i][j];
			a[i][j] = i + 1;
		}
	}
}

void displayMatrix(int a[][M], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout.width(5);
			cout << a[i][j];
		}

		cout << endl;
	}
}

void transpose(int a[][M], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			swap(a[i][j], a[j][i]);
		}
	}
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void swap(int[], int[], int);

void bubbleSort(int[][M], int*, int, int);

void createKeys(int[][M], int, int, int*);

int findMax(int*, int);

void createKeys(int a[][M], int n, int m, int* keys)
{
	for (int i = 0; i < n; i++)
	{
		/*int k = 0;
		for (int j = 0; j < m; j++)
		{
			if (a[i][j] > a[i][k])
			{
				k = j;
			}
		}
		keys[i] = a[i][k];
		*/
		keys[i] = findMax(a[i], m);
	}
}

int findMax(int* array, int n)
{
	int k = 0;
	for (int j = 1; j < n; j++)
	{
		if (array[j] > array[k])
		{
			k = j;
		}
	}

	return array[k];
}

void bubbleSort(int matrix[][M], int* keys, int n, int m)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (keys[j] < keys[j - 1])
			{			
				/*for (int k = 0; k < m; k++)
				{
					swap(matrix[j][k], matrix[j - 1][k]);
				}*/
				swap(matrix[j], matrix[j - 1], m);
				swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void swap(int left[], int right[], int n)
{
	for (int i = 0; i < n; i++)
	{
		swap(left[i], right[i]);
	}
}