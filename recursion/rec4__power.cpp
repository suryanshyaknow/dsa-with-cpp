#include <iostream>
using namespace std;

int power(int, int);

int main()
{
    int b, n;
    cout << "Enter Base and Power(to be raised) respectively: " << endl;
    cin >> b >> n;

    cout << "Result: " << power(3, 4);

    return 0;
}

int power(int base, int pow)
{
    if (pow == 0)
    {
        return 1;
    }
    else
    {
        return(power(base, pow-1) * base);
    }
}