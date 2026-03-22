class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty() == 1)
        {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        int maxLength = 1;
        int temp = 1;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            std::cout << nums[i] << std::endl;
            if(nums[i + 1] - nums[i] == 1)
            {
                temp++;
            }    
            else if(nums[i + 1] == nums[i])
            {
                continue;
            }
            else
            {
                temp = 1;
            }

            maxLength = max(temp, maxLength);
        }

        return maxLength;
    }
};