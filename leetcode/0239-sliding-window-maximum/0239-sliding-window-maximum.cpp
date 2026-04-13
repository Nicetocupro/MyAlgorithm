class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int left = 0, maxPos = 0;
        vector<int> result;
        for(int i = 0; i < (k > nums.size() ? nums.size() : k); i++)
        {
            maxPos = (nums[maxPos] > nums[i]) ? maxPos : i;
        }

        result.push_back(nums[maxPos]);
        left++;

        while(left + k <= nums.size())
        {
            if(nums[left + k - 1] > nums[maxPos])
            {
                maxPos = left + k - 1;
                left++;
                result.push_back(nums[maxPos]);
                continue;
            }

            // 重新寻找最大值
            if(maxPos < left)
            {
                maxPos = left;
                for(int i = left; i < left + k; i++)
                {
                    maxPos = (nums[maxPos] > nums[i]) ? maxPos : i;
                }
            }
            result.push_back(nums[maxPos]);
            left++;
        }

        return result;
    }
};