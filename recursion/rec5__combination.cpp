#include <iostream>
using namespace std;

int combination(int, int);

int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
        // return factorial(n - 1) * n;
        // either way the control will be returned first and foremost to the recursive call
    }
    else
    {
        return 1;
    }
}

int main()
{
    int n = 0, r = 0;
    cout << "Enter the total number of items, N:" << n << endl;
    cin >> n;
    cout << "Enter the number of items to be selected, R:" << r << endl;
    cin >> r;

    cout << "Number of desired combinations: " << combination(n, r) << endl;
    return 0;
}

int combination(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}