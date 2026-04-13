class Solution {
public:
    
    int maxProfit(vector<int>& prices) 
    {
        
        int len = prices.size();
        vector<vector<int>> dp(len , vector<int>(4 , 0));
        dp[0][0] = -prices[0]; // 0 只进行过一次买操作；
        dp[0][1] = 0; // 1 进行了一次买操作和一次卖操作，即完成了一笔交易；
        dp[0][2] = -prices[0]; // 2 在完成了一笔交易的前提下，进行了第二次买操作；
        dp[0][3] = 0; // 3 完成了全部两笔交易。

        for(int i = 1 ; i < len ; i++)
        {
            dp[i][0] = max(dp[i - 1][0] , -prices[i]);
            dp[i][1] = max(dp[i - 1][1] , prices[i] + dp[i - 1][0]);
            dp[i][2] = max(dp[i - 1][2] , dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3] , dp[i - 1][2] + prices[i]);
        }

        return dp[len - 1][3];
    }
};