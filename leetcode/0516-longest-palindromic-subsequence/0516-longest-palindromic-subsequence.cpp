class Solution{
public:
    int longestPalindromeSubseq(string s)
    {
        int len = s.size();
        vector<vector<int>> dp(len , vector<int>(len , 0));

        for(int i = 0 ; i < len - 1 ; i++)
        {
            dp[i][i] = 1;
            dp[i][i + 1] = (s[i] == s[i + 1]) ? 2 : 1;
        }

        dp[len - 1][len - 1] = 1;

        for(int r = 2 ; r < len ; r++)
        {
            for(int i = 0 ; i + r < len ; i++)
            {
                int j = i + r;
                if(s[i] == s[j])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
                else
                {
                    dp[i][j] = max(dp[i + 1][j] , dp[i][j - 1]);
                }
            }
        }

        return dp[0][len - 1];
    }


};