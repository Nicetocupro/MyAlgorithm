/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#ifdef LOCAL
#include<iostream>
#include<algorithm>
#include<vector>

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
    int maxDiameter = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        // root的深度左右相加（绝大多数是，但很多情况也不是这样）

        deepOfNode(root);

        return maxDiameter;
    }

    int deepOfNode(TreeNode* root)
    {
        if(root == nullptr)
        {
            return 0;
        }

        // 还应该计算每个节点的左右相加，
        int leftDeep = deepOfNode(root->left);
        int rightDeep = deepOfNode(root->right);

        int total = leftDeep + rightDeep;

        if(total > maxDiameter)
        {
            maxDiameter = total;
        }
        
        return std::max(leftDeep, rightDeep) + 1;
    }


};
// @lc code=end

