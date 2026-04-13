class Solution {
public:
    int trap(vector<int>& height) {
        int sumTrap = 0;
        int left = 0, right = height.size() - 1;
        int maxLeft = 0, maxRight = 0;

        while(left < right)
        {
            maxLeft = max(height[left], maxLeft);
            maxRight = max(height[right], maxRight);

            if(maxLeft <= maxRight)
            {
                sumTrap += maxLeft - height[left];
                left++;
            }
            else
            {
                sumTrap += maxRight - height[right];
                right--;
            }
        }
        return sumTrap;
    }
};