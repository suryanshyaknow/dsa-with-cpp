#include <iostream>
using namespace std;

// Find the Number Occurring Odd Number of Times
/* Given an array of positive integers. All numbers occur an even number of times except one number which occurs
an odd number of times.
*/

int oddTimesOut(int a[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int count = 1;
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] == a[i])
            {
                count+=1;                
            }
        }
        if (count%2 != 0){
            return a[i];
        }
    }
    return -1;
}

int main()
{
    int A[] = {1, 2, 3, 2, 3, 1, 3};
    int len = sizeof(A) / sizeof(A[0]);

    cout << "The element that occurs odd number of times in the given array_A: " << oddTimesOut(A, len) << endl;

    int B[] = {5, 7, 2, 7, 5, 2, 5};
    int len_b = sizeof(A) / sizeof(A[0]);

    cout << "The element that occurs odd number of times in the array_B: " << oddTimesOut(B, len_b) << endl;
    cout << INT_MIN << endl;

    return -1;
}