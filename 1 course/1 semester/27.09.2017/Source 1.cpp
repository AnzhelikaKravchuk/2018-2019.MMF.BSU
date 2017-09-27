#include <iostream>

using namespace std;

int main()
{
	double a, b, c;
	char ok = 'y';
	while (ok == 'y' || ok == 'Y')
	{
		while (true)
		{
			cout << " a = ";
			cin >> a;
			if (a != 0) 
				break;
			else cout << "Invalid data!" << endl;
		}

		cout << " b = ";
		cin >> b;
		cout << " c = ";
		cin >> c;

		double d = b * b - 4 * a * c;

		if (d > 0)
		{
			cout << "x1 = " << (-b + sqrt(d)) / 2 / a << endl;
			cout << "x2 = " << (-b - sqrt(d)) / 2 / a << endl;
		}
		else if (d == 0)
		{
			cout << "x1 = x2 = " << -b / 2 / a << endl;
		}
		else
		{
			cout << "no real roots!" << endl;
		}
		cout << "If continue, press y or Y";
		cin >> ok;
	}
	
	return 0;
}