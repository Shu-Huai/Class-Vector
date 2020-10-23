#include"Class Vector.h"
#include <iostream>
using namespace std;
int main()
{
    int a[4] = { 1, 3, 5, 7 };
    int b[4] = { 2, 4, 6, 8 };
    Vector<int> test0(a, 4), test1(b, 4);
    double c[4] = { 1.1, 2.2, 3.3, 4.4 };
    Vector<double> test2(c, 4);
    cout << "test0: " << endl
        << test0 << "test1: " << endl
        << test1 << "test2: " << endl
        << test2
        << "Assign test0 to test1. " << endl
        << "test1: " << endl;
    test1 = test0;
    cout << test1 << "Whether test0 == test1: " << boolalpha << (test0 == test1) << endl
        << "Whether test0 != test1: " << boolalpha << (test0 != test1) << endl
        << "The dimension of test0 is: " << test0.GetDimension() << endl;
    cout << "test0 = test0 + test1. " << endl;
    try
    {
        test0 = test0 + test1;
        cout << test0;
    }
    catch (int)
    {
        cout << "The dimension of test0 and test1 are not the same. " << endl;
    }
    cout << "Resize test0. Please input the dimension: ";
    int di = 0;
    cin >> di;
    test0.Resize(di);
    cout << "test0: " << endl
        << test0 << "test0 += test1. " << endl;
    try
    {
        test0 += test1;
        cout << test0;
    }
    catch (int)
    {
        cout << "The dimension of test0 and test1 are not the same. " << endl;
    }
    cin >> test0;
    cout << test0;
    for (int i = 0; i < 2; i++)
    {
        cout << "Get the length on one of the dimension of test0. Please input the number of the dimension: ";
        cin >> di;
        try
        {
            cout << "The length is: " << test0[di] << endl;
        }
        catch (int& index)
        {
            cout << "Test0 does not have " << index + 1 << " dimensions" << endl;
        }
    }
    return 0;
}