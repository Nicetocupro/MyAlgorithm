class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        if (prices.empty()) 
        {
            return 0;
        }
        int cash = 0; //不持有股票的最大利润
        int hold = - prices[0] - fee; //持有股票的最大利润

        for(unsigned int i = 0 ; i < prices.size() ;i++)
        {
            cash = max(cash , hold + prices[i]);
            hold = max(hold , cash - prices[i] - fee);
        }

        return cash;
    }
};