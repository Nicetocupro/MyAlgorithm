class Solution {
public:
    int maxCoins(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> ans(n + 2 , vector<int>(n + 2));
        vector<int> val(n + 2);

        val[0] = 1;
        val[n + 1] = 1;
        for (int i = 1; i <= n; i++)
        {
            val[i] = nums[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j <= n + 1; j++)
            {
                for (int k = i + 1; k < j; k++)
                {
                    int sum = val[i] * val[k] * val[j];
                    sum += ans[i][k] + ans[k][j];
                    ans[i][j] = max(ans[i][j], sum);
                }
            }
        }
        return ans[0][n + 1];
    }
};