#include "stdafx.h"
#include "Strings.h"
#include <ostream>
#include <iostream>
using namespace StringExtention;

char** StringExtention::ObtainWords(char * source, int & n)
{
	char* copy = new char[strlen(source) + 1];
	strcpy(copy, source);

	char** words = new char*[strlen(copy) / 2];
	n = 0;
	char* symbols = "	1234567890-=!@#$%^&*()_+{}|][:;'<>?/., \x22";
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

char** StringExtention::ObtainWordsAgain(char* source, int& n)
{
	char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char*[strlen(source) / 2];

	n = 0;
	char* pword = strpbrk(source,symbols);
	while(pword)
	{
		int length = strspn(pword,symbols);
		words[n] = new char[length + 1];
		strncpy(words[n],pword,length);
		words[n][length] = '\0';
		pword += length;
		pword = strpbrk(pword,symbols);
		n++;
	}

	return words;
}  

void StringExtention::DisplayWords(char** words, int n)
{
	for (int i = 0; i < n; i++)
		std::cout << (i + 1) << ". " << words[i] << std::endl;
}

void StringExtention::FreeHeap(char** words, int n)
{
	for (int i = 0; i < n; i++)
		delete[] words[i];
	delete[] words;
}

void StringExtention::SortingWords(char** words, int n)
{
	for (int i = 0; i < n; i++)//!!!!Optimization!!!!!
		for (int j = n - 1; j > i; j--)
			if (stricmp(words[j], words[j - 1]) < 0)
				Swap(words[j], words[j - 1]);
}

void StringExtention::Swap(char* &x, char* &y)
{
	char* temp = x;
	x = y;
	y = temp;
}