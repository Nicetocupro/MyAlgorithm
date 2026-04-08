/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        std::stack<ListNode*> myStack;
        ListNode* temp = head;
        int nodeSum = 0;

        while(temp != nullptr)
        {
            myStack.push(temp);
            temp = temp->next;
            nodeSum++;
        }

        temp = head;
        int step = 0;
        // 只用校验一半 4 2 5 2
        while(step != nodeSum / 2)
        {
            if(temp->val != myStack.top()->val)
            {
                return false;
            }
            temp = temp->next;
            myStack.pop();
            step++;
        }

        return true;
    }
};