class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int len = prices.size();
        if(len == 0)
        {
            return 0;
        }
        int maxProfit = 0;
        int minProfit = prices[0];
        for(int i = 0 ; i < len ; i++)
        {
            if(prices[i] > minProfit)
            {
                maxProfit = max(maxProfit , prices[i] - minProfit);
            }
            else
            {
                minProfit = prices[i];
            }
        }
        return maxProfit;
    }
};