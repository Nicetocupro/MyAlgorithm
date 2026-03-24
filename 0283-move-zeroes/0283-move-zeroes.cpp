class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;

        while(right < nums.size())
        {
            if(nums[right])
            {
                int temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                left++;
            }
            right++;
        }
    }
};


/*
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count = 0;
        for(int j = 0; j < nums.size(); j++)
        {
            if(nums[j] == 0 && j < nums.size() - count)
            {
                for(int i = j + 1; i < nums.size(); i++)
                {
                    int temp = nums[i - 1];
                    nums[i - 1] = nums[i];
                    nums[i] = temp;
                }
                count++;
                j--;
            }
        }
    }
};

*/