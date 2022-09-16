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
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());

        int mtimes = nums.size() / 2;
        cout << "num of occurences to be a majority element: " << mtimes << endl;
        int count = 0;
        int ind = 0;

        if (nums.size()==1)return nums[0];
        
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == nums[ind])
                count += 1;
            else
            {
                cout << "count of " << nums[i] << ": " << count << endl;
                if (count >= mtimes)
                    return nums[i];
                ind = i;
                count = 1;
            }
        }
        return -1;
    }
    int majorityElement_ii(vector<int> &nums)
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
            if (count >= mtimes)
                return nums[i];
        }
        return -1;
    }
};

int main()
{
    // vector<int> nums = {2, 2, 1, 1, 1, 2, 2};
    vector<int> nums = {1};

    Solution sol;
    cout << "majority element: " << sol.majorityElement(nums) << endl;

    return 0;
}