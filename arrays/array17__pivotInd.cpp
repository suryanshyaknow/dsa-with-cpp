#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
class Solution
{
public:
    int pivotIndex_i(vector<int> &nums)
    {
        int l_sum = 0;
        int r_sum = 0;
        if (nums.size() == 1)
            return 0;

        int i = 0;
        while (i < nums.size())
        {
            r_sum = 0;
            if (i != 0)
                l_sum += nums[i - 1];
            for (int j = i + 1; j < nums.size(); j++)
                r_sum += nums[j];
            if (r_sum == l_sum)
                return i;
            i++;
        }
        return -1;
    }
    int pivotIndex_ii(vector<int> &nums)
    {

        int lsum = 0;
        int rsum = accumulate(nums.begin(), nums.end(), 0);

        if (nums.size() == 1)
            return 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0)
                lsum += nums[i - 1];

            rsum = rsum - nums[i];

            if (rsum == lsum)
                return i;
        }
        return -1;
    }
    int pivotIndex_iii(vector<int> &nums)
    {
        int l_sum = 0;
        int r_sum = 0;
        if (nums.size() == 1)
            return 0;

        int i = 0;
        while (i < nums.size())
        {
            r_sum = 0;
            if (i != 0)
                l_sum += nums[i - 1];
            r_sum = accumulate(nums.begin() + i + 1, nums.end(), r_sum);

            if (r_sum == l_sum)
            {
                cout << "lsum: " << l_sum << endl;
                cout << "rsum: " << r_sum << endl;
                return i;
            }
            i++;
        }
        return -1;
    }
};

int main()
{
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    // vector<int> nums = {-1, -1, -1, -1, -1, -1};
    // vector<int> nums = {1,2,3};
    // vector<int> nums = {2,1,-1};
    Solution sol;
    cout << "pivot index: " << sol.pivotIndex_i(nums) << endl;
    cout << "pivot index: \n"
         << sol.pivotIndex_ii(nums) << endl;

    return 0;
}