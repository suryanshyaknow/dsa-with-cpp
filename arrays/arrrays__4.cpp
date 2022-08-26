#include <iostream>
using namespace std;

// Largest Sum Contiguous Subarray
/* Write an efficient program to find the sum of the contiguous subarray within a one-dimensional array of numbers
that has the largest sum.
*/

int maxSubArraySum(int a[], int len)
{   
    int max_so_far = INT_MIN; // to keep the track of maximum so far
    int max_ending_here = 0; // keeps on updating

    for (int i=0; i<len; i++)
    {
        max_ending_here += a[i];

        // update the max_so_far 
        if (max_ending_here >= max_so_far)
        {
            max_so_far = max_ending_here;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0; 
            /* Cuz I don't want it to keep negative values since we are assured that there's gonna be atleast one
            positive value which will make my sum positive and largest.
            */
        }
    }

    return max_so_far;
}

int main()
{
    int A[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int len = sizeof(A) / sizeof(A[0]);

    cout << "The largest sum of the contiguous Subarray is: " << maxSubArraySum(A, len) << endl;
    
    int B[] = {-2, -3, -4, -1, -2, 1, 5, -3};
    int len_b = sizeof(A) / sizeof(A[0]);

    cout << "The largest sum of the contiguous Subarray is: " << maxSubArraySum(B, len_b) << endl;

    return 0;
}