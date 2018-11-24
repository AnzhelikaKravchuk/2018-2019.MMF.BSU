#include<iostream>

using namespace std;

void swap(int&, int&);
void abs(int*, int);
void copyTo(int*, int*, int);
int inputDimension(int);
void swap(int*, int*);
void inputArray(int*, int);
void randomArray(int*, int, int);
void generatorArray(int*, int, int, int);
void displayArray(int*, int);
void findMinAndMax(int*, int, int&, int&);
void bubbleSort(int*, int);
void bubbleSort(int*, int*, int);
void selectionSort(int*, int);
void insertionSort(int*, int);
void shiftRightElement(int*, int);
void shiftRightElement(int *, int, int);
int searchCountDifferentElements(int*, int);
void merge(int*, int, int*, int, int*, int);

//int[] -1, 4, 5, -78, 56 values
//int[]  1, 4, 5, 78, 56 keys abs

//int[] -1, 4, 5, -78, 56 values
//int[] 2, 1, 2, 0, 2 keys (% 3)

int main()
{
	const int N = 100;// max dimension

	int arrayA[N] = { 0 };// { 1, 2, 3, 1, 4, 5, 4, 3, 2, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 3 };
	
	int arrayB[N] = { 0 };
	
	int n = inputDimension(N);
	int m = inputDimension(N);//real dimension

	randomArray(arrayA, n, 20);
	randomArray(arrayB, n, 100);

	cout << "Source array A" << endl;
	bubbleSort(arrayA, n);
	int arrayAKeys[N] = { 0 };
	copyTo(arrayA, arrayAKeys, n);
	abs(arrayAKeys, n);
	bubbleSort(arrayA, arrayAKeys, n);
	displayArray(arrayA, n);

	cout << "Source array B" << endl;
	bubbleSort(arrayB, m);
	displayArray(arrayB, m);

	int arrayC[2 * N] = { 0 };
	int k = n + m;

	merge(arrayA, n, arrayB, m, arrayC, k);
	displayArray(arrayC, k);
	//bubbleSort(array, n);

	//cout << "\nSorted array" << endl;
	//displayArray(array, n);*/

	//generatorArray(array, n, 4, 2);

	//displayArray(array, n);

	//shiftRightElement(array, n, 5);
	//cout << "Different elements: " << searchCountDifferentElements(array, n);

	cout << endl;

	system("pause");
	return 0;
}

void swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}

void inputArray(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "[" << i + 1 << "] : ";
		cin >> array[i];
	}
}

void displayArray(int* array, int n)
{
	if (array == nullptr)
	{
		cout << "Invalid data!" << endl;
		return;
	}

	if (n <= 0)
	{
		cout << "Invalid data!" << endl;
		return;
	}


	for (int i = 0; i < n; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;

}

void findMinAndMax(int* array, int n, int& min, int& max)
{
	min = max = 0;

	for (int i = 1; i < n; i++)
	{
		if (array[min] > array[i])
		{
			min = i;
		}

		if (array[max] < array[i])
		{
			max = i;
		}
	}
}

void bubbleSort(int * array, int n)
{
	// O(n^2) - any case - sorted!
	/*for (int i = 1; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
			}
		}
	}*/

	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (array[j] < array[j - 1])
			{
				swap(array[j], array[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void randomArray(int * array, int n, int max)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % max - max / 2;//<- 0..max
	}
}

void selectionSort(int * array, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;

		for (int j = i + 1; j < n; j++)
		{
			if (array[min] > array[j])
			{
				min = j;
			}
		}

		swap(array[min], array[i]);
	}
}

void insertionSort(int * array, int n)
{
	for (int i = 0; i < n; i++)
	{

	}
}

void shiftRightElement(int * array, int n)
{
	int temp = array[n - 1];

	for (int i = n - 1; i >= 1; i--)
	{
		array[i] = array[i - 1];
	}

	array[0] = temp;
}

void shiftRightElement(int * array, int n, int count)
{
	for (int i = 1; i <= count; i++)
	{
		shiftRightElement(array, n);
	}
}

void generatorArray(int* array, int n, int start, int step)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = start;
		start += step;
	}
}

int searchCountDifferentElements(int* array, int n)
{
	int count = n;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (array[i] == array[j])// double !!! fabs(array[i] - array[j])<=epsilon
			{
				count--;
				break;
			}
		}
	}

	return count;
}

// 1 2 3 1 4 5 4 3 2 1 0 0 0 0 0 0 0 0 0 1 1 1 3

int inputDimension(int dimension)
{

	int n;

	while (true)
	{
		cout << "Enter dimension of array <= " << dimension << " :";
		cin >> n;
		if (n >= 1 && n <= dimension)
		{
			break;
		}

		cout << "Invalid data!";
	}

	return n;
}

void merge(int* arrayA, int n, int* arrayB, int m, int* arrayC, int k)
{
	int i = 0, j = 0, l = 0;

	while ( i < n && j < m )
	{
		if (arrayA[i] < arrayB[j])
		{
			arrayC[l] = arrayA[i];
			i++;
		}
		else
		{
			arrayC[l] = arrayB[j];
			j++;
		}

		l++;
	}

	if (i == n)
	{
		for (; j < m; j++, l++)
		{
			arrayC[l] = arrayB[j];
		}
	}
	else
	{
		for (; i < n; i++, l++)
		{
			arrayC[l] = arrayA[i];
		}
	}
}

void bubbleSort(int* values, int* keys, int n)
{
	bool swapped = true;

	int i = 1;

	while (swapped)
	{

		swapped = false;

		for (int j = n - 1; j >= i; j--)
		{
			if (keys[j] < keys[j - 1])
			{
				swap(values[j], values[j - 1]);
				swap(keys[j], keys[j - 1]);
				swapped = true;
			}
		}

		i++;
	}
}

void abs(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = abs(array[i]);
	}
}

void copyTo(int* source, int* destination, int n)
{
	for (int i = 0; i < n; i++)
	{
		destination[i] = source[i];
	}
}