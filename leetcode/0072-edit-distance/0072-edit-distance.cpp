class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        int len1 = word1.size() , len2 = word2.size();
        if(len1 * len2 == 0)
        {
            return max(len1 , len2);
        }
        vector<vector<int>> dp(len1 + 1 , vector<int>(len2 + 1 , 0));
        
        for(int i = 0 ; i < len1 + 1 ; i++)
        {
            dp[i][0] = i;
        }

        for(int i = 0 ; i < len2 + 1 ; i++)
        {
            dp[0][i] = i;
        }

        for(int i = 1 ; i < len1 + 1 ; i++)
        {
            for(int j = 1 ; j < len2 + 1 ; j++)
            {
                int op1 = dp[i - 1][j] + 1;
                int op2 = dp[i][j - 1] + 1;
                int op3 = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1;
                dp[i][j] = min(min(op1 , op2) , op3);
            }
        }

        return dp[len1][len2];
    }
};