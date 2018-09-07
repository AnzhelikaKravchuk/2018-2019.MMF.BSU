#include <iostream>

using namespace std;

void Swap(int&, int&);
void Swap(int*, int*);

int* AllocateMemory(int);
void InitArray(int* const, int);
void FreeMemory(int* const);
void DisplayArray(int const* , int);
void RemoveElement(int* const, int&, int);

int main(int argc, const char * argv[])
{
    int n = 20;
    
    int* array = AllocateMemory(n);
    
    InitArray(array, n);
    
    DisplayArray(array, n);
    std::cout << std::endl;
    
    RemoveElement(array, n, 4);
    
    DisplayArray(array, n);
    std::cout << std::endl;
    
    FreeMemory(array);

    return 0;
}


void InitArray(int * const a, int n)
{
    if (n <= 0)
    {
        throw std::out_of_range("Dimension of array must be more zero!");
    }
    
    if (a == nullptr)
    {
        throw std::invalid_argument("Argument is null!");
    }
    
    for (int* p = a; p < a + n; p++)
    {
        *p = rand() % 100;
    }
}

int * AllocateMemory(int n)
{
    if (n <= 0)
    {
        throw std::out_of_range("Dimension of array must be more zero!");
    }
    
    int* a = new int[n];
    
//этот кусочек убрать, была не права! этот тип исключения генерирует сам оператор new!
//    if (a == nullptr)
//    {
//        throw std::bad_alloc();
//    }
    
    return a;
}

void FreeMemory(int* const a)
{
    if (a == nullptr)
    {
        throw std::invalid_argument("Argument is null!");
    }
    
    delete[] a;
}

void DisplayArray(const int * a , int n)
{
    if (n <= 0)
    {
        throw std::out_of_range("Dimension of array must be more zero!");
    }
    
    if (a == nullptr)
    {
        throw std::invalid_argument("Argument is null!");
    }
    
    for (const int* p = a; p < a + n; p++)
    {
        std::cout << *p << " ";
    }
}

void RemoveElement(int * const a, int& n, int k)
{
    if (n <= 0)
    {
        throw std::out_of_range("Dimension of array must be more zero!");
    }
    
    if (k < 0 || k > n)
    {
        throw std::out_of_range("Position  of array must be more than  zero and less then!");
    }
    
    if (a == nullptr)
    {
        throw std::invalid_argument("Argument is null!");
    }
    
    for (int i = k; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }
    
    n--;
}

void Swap(int& a, int& b)
{
    int t = a;
    a = b;
    b = t;
}

void Swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}