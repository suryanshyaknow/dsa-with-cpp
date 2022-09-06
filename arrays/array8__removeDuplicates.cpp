#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int tracker = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                nums[tracker] = nums[i];
                tracker++; 
            }
        }
        nums.erase(nums.begin()+tracker, nums.end());
        return nums.size();
    }
};

int main()
{
    vector<int> arr = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    Solution sol;
    cout << sol.removeDuplicates(arr) << endl;

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}