class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if (len <= 1) {
            return len;
        }

        // 初始状态
        int state = 0; // 0 表示初始状态，1 表示上升状态，-1 表示下降状态
        int ans = 1; // 至少有一个元素
        for (int i = 1; i < len; ++i) {
            int diff = nums[i] - nums[i - 1];
            if ((diff > 0 && state != 1) || (diff < 0 && state != -1)) {
                // 当前状态转为摆动状态，更新状态并增加摆动序列长度
                state = diff > 0 ? 1 : -1;
                ++ans;
            }
        }
        
        return ans;
    }
};