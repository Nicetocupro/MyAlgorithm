class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        // 动态规划
        int pre = 0, maxNum = nums[0];
        for(const auto x : nums)
        {
            pre = max(x, pre + x);
            maxNum = max(maxNum, pre);
        }

        return maxNum;
    }
};
