#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        // making the vector's elements as an integer
        // and increementing it by one
        vector<int> nums;

        long long num = 0;
        int size = digits.size();
        for (int i = 0; i < size; i++)
        {
            num += digits[i] * pow(10, (size - 1) - i);
        }
        num++;
        cout << num << endl;

        // appending the digits of the number formed into nums
        while (num != 0)
        {
            nums.push_back(num % 10);
            num /= 10;
        }
        reverse(nums.begin(), nums.end());
        return nums;
    }

    vector<int> plus_one(vector<int> &digits) // failed for some test cases!
    {
        string s1;
        for (int i = 0; i < digits.size(); i++)
        {
            s1 += to_string(digits[i]);
        }
        string s2 = to_string(stoll(s1) + 1);

        vector<int> ans;
        string x;
        for (int i = 0; i < size(s2); i++)
        {
            x = s2[i];
            ans.push_back(stoi(x));
        }
        return ans;
    }
};

int main()
{
    vector<int> digits = {6, 1, 4, 5, 3, 9, 0, 1, 9, 5, 1, 8, 6, 7, 0, 5, 5, 4, 3};
    Solution sol;

    vector<int> nums = sol.plus_one(digits);
    for (int i = 0; i < nums.size(); i++)
    {
        /* code */
        cout << nums[i] << " ";
    }

    // ********************************************************************************************
    // ********************** Conversion of string into int and vice-versa ************************
    // int arr[] = {1, 2, 4};
    // int sizeof_arr = sizeof(arr) / sizeof(arr[0]);
    // string s;

    // // Converting each element of the `array arr` to string and appending to `string s`
    // for (int i = 0; i < sizeof_arr; i++)
    // {
    //     s += to_string(arr[i]);
    // }

    // cout << "string form of arr: " << s << endl;
    // cout << "length of the string s: " << size(s) << endl;

    // // converting each char of the `string s` and pushing in into a vector
    // vector<int> digits;
    // string x;
    // for (int i = 0; i < size(s); i++)
    // {
    //     x = s[i];
    //     cout << "x : " << x << endl;
    //     digits.push_back(stoi(x));
    // }

    // // dislaying the vector `digits`
    // cout << "\ndisplaying the vector `digits`: ";
    // for (int i = 0; i < digits.size(); i++)
    // {
    //     cout << digits[i] << " ";
    // }
    // **********************************************************************************************

    return 0;
}