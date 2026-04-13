class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int result = 0;

        for (auto it1 = nums.begin(); it1 < nums.end(); it1++) {
            int tempSum = k - *it1;

            if (tempSum == 0) {
                result++;
            }

            for (auto it2 = it1 + 1; it2 < nums.end(); it2++) {
                if (tempSum == *it2) {
                    result++;    
                }

                tempSum -= *it2;
            }
        }

        return result;
    }
};