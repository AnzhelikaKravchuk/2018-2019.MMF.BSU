#include "ArrayLibrary.h"
#include <iostream>

//using namespace ArrayExtension;

void foo(const int &a)
{
	//a = 67;
}

void boo(int &a)
{
	a = 90;
}

int cube(int);

int main()
{
	int x = 90;

	const int y = 100;

	int n = 20;

	int* array = nullptr;

	try
	{
		array = ArrayExtension::allocateMemory(n);
	}
	catch (const std::invalid_argument& ex) 
	{
		std::cerr << "Invalid argument: " << ex.what() << '\n';
	}

	ArrayExtension::randomArray(array, n);

	std::cout << "Source array" << std::endl;

	ArrayExtension::displayArray(array, n);

	ArrayExtension::bubbleSort(array, n, cube);

	std::cout << "Sorted array" << std::endl;

	ArrayExtension::displayArray(array, n);

	int* keys = ArrayExtension::createKeys(array, n);

	ArrayExtension::bubbleSort(array, keys, n);

	std::cout << "Sorted array" << std::endl;

	ArrayExtension::displayArray(array, n);

	int m = 10;

	int* indexes = new int[m]{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };//input

	keys = ArrayExtension::createKeys(array, n, ArrayExtension::countOfUnitInBinaryPresentation);

	ArrayExtension::bubbleSort(array, keys, n, indexes, m);

	std::cout << "Sorted array" << std::endl;

	ArrayExtension::displayArray(array, n);

	ArrayExtension::key key = cube;

	std::cout << cube(4) << std::endl;

	std::cout << key(4) << std::endl;

	key = ArrayExtension::sqr;

	std::cout << ArrayExtension::sqr(4) << std::endl;

	std::cout << key(4) << std::endl;

	int(*entryPoint)()  = main;// <=> &main

	system("pause");

	//entryPoint();

	return 0;
}

int cube (int number)
{
	return number * number * number;
}