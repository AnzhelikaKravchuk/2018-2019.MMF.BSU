#include "stdafx.h"
#include "CppUnitTest.h"
#include <cmath>
#include<iostream>
#include "MathLibrary.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MathLibraryTests
{		
	TEST_CLASS(MathExtensionTests)
	{
	public:
		
		TEST_METHOD(sinTylorTest_1)
		{
			//Arrange
			double epsilon = 0.000001;
			double x = 0.127;
			double expected = sin(x);

			//Act
			double actual = Math::SinTaylor(x, epsilon);

			//Assert
			//Assert::IsTrue(fabs(expected - actual) < epsilon);

			//Fail assert!
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(sinTylorTest_2)
		{
			double epsilon = 0.000000001;
			double x = -12.56;
			double expected = sin(x);

			double actual = Math::SinTaylor(x, epsilon);

			Assert::IsTrue(fabs(expected - actual) < epsilon);
		}

		//etc.

	};
}