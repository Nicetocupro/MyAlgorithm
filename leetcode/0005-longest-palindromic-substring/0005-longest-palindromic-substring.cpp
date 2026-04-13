class Solution {
public:
    string longestPalindrome(string s) 
    {
        int len = s.size();
        vector<vector<bool>> dp(len , vector<bool>(len , false));
        int maxLen = 1 , left = 0;
        for(int i = 0 ; i < len - 1 ; i++)
        {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if(dp[i][i + 1] && maxLen < 2)
            {
                maxLen = 2;
                left = i;
            }
        }

        dp[len - 1][len - 1] = true;

        for(int r = 2 ; r < len ; r++)
        {
            for(int i = 0 ; i + r < len ; i++)
            {
                int j = i + r;
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
                if(dp[i][j] && j - i + 1 > maxLen)
                {
                    maxLen = j - i + 1;
                    left = i;
                }
            }
        }
        
        return s.substr(left , maxLen);
    }
};