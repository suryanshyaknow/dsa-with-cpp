#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        // let's first find it..
        int low = 0, high = nums.size() - 1;
        int mid = (low + high) / 2;
        int ind = -1; // position where target is to be inserted!

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] > target)
            {
                high = mid - 1;
                ind = mid;
            }
            else // nums[mid] < target
            {
                low = mid + 1;
                ind = mid + 1;
            }
        }
        return ind;
    }
};

int main()
{
    return 0;
}