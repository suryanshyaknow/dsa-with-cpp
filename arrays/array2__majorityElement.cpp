#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
Find the majority element in the array.
--> A majority element in an array A[] of size n is an element that appears more than n/2 times
(and hence there is at most one such element).
*/

class Solution
{
public:
    int majorityElement(vector<int> &nums) // time: O(nlog(n) + n) // n to be discarded!
    {
        sort(nums.begin(), nums.end()); // time: O(nlog(n))

        int mtimes = nums.size() / 2;
        cout << "num of occurences to be a majority element: " << mtimes << endl;
        int count = 0;
        int ind = 0;

        // if the array contains a single ele then return the 0th index
        if (nums.size() == 1)
            return nums[0];

        // after sorting...
        // if the ele is same then keep the track of the count and keep updating it
        //..the moment it becomes more than n/2, return the index of the element
        for (int i = 0; i < nums.size(); i++) // time: n
        {
            if (nums[i] == nums[ind])
                count += 1;
            else
            {
                ind = i;
                count = 1;
            }
            if (count > mtimes)
                return nums[i];
        }
        return -1;
    }
    int majorityElement_ii(vector<int> &nums) // space: O(n), time: O(n)
    {
        int mtimes = nums.size() / 2;
        unordered_map<int, int> dict;
        for (auto a : nums)
        {
            dict[a]++;
            if (dict[a] > mtimes)
                return a;
        }
        return -1;
    }

    int majorityElement_i(vector<int> &nums)
    {
        int mtimes = nums.size() / 2;
        for (int i = 0; i < nums.size(); i++)
        {
            int count = 1;
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[j] == nums[i])
                    count += 1;
            }
            if (count > mtimes)
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    // vector<int> nums = {1};
    vector<int> nums = {2, 2};

    Solution sol;
    cout << "majority element: " << sol.majorityElement(nums) << endl;

    return 0;
}