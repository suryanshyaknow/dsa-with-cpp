#include <iostream>
using namespace std;

int binarySearch(int arr[], int len, int x)
{
    int low = 0, high = len - 1;
    int mid = (low + high) / 2;

    while (low <= high)
    {
        if (arr[mid] == x)
        {
            return mid;
        }
        else if (arr[mid] < x)
        {
            low = mid + 1;
            mid = (low + high) / 2;
        }
        else
        {
            high = mid - 1;
            mid = (low + high) / 2;
        }
    }
    return -1;
}
int main()
{
    int arr[] = {10, 15, 17, 18, 26, 1972, 1976, 1999, 2004, 2011};
    int len = sizeof(arr) / sizeof(arr[0]);
    int x = 1999;
    cout << "The " << x << " is present at the index__" << binarySearch(arr, len, x) << " of arr" << endl;

    return 0;
}