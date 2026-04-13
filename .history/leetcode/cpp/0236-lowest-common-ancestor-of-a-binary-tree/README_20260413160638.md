## [236\. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

这个题写的可以，一下子就抓住了题目面试要点，虽然不是最快的方法。

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr)
        {
            return nullptr;
        }

        if(root == p || root == q)
        {
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(left != nullptr && right != nullptr)
        {
            return root;
        }
        else if(left == nullptr && right != nullptr)
        {
            return right;
        }
        else if(left != nullptr && right == nullptr)
        {
            return left;
        }
        else
        {
            return nullptr;
        }
    }
};
```