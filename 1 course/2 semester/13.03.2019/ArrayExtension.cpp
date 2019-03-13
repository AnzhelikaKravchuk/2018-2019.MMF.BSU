#include <iostream>
#include "ArrayLibrary.h"

using namespace std;

int* ArrayExtension::allocateMemory(int n)
{
	if (n <= 0)
	{
		//return nullptr;
		//http://www.cplusplus.com/reference/exception/exception/
		throw std::out_of_range("Count of array elements can not be less or equal 0.");
	}

	int* array = new int[n];

	return array;
}

void ArrayExtension::inputArray(int * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int* p = array, i = 1; p < array + n; p++, i++)
	{
		std::cout << "a[" << i << "] = ";
		std::cin >> *p;

	}
}

void ArrayExtension::randomArray(int * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int* p = array, i = 1; p < array + n; p++, i++)
	{
		*p = rand() % 20 - 9;
	}
}

void ArrayExtension::displayArray(int * array, int n)
{
	if (array == nullptr)
	{
		throw std::invalid_argument("Array can not be null.");
	}

	if (n <= 0)
	{
		throw std::invalid_argument("Count of array elements can not be less or equal 0.");
	}

	for (int* p = array; p < array + n; p++)
	{
		std::cout << *p << " ";
	}

	std::cout << std::endl;
}

int* ArrayExtension::createKeys(int* array, int n)
{
	int* keys = ArrayExtension::allocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		keys[i] = sqr(array[i]);
	}

	return keys;
}

int * ArrayExtension::createKeys(int * array, int n, key key)
{
	int* keys = ArrayExtension::allocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		keys[i] = key(array[i]);
	}

	return keys;
}

//void ArrayExtension::swap(int& a, int& b)
//{
//	int t = a;
//	a = b;
//	b = t;
//}

int ArrayExtension::countOfUnitInBinaryPresentation(int number)
{
	int k = 0;

	number = abs(number);

	while (number)
	{
		int rest = number % 2;

		if (rest == 1)
		{
			k++;
		}

		number /= 2;
	}

	return k;
}

void ArrayExtension::bubbleSort(int* array, int n)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int* keys, int n)
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
				ArrayExtension::swap(array[j], array[j - 1]);
				ArrayExtension::swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int* keys, int n, int* indexes, int m)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = m - 1; j >= i; j--)
		{
			if (keys[indexes[j]] < keys[indexes[j - 1]])
			{
				ArrayExtension::swap(array[indexes[j]], array[indexes[j - 1]]);
				ArrayExtension::swap(keys[indexes[j]], keys[indexes[j - 1]]);
				swapped = true;
			}
		}

		i++;
	}
}

void ArrayExtension::bubbleSort(int* array, int n, key key)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{
		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (key(array[j]) < key(array[j - 1]))
			{
				ArrayExtension::swap(array[j], array[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

int ArrayExtension::sqr(int number)
{
	return number * number;
}

int** ArrayExtension::allocateMemory(int n, int* dimentions)
{
	// validation!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	int** matrix = new int*[n];

	for (int i = 0; i < n; i++)
	{
		matrix[i] = new int[dimentions[i]];
	}

	return matrix;
}

void ArrayExtension::displayMatrix(int** matrix, int rows, int* dimentions)
{
	// validation!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	for (int i = 0; i < rows; i++)
	{
		displayArray(matrix[i], dimentions[i]);
		std::cout << std::endl;
	}

}

//int** ArrayExtension::foo(int** matrix, int rows, int* dimentions, Predicate predicate, Transform*)
//{
//	// validation!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
//
//	for (int i = 0; i < rows; i++)
//	{
//		displayArray(matrix[i], dimentions[i]);
//		std::cout << std::endl;
//	}
//
//}