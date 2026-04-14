/*
 * @lc app=leetcode id=190 lang=cpp
 *
 * [190] Reverse Bits
 */
#ifdef LOCAL
#include <iostream>
#include <bitset>
#endif

// @lc code=start
class Solution {
public:
    int reverseBits(int n) {
        unsigned int left = 1, right = 1 << 31;
        
        while(left <= right)
        {
            unsigned int left_temp = n & left;
            unsigned int right_temp = n & right;

            if(left_temp == 0)
            {
                n = n & (~right);
            }
            else
            {
                n = n | right;
            }

            if(right_temp == 0)
            {
                n = n & (~left);
            }
            else 
            {
                n = n | left;
            }

            left *= 2;
            right /= 2;
        }

        return n;
    }
};

# ifdef LOCAL
int main()
{
    Solution s;
    std::cout << std::bitset<32>(s.reverseBits(43261596)) << std::endl;
}
# endif
// @lc code=end

