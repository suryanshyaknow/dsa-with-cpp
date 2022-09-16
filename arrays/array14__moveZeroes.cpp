#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void moveZeroes_i(vector<int> &nums) // mine and mine only!
    {
        int ind = 0;
        int zeros = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                zeros += 1;
            }
            else
            {
                nums[ind++] = nums[i];
            }
        }
        int from_last = nums.size() - 1;

        while (zeros > 0)
        {
            nums[from_last--] = 0;
            zeros--;
        }
    }

    void moveZeroes_ii(vector<int> &nums)
    {
        int ind = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[ind++] = nums[i];
            }
        }
        while (ind < nums.size())
        {
            nums[ind++] = 0; 
        }
        
    }
};

int main()
{
    vector<int> nums = {0, 1, 3, 0, 12};
    Solution sol;
    sol.moveZeroes_i(nums);
    sol.moveZeroes_ii(nums);

    // displaying the vector after doing what was required
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}