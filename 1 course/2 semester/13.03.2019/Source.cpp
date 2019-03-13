#define _CRT_SECURE_NO_WARNINGS

#include "ArrayLibrary.h"
#include <iostream>
using namespace std;

using namespace ArrayExtension;
char** ObtainWords(char * source, int & n);
char** ObtainWordsAgain(char* source, int& n);
void FreeHeap(char** words, int n);
void DisplayWords(char** words, int n);
void SortingWords(char** words, int n);
void Swap(char* &x, char* &y);
char* deleteWordsWithLength(char* source, int n);

int cube(int);

int main()
{
	int* a = new int[10];

	Transform* transformers = new Transform[4]{ randomArray, displayArray, bubbleSort, displayArray};
	
	for (int i = 0; i < 3; i++)
	{
		transformers[i](a, 10);
	}

	cout << max(19, 20) << endl;
	cout << max('a', 'b') << endl;
	cout << max(12.456, 34.67) << endl;
	system("pause");
	return 0;
	int countOfRows = 10;

	int* dimentions = allocateMemory(countOfRows);
	
	randomArray(dimentions, countOfRows);

	const int LENGTH = 256;
	char str[LENGTH] = "	The   ???  usual form of input, 098 -1  =+   For most statistical functions is a list of data... 89 Form. ";
	//cout << "Enter the string: ";
	//cin.getline(str, LENGTH, '\n');
	system("cls");
	cout << endl << "\tSTRING IS:" << endl;
	cout << str;
	cout << deleteWordsWithLength(str,4) << endl;
	system("pause");
	return 0;
	int n = 0;
	char** arrayWords = ObtainWords(str, n);
	cout << endl << "\tARRAY OF WORDS" << endl;
	DisplayWords(arrayWords, n);
	SortingWords(arrayWords, n);
	std::cout << endl << "\tNEW ARRAY OF WORDS" << endl;
	DisplayWords(arrayWords, n);
	FreeHeap(arrayWords, n);
	ArrayExtension::key funPtr= &cube;

	cube(2);
	funPtr(2);
	//std::cout << main << &main << std::endl;
	int *  array = nullptr;

	//int n = -20;

	try
	{
		array = ArrayExtension::allocateMemory(n);
	}
	catch (const std::invalid_argument& ex) 
	{
		std::cerr << "Invalid argument: " << ex.what() << '\n';
		system("pause");
		return 0;
	}
	catch(const std::exception& ex)
	{
		std::cerr << "Invalid argument !!!!!!!!!!: " << ex.what() << '\n';
		system("pause");
		return 0;
	}
	//array = nullptr;
	ArrayExtension::randomArray(array, n);

	std::cout << "Source array" << std::endl;

	ArrayExtension::displayArray(array, n);

	ArrayExtension::bubbleSort(array, n, &cube);

	std::cout << "Sorted array" << std::endl;

	ArrayExtension::displayArray(array, n);

	int* keys = ArrayExtension::createKeys(array, n, ArrayExtension::sqr);

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

	entryPoint();

	return 0;
}

int cube (int number)
{
	return number * number * number;
}

char** ObtainWords(char * source, int & n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	char** words = new char*[strlen(copy) / 2];
	n = 0;
	const char* symbols = "	1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
	char* pword = strtok(copy, symbols);
	words[n] = new char[strlen(pword) + 1];
	strcpy(words[n], pword);

	n++;
	while (pword)
	{
		pword = strtok('\0', symbols);
		if (pword)
		{
			words[n] = new char[strlen(pword) + 1];
			strcpy(words[n], pword);
			n++;
		}
	}

	delete[] copy;
	return words;
}

char** ObtainWordsAgain(char* source, int& n)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char*[strlen(source) / 2];

	n = 0;
	char* pword = strpbrk(source, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);
		words[n] = new char[length + 1];
		strncpy(words[n], pword, length);
		words[n][length] = '\0';
		pword += length;
		pword = strpbrk(pword, symbols);
		n++;
	}

	return words;
}

void DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << (i + 1) << ". " << words[i] << std::endl;
}

void FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
		delete[] words[i];
	delete[] words;
}

void SortingWords(char** words, int n)
{
	for (int i = 0; i < n; i++)//!!!!Optimization!!!!!
		for (int j = n - 1; j > i; j--)
			if (strcmp(words[j], words[j - 1]) < 0)
				Swap(words[j], words[j - 1]);
}

void Swap(char* &x, char* &y)
{
	char* temp = x;
	x = y;
	y = temp;
}

char* deleteWordsWithLength(char* source, int n)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);
	char* pword = strpbrk(copy, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);

		char* hlp = nullptr;
		if (length == n)
		{
			//hlp = new char[strlen(source) + 1];
			//strcpy(hlp, pword + length);
			strcpy(pword, pword + length);
		}
		else
		{
			pword += length;
		}

		delete[] hlp;

		pword = strpbrk(pword, symbols);
	}

	return copy;
}
