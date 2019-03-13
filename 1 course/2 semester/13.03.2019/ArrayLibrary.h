#pragma once

namespace ArrayExtension
{
	typedef int(*key)(int);
	typedef bool(*Predicate)(int*, int);
	typedef void(*Transform)(int*, int);
	//typedef void(*key1)(int, double);

	int* allocateMemory(int);

	void inputArray(int *, int);

	void randomArray(int *, int);

	void displayArray(int *, int);

	void bubbleSort(int *, int);

	void bubbleSort(int*, int*, int);

	void bubbleSort(int*, int*, int, int*, int);

	void bubbleSort(int *, int, key);
	//void bubbleSort(int *, int, int(*key)(int));

	//void swap(int&, int&);

	int* createKeys(int*, int);

	int* createKeys(int*, int, key);

	int countOfUnitInBinaryPresentation(int);

	int sqr(int);

	template<typename T>
	T max(T x, T y)
	{
		return (x > y) ? x : y;
	}

	template <typename T> 
	void swap(T& x, T& y)
	{
		T t = x;
		x = y;
		y = t;
	}

	int** allocateMemory(int, int*);

	void displayMatrix(int**, int, int*);

}