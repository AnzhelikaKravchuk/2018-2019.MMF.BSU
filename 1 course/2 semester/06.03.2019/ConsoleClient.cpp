// ConsoleClient.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "MathLibrary.h"
#include"StudentSystem.h"
#include "Strings.h"
#include <iostream>

using namespace std;
using namespace Math;
using namespace StudentLibrary;

void Display(const Student&);
void BadDisplay(Student);
Student InitStudent();
Course InitCourse(int);


int main()
{

	const int LENGTH = 256;
	char str[LENGTH] = "	The   ???  usual form of input, 098 -1  =+   For most statistical functions is a list of data... 89 Form. ";
	//cout << "Enter the string: ";
	//cin.getline(str, LENGTH, '\n');
	system("cls");
	cout << endl << "\tSTRING IS:" << endl;
	cout << str;
	int n = 0;
	char** arrayWords = StringExtention::ObtainWordsAgain(str, n);
	cout << endl << "\tARRAY OF WORDS" << endl;
	StringExtention::DisplayWords(arrayWords, n);
	StringExtention::SortingWords(arrayWords, n);
	cout << endl << "\tNEW ARRAY OF WORDS" << endl;
	StringExtention::DisplayWords(arrayWords, n);
	StringExtention::FreeHeap(arrayWords, n);
	/*int arr[] = { 12, 45, 67, 67, 7, 77, 3224 };
	Array array(arr, 7);
	arr[0] = -900;
	array.Show();
	int* a = array.CopyToArray();
	a[0] = -123;
	array.Show();*/
	//Student student = InitStudent();
	//student.GetFirstName();<=>student.GetFirstName(&student)
	//	GetFirstName(Student* this)
	//Student* ps = new Student;
	//Student st(student);
	//Student student1 = student;
	//char * temp = student.GetFirstName();
	//temp[3] = '2';
	//strcpy(temp, student.GetFirstName());
	//cout << temp << endl;
	//Display(student);
	//BadDisplay(student);
	//Student student2 = InitStudent();
	//student2 = student;
	//student2.operator=(student);
	//Display(student);
	//cout << Student::CountStudents() << endl;
	cout << endl;
	system("pause");
	return 0;
}

void Display(const Student& student)
{
	cout << student.GetId() << ". ";
	cout << student.GetFirstName() << " " << student.GetLastName() << ".";
	cout << " Course: " << student.GetCourse() << ". ";
	cout << " Average mark: " << student.GetAverageMark() << ". ";
}

void BadDisplay(Student student)
{
	cout << student.GetId() << ". ";
	cout << student.GetFirstName() << " " << student.GetLastName() << ".";
	cout << " Course: " << student.GetCourse() << ". ";
	cout << " Average mark: " << student.GetAverageMark() << ". ";
}

Student InitStudent()
{
	int n = 256;
	char* fn = new char[n];
	cout << "Enter first name of student:";
	cin.getline(fn, n, '\n');

	char* ln = new char[n];
	cout << "Enter last name of student:";
	cin.getline(ln, n, '\n');

	char* fc = new char[n];
	cout << "Enter faculty:";
	cin.getline(fc, n, '\n');

	int k;
	cout << "Enter course:";
	cin >> k;

	int l;
	cout << "Enter count of marks:";
	cin >> l;

	int* mrks = new int[l];

	cout << "Enter marks:";

	for (size_t i = 0; i < l; i++)
	{
		cout << (i + 1) << " : ";
		cin >> mrks[i];
	}
	Student student(fn, ln, fc, InitCourse(k), mrks, l);
	return student;
}

Course InitCourse(int k)
{
	Course course;
	switch (k)
	{
	case 1:
		course = Course::first;
		break;
	case 2:
		course = Course::second;
		break;
	case 3:
		course = Course::third;
		break;
	case 4:
		course = Course::fourth;
		break;
	default:
		throw std::invalid_argument("Invalid course!");
		break;
	}
}

