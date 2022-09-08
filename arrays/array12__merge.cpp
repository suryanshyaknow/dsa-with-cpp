#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void mergei(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        // using two pointers approach
        vector<int> *ptr1 = &nums1;
        vector<int> *ptr2 = &nums2;
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;

        while (i >= 0 && j >= 0)
        {
            if (ptr1->at(i) >= ptr2->at(j))
            {
                nums1[k] = ptr1->at(i);
                k--;
                i--;
            }
            else
            {
                nums1[k--] = ptr2->at(j--);
            }
        }
        while(i>=0) // if the elements of the nums1 are remaining
        {
            nums1[k--] = nums1[i--];
        }
        while(j>=0) // if the elements of the nums2 are remaining
        {
            nums1[k--] = nums1[j--];
        }
    }
    void mergeii(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> *ptr;
        ptr = &nums2;
        int j = 0;
        for (int i = m; i < nums1.size(); i++)
        {
            nums1[i] = ptr->at(j);
            j++;
        }
        sort(nums1.begin(), nums1.end());
    }
    void displayVec(vector<int> vec)
    {
        for (int i = 0; i < vec.size(); i++)
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    // How two access the elements of a vector using a pointer
    // vector<int> nums2 = {12, 34, 34, 66, 73, 40};
    // vector<int> *ptr = &nums2;
    // cout << "Address of the first ele of nums2: " << &nums2 << endl; // not nums2, unlike in arrays
    // cout << ptr->at(3) << endl;

    Solution sol;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6, 9};
    sol.mergei(nums1, 3, nums2, 4);
    sol.displayVec(nums1);
    return 0;
}