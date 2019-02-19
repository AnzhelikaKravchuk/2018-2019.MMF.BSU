#pragma once

namespace ArrayExtension
{
	typedef int(*key)(int);

	int* allocateMemory(int);

	void inputArray(int *, int);

	void randomArray(int *, int);

	void displayArray(int *, int);

	void bubbleSort(int *, int);

	void bubbleSort(int*, int*, int);

	void bubbleSort(int*, int*, int, int*, int);

	void bubbleSort(int *, int, key);
	//void bubbleSort(int *, int, int(*key)(int));

	void swap(int&, int&);

	int* createKeys(int*, int);

	int* createKeys(int*, int, key);

	int countOfUnitInBinaryPresentation(int);

	int sqr(int);
}