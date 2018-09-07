#include<iostream>

using namespace std;

int main()
{
	//loops counter - i, j, k, l (integer)
	//dimentions - n, m (integer)
	int n;
	char ok = 'y';
	int const N = 100;

	while (ok == 'y' || ok == 'Y')
	{
		while (true)
		{
			cout << " Enter n <= " << N;
			cin >> n;
			if (n > 0 && n <= N)
				break;
			else
				cout << "Invalid data!" << endl;
		}
		//variant 1
		int i = 1;
		int sum = 0;

		while (i <= n)
		{
			//sum = sum + i;
			// vs 
			sum += i;
			//i = i + 1;
			//vs
			//i += 1;
			//vs
			//i++;//postfix form increament
			//vs
			++i;//prefix form increament
		}

		cout << "1 + 2 + 3 + ... + " << n << " = " << sum << endl;
		
		for (int j = 1; j <= n ; j++)
		{
			sum += j;
		}
		//vs
		/*int j = 1;
		for ( ; ; )
		{
			if (j <= n) break;
			sum += j;
			j++;
		}*/

		cout << "1 + 2 + 3 + ... + " << n << " = " << sum << endl;
		//about increament forms
		//int j = 1, k = 1;
		//int l = ++j;
		//int m = k++;

		cout << "If continue, press y or Y";
		cin >> ok;
	}



	return 0;
}
