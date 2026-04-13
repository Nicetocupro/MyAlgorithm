class Solution {
public:
    int maxArea(vector<int>& height) {
        // 越高越远越好
        int left = 0;
        int right = height.size() - 1;
        int maxArea = 0;
        while(left < right)
        {
            int tempArea = min(height[left], height[right]) * (right - left);
            maxArea = max(maxArea, tempArea);
            if(height[left] < height[right])
            {
                left++;
            }
            else
            {
                right--;
            }
        }

        return maxArea;
    }
};