#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit_i(vector<int> &prices) // O(n) time complexity and O(n) space taken!
    {
        vector<int> aux; // max price of stock on a certain day
        /* Think of it as this way:
        Assume today if I'd know on what day the stock is going to be sold at maximum price,
        I'd be able to have maximum profit.
        */

        int max_so_far = prices[prices.size() - 1];
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (max_so_far < prices[i])
            {
                aux.push_back(prices[i]);
                max_so_far = prices[i];
            }
            else
            {
                aux.push_back(max_so_far);
            }
        }
        reverse(aux.begin(), aux.end());

        int max_profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            if (aux[i]-prices[i] > max_profit)
            {
                max_profit = aux[i]-prices[i];
            }
        }       
        // displaying the aux array
        // for (int i = 0; i < aux.size(); i++)
        // {
        //     cout << aux[i] << " ";
        // }
        // cout << endl;

        return max_profit;
    }

    int maxProfit_ii(vector<int> &prices) // O(n) time complexity!
    {   
        /*
        Think of this approach as this way:
        Try to sell the stock on each day and think over what was the day before today where you could've
        bought it for the lowest price.
        */
        int min_price = prices[0];
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            min_price = min(min_price, prices[i]);
            profit = max(profit, prices[i] - min_price);
        }
        return profit;
    }

    int maxProfit_iii(vector<int> &prices)
    {

        int cheapest = 0;
        int exp = 1;
        int profit = 0;

        for (int i = 0; i < prices.size(); i++)
        {
            // had to buy on the day on which price is lowest
            if (prices[i] < prices[cheapest])
            {
                cheapest = i;
                exp = i + 1; // it must be kept on increasing so that day[sell] > day[buy] always
            }
            for (int j = i + 1; j < prices.size(); j++)
            {
                // had to sell on the day on which the price is highest!
                if (prices[j] > prices[exp])
                {
                    exp = j;
                }
                if (prices[exp] - prices[cheapest] > profit)
                {
                    profit = prices[exp] - prices[cheapest];
                }
            }
        }
        return profit;
    }
};

int main()
{
    // vector<int> prices = {2,4,1};
    // vector<int> prices = {7, 6, 4, 3, 1};
    vector<int> prices = {300, 100, 400, 800, 700, 200, 500};
    Solution sol;
    cout << "max profit: " << sol.maxProfit_i(prices) << endl;
    cout << "max profit: " << sol.maxProfit_ii(prices) << endl;
    return 0;
}