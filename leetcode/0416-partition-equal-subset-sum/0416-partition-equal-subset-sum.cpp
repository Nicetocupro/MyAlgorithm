class Solution {
public:
    bool canPartition(vector<int>& nums) 
    {
        int sum = 0 , maxNum = 0;
        for(unsigned int i = 0 ; i < nums.size() ; i++)
        {
            sum += nums[i];
            maxNum = max(nums[i] , maxNum);
        }

        int target = sum / 2;
        if(nums.size() <= 1 || maxNum > target || sum % 2 != 0)
        {
            return false;
        }
        

        vector<vector<bool>> dp(nums.size(), vector<bool>(target + 1, 0));


        dp[0][nums[0]] = true;

        for(unsigned int i = 0 ; i < nums.size() ; i++)
        {
            dp[i][0] = false;
        }

        for(unsigned int i = 1 ; i < nums.size() ; i++)
        {
            
            for(int j = 0 ; j < target + 1 ; j++)
            {
                if(nums[i] > j)
                {
                    dp[i][j] = dp[i - 1][j];
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
                }
            }
        }
        
        return dp[nums.size() - 1][target];
    }
};