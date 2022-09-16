#include <iostream>
#include <vector>
using namespace std;

/*
Problemo Statement:
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] > prices[i - 1])
            {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }

    int maxProfit_ii(vector<int> &prices) // WRONG approach!
    {

        int min_price1 = prices[0];
        int profit1 = 0;
        int ind = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            min_price1 = min(min_price1, prices[i]);
            profit1 = max(profit1, prices[i] - min_price1);

            ind += 1;
        }

        int min_price2 = prices[ind];
        int profit2 = 0;
        for (int i = ind; i < prices.size(); i++)
        {
            min_price2 = min(min_price2, prices[i]);
            profit2 = max(profit2, prices[i] - min_price2);
        }

        return profit1 + profit2;
    }
};
int main()
{
    // vector<int> prices = {1, 2, 3, 4, 5};
    // vector<int> prices = {7,1,5,3,6,4}; // answer: 7
    vector<int> prices = {5, 2, 7, 3, 6, 1, 2, 4}; // answer: 11
    Solution sol;
    cout << "max profit: " << sol.maxProfit(prices) << endl;
    return 0;
}