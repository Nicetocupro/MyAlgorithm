class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int found = 1;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0)
            {
                continue;
            }
            if(found == nums[i])
            {
                found++;
            }
            else if(nums[i] <= found)
            {
                continue;
            }
            else
            {
                break;
            }
        }

        return found;
    }
};