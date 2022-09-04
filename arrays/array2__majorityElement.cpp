#include <iostream>
using namespace std;

// Find the majority element in the array.
/* A majority element in an array A[] of size n is an element that appears more than n/2 times
(and hence there is at most one such element). */

int majEle(int a[], int len) // majority element function
{
    int n_maj = len / 2; // number of times for an element to be appear more than, to be the majority element
    cout << n_maj << endl;

    int count = 1;

    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (a[j] == a[i])
            {
                count++;
            }
        }

        cout << "count: " << count << endl;
        

        if (count > n_maj)
        {
            cout << a[i] << (" is the majority element of the given array!") << endl;
            return a[i];
        }

        count = 1;
    }
    cout << "There's no such element." << endl;
    return 0;
}

int main()
{
    int A[] = {3, 3, 4, 2, 4, 4, 2, 4};
    int len = sizeof(A)/ sizeof(A[0]);

    int a = majEle(A, len);
    cout << a << endl;
    return 0;
}