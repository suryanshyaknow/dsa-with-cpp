#include <iostream>
using namespace std;

//*********************** Factorial *************************************
// The simplest case of Reursion

int factorial(int n);

int main()
{
    int num;

    cout << "Enter the number of which factorial is to be found: " << endl;
    cin >> num;

    cout << "The factorial of the " << num << " is: " << factorial(num) << endl;

    return 0;
}

int factorial(int n)
{
    if (n > 1)
    {
        return n * factorial(n - 1);
        // return factorial(n - 1) * n;
        // either way the control will be returned firstly to the recursive call
    }
    else
    {
        return 1;
    }
    
}