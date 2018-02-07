// ConsoleClient.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "MathLibrary.h"
#include <iostream>

double accurancyDefine();

int main()
{
	double x, epsilon = accurancyDefine();

	std::cout << "Enter x ";
	std::cin >> x;
	system("cls");

	std::cout << "sum = " << Math::SinTaylor(x, epsilon) << std::endl;
	std::cout << "sin = " << sin(x) << std::endl;

	system("pause");
    return 0;
}

double accurancyDefine()
{
	double accurancy;

	while (true)
	{
		std::cout << "Enter 0 < epsilon < 1 :";//<- Scope Resolution Operator
		std::cin >> accurancy;
		if (accurancy > 0 && accurancy < 1)
		{
			break;
		}
		std::cout << "Invalid data! Try again!";
		system("pause");
		system("cls");
	}

	return accurancy;
}

