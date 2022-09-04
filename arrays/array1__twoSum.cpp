#include <iostream>
using namespace std;

// Given an array A[] and a number x, check for pair in A[] with sum as x (aka Two Sum)

bool chk_twoSum(int a[], int len, int x)
{
    // int len;
    // len = sizeof(a) / sizeof(a[0]);
    
    // Note: We gotta pass the number of elements of an array while passing it because function wouldn't know the same shit. 
    for (int i = 0; i < (len-1); i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[i] + a[j] == x)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // int A[] = {1, 4, 45, 6, 10, 8}, x = 16;
    int A[] = {0, -1, 2, -3, 1}, x = -2;

    int len = sizeof(A)/sizeof(A[0]); // length of an array

    if (chk_twoSum(A, len, x))
    {
        cout << "Valid pair exists!" << endl;
    }
    else
    {
        cout << "No such pair exists!" << endl;
    }

    return 0;
}