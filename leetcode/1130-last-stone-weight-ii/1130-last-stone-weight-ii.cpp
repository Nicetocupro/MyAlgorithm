class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) 
    {
        int sum = 0 , len = stones.size();

        for(int i = 0 ; i < len ; i++)
        {
            sum += stones[i];
        }
        vector<vector<int>> dp(len , vector<int>(sum / 2 + 1 , 0));

        for(int i = stones[0] ; i <= sum / 2 ; i++)
        {
            dp[0][i] = stones[0];
        }

        for(int i = 1 ; i < len ; i++)
        {
            for(int j = 0 ; j <= sum / 2 ; j++)
            {
                dp[i][j] = dp[i - 1][j];
                if(j >= stones[i])
                {
                    dp[i][j] = max(dp[i - 1][j] , dp[i - 1][j - stones[i]] + stones[i]);
                }
            }
        }

        int maxNum = 0;

        for(int i = 0 ; i <= sum / 2 ; i++)
        {
            maxNum = max(maxNum , dp[len - 1][i]);
        }


        return sum - 2 * maxNum;
    }
};