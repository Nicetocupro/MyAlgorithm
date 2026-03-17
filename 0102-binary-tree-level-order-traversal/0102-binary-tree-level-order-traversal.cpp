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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        std::queue<TreeNode*> myqueue;
        vector<vector<int>> List;

        if(root == nullptr)
        {
            return List;
        }

        myqueue.push(root);
        while(!myqueue.empty())
        {  
            int size = myqueue.size();
            vector<int> subList;
            for(int i = 0; i < size; i++)
            {
                TreeNode *temp = myqueue.front();
                int val = temp->val;
                myqueue.pop();
                subList.push_back(val);

                if(temp->left != nullptr) myqueue.push(temp->left);
                if(temp->right != nullptr) myqueue.push(temp->right);
            }
            List.push_back(subList);
        }

        return List;
    }
};