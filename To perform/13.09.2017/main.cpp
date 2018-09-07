#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    cout << "Enter point:" << endl;
    cout << "x = ";
    cin >> x;
    cout << "y = ";
    cin >> y;
    
    // v 1.0 bad
//    if (y < -0.5)
//    {
//        cout << "( " << x << " , " << y << " ) doesn`t be long" << endl;
//        return 0;
//    }
//    
//    if (x <= 1)
//    {
//        if (y <= x)
//        {
//            cout << "( " << x << " , " << y << " ) be long" << endl;
//            return 0;
//        }
//        else
//        {
//            cout << "( " << x << " , " << y << " ) doesn`t be long" << endl;
//            return 0;
//        }
//    }
//    else
//    {
//        if ((x - 1) * (x - 1) + y * y <= 1)
//        {
//            cout << "( " << x << " , " << y << " ) be long" << endl;
//            //return 0;
//        }
//        else
//        {
//            cout << "( " << x << " , " << y << " ) doesn`t be long" << endl;
//            return 0;
//        }
//    }
    // v 2.0
    bool result = true;
    
    if (y < -0.5)
    {
        result = false;
    }
    
    if (x <= 1)
    {
        if (y > x)
        {
            result = false;
        }
    }
    else
    {
        if ((x - 1) * (x - 1) + y * y > 1)
        {
            result = false;
        }
    }
    
    if (result)
    {
        cout << "( " << x << " , " << y << " ) be long" << endl;
    }
    else
    {
        cout << "( " << x << " , " << y << " ) doesn`t be long" << endl;
    }
    //v 3.0
    if (y >= -0.5)
    {
        if (x <= 1)
        {
            if (y > x)
            {
                result = false;
            }
        }
        else
        {
            if ((x - 1) * (x - 1) + y * y > 1)
            {
                result = false;
            }
        }
    }
    
    return 0;
}
