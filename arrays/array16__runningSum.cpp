#include <iostream>
#include <vector>
using namespace std;
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> output;
        int r_sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            r_sum += nums[i];
            output.push_back(r_sum);
        }
        return output;
    }
};

int main()
{
    vector<int> nums = {12, 34, 1, 2, 33, 34};
    cout << "The array having running sum of nums: "
         << " ";
    Solution sol;
    vector<int> running_nums = sol.runningSum(nums);
    for (int i = 0; i < running_nums.size(); i++)
    {
        cout << running_nums[i] << " ";
    }
    return 0;
}