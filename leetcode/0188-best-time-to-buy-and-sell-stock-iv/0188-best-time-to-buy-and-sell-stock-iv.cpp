class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int len = prices.size() , state = 2 * k;
        vector<vector<int>> dp(len , vector<int>(state , 0));
        for(int i = 0 ; i < state ; i++)
        {
            if(i % 2 == 0)
            {
                dp[0][i] = -prices[0];
            }
        }

        for(int i = 1 ; i < len ; i++)
        {
            
            dp[i][0] = max(dp[i - 1][0] , -prices[i]);
            dp[i][1] = max(dp[i - 1][1] , dp[i - 1][0] + prices[i]);

            for (int j = 2 ; j < state ; j++)
            {
                if(j % 2 == 0)
                {
                    dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - 1] - prices[i]);
                }
                else
                {
                    dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - 1] + prices[i]);
                }
            }
        }

        return dp[len - 1][state - 1];
    }
};