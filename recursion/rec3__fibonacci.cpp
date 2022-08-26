#include <iostream>
using namespace std;

// 1. Print out the Fibonacci Series.
// 2. Sum of the Fibonacci Sequence up to a desired nth val.
// 3. Print out all the fibonacci temrs that are less than day, 200.

int fib(int);      // function to print out the nth number of the Fibonacci Sequence
void genFib(int);  // function to generate the Fibonacci Sequence up to a desired number of terms
int sumFib(int);   // function to sum the Fibonacci Sequence up to a nth term
// void consFib(int constraint = 100); // function to put some sort of constraint on the fibonacci sequence

void consFib(int constraint = 100)
{
    for (int i = 0; i >= 0; i++)
    {
        if (fib(i) >= constraint)
        {
            break;
        }
        cout << fib(i) << endl;
    }
}

int main()
{
    int n;
    cout << "Enter the number of terms you want in your Fibonacci sequence: " << endl;
    cin >> n;

    // printing out the fibonacci sequence
    genFib(n);

    // summing the terms of the fibonacci series
    cout << "The sum of the sequence of the Fibonacci sequence up to " << n << " number of terms is "
         << sumFib(n);

    // printing out the values of the fibonacci sequence that are less than 200
    consFib(900);

    return 0;
}

int fib(int num)
{
    if (num == 0 || num == 1)
    {
        return num;
    }
    else
    {
        return fib(num - 2) + fib(num - 1);
    }
}

void genFib(int n)
{
    int i = 1;
    while (i <= n)
    {
        if (i != n)
        {
            cout << fib(i) << ", ";
        }
        else
        {
            cout << fib(i) << endl;
        }
        i++;
    }
}

int sumFib(int n)
{
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += fib(i);
    }
    return sum;
}