#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int max_Profit(vector<int>& prices) {
        int min_price = INT_MAX;
        int profit = 0;
        for (int i = 0; i < prices.size(); i++)
        {
            min_price = min(prices[i], min_price);
            profit = max(profit, prices[i]-min_price);
        }
        return profit;        
    }

    int maxProfit(vector<int>& prices) {
        
        int cheapest = 0;
        int exp = 1;
        int profit = 0;
        
        for (int i=0; i<prices.size(); i++)
        {
            // had to buy on the day on which price is lowest
            if (prices[i] < prices[cheapest])
            {
                cheapest=i;
                exp=i+1; // it must be kept on increasing so that day[sell] > day[buy] always
            }
            for(int j=i+1; j<prices.size(); j++)
            {
                // had to sell on the day on which the price is highest!
                if (prices[j] > prices[exp] )
                {
                    exp=j;
                }
                if (prices[exp]-prices[cheapest] > profit)
                {   
                   profit= prices[exp]-prices[cheapest];
                }
            }
        }
        return profit;
    }

    int max_profit(vector<int> &prices) // failed for some cases miserably!
    {
        int cheapest = 0;
        // finding the day when the stock pricers is lowest
        for (int i = 1; i < prices.size(); i++)
        {
            if (prices[i] < prices[cheapest])
            {
                cheapest = i;
            }
        }
        // checking if today is that so only
        if (cheapest == prices.size() - 1)
        {
            return 0;
        }
        else
        {
            int exp = cheapest;
            // finding the day when the price is expensive
            for (int i = cheapest + 1; i < prices.size(); i++)
            {
                if (prices[i] > prices[exp])
                {
                    exp = i;
                }
            }
            if (prices[cheapest] < prices[exp])
            {
                return prices[exp] - prices[cheapest];
            }
        }
        return 0;
    }
};

int main()
{   
    // vector<int> prices = {2,4,1};
    vector<int> prices = {7,6,4,3,1};
    Solution sol;
    cout << "max profit: " << sol.maxProfit(prices) << endl;
    cout << "max profit: " << sol.max_Profit(prices) << endl;
    return 0;
}