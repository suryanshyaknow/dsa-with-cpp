#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<int> output;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    output.push_back(i);
                    output.push_back(j);
                }
            }
        }
        return output;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    Solution sol;
    sol.twoSum(nums, 9);

    return 0;
}