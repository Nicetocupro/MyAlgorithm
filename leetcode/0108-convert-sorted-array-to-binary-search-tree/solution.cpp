/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
 */

#ifdef LOCAL
#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
#endif

class Solution {
public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        return sortedArrayToBstInMid(nums, 0, nums.size());
    }

    TreeNode* sortedArrayToBstInMid(std::vector<int>& nums, int left, int right)
    {
        if(left >= right)
        {
            return nullptr;
        }

        int mid = (right + left) / 2;       
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = sortedArrayToBstInMid(nums, left, mid);
        root->right = sortedArrayToBstInMid(nums, mid + 1, right);

        return root;
    }
};
// @lc code=end

