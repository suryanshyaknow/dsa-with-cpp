#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> intToVec(long long num)
{
    vector<int> nums;
    string s = to_string(num);

    string ele;
    for (int i = 0; i < size(s); i++)
    {
        ele = s[i];
        nums.push_back(stoi(ele));
    }
    return nums;
}

vector<int> int_to_vec(long long num)
{
    vector<int> nums;
    while (num != 0)
    {
        nums.push_back(num % 10);
        num /= 10;
    }
    reverse(nums.begin(), nums.end());
    return nums;
}

int main()
{
    // vector<int> x = intToVec(952825323479230743);
    vector<int> x = int_to_vec(6145390195186705408);

    // displaying the vector
    for (int i = 0; i < x.size(); i++)
    {
        /* code */
        cout << x[i] << " ";
    }
    cout << endl;

    return 0;
}