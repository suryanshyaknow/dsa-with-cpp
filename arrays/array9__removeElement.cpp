#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        // for (int i = 0; i < nums.size(); i++)
        // {
        //     if (nums[i] == val)
        //     {
        //         nums.erase(nums.begin() + i);
        //         continue;
        //     }
        // }
        int i = 0;
        while (i < nums.size())
        {
            if (nums[i] == val)
            {
                nums.erase(nums.begin()+i);
                continue;
            }
            i++;
        }
        return nums.size();
    }
};

int main()
{
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};

    Solution sol;
    cout << sol.removeElement(nums, 2) << endl;

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}