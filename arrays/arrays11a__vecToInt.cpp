#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long vecToInt(vector<int> nums)
{
    long long num = 0;
    int len = nums.size();
    for (int i = 0; i < nums.size(); i++)
    {
        num += nums[i] * pow(10, (len - 1 - i));
        cout << num << " ";
    }
    return num;
}

int main()
{
    // vector<int> nums = {9, 5, 2, 8, 1};
    vector<int> nums = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};
    cout << "conversion of the `vector nums` into int: " << vecToInt(nums) << endl;
    return 0;
}