#pragma once

#ifdef MATHLIBRARY_EXPORTS
#define MATHLIBRARY_API __declspec(dllexport) 
#else
#define MATHLIBRARY_API __declspec(dllimport) 
#endif

namespace StringExtention
{
	MATHLIBRARY_API char** ObtainWords(char*, int&);
	MATHLIBRARY_API char** ObtainWordsAgain(char*, int&);
	MATHLIBRARY_API void SortingWords(char**, int);
	MATHLIBRARY_API void DisplayWords(char**, int);
	void Swap(char* &, char* &);
	MATHLIBRARY_API void FreeHeap(char**, int);
}