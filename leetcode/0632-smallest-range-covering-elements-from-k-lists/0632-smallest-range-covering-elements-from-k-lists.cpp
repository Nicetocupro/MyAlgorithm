class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int len = nums.size();
        vector<int> dp(len , 0);
        vector<int> result(2 , 0);
        result[0] = 0;
        result[1] = INT_MAX;
        int minNum = INT_MAX , maxNum = INT_MIN;
        while(1)
        {
            minNum = INT_MAX , maxNum = INT_MIN;
            for(int i = 0 ; i < len ; i++)
            {
                minNum = min(minNum , nums[i][dp[i]]);
                maxNum = max(maxNum , nums[i][dp[i]]);
            }
            if(maxNum - minNum < result[1] - result[0])
            {
                result[0] = minNum;
                result[1] = maxNum;
            }
            for(int i = 0 ; i < len ;i++)
            {
                if(nums[i][dp[i]] == minNum)
                {
                    dp[i]++;
                    if((unsigned int)dp[i] >= nums[i].size())
                    {
                        return result;
                    }
                    break;
                }
            }

        }

    }
};