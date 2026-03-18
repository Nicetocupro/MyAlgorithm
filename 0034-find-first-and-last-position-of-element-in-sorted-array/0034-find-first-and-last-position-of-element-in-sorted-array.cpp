class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto it1 = std::find(nums.begin(), nums.end(), target);
        if(it1 == nums.end()) return vector<int>{-1, -1};

        int begin = std::distance(nums.begin(), it1);
        auto it2 = std::find(nums.rbegin(), nums.rend(), target);
        int end = std::distance(nums.begin(), --it2.base());

        return vector<int>{begin, end};    
    }
};