class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        for(int i = 0; i < nums.size(); i++)
        {
            auto it = std::find(nums.begin(), nums.end(), target - nums[i]);
            int temp = std::distance(nums.begin(), it);
            if(it != nums.end() && temp != i)
            {
                std::cout << nums[i] << std::endl;
                return vector<int>{i, temp};
            }
        }

        return vector<int>();
    }
};