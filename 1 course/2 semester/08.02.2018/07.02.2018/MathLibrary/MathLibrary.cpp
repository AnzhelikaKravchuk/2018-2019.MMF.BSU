// MathLibrary.cpp : Defines the exported functions for the DLL application.

#include "stdafx.h"
#include <cmath>
#include "MathLibrary.h"

MATHLIBRARY_API double Math::SinTaylor(double value, double accurancy)
{
	double term = value, sum = 0;

	for (int i = 1; fabs(term) > accurancy; i++)
	{
		sum += term;
		term = -term * value * value / (2 * i) / (2 * i + 1);
	}

	return sum;
}
