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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::stack<ListNode*> myStack;
        ListNode* temp = head;

        while(temp != nullptr)
        {
            myStack.push(temp);
            temp = temp->next;
        }

        for(int i = 0; i < n; i++)
        {
            myStack.pop();
        }
        
        if(myStack.empty())
        {
            return head->next;
        }
        else
        {
            temp = myStack.top();

            temp->next = temp->next->next;
        }


        return head;
    }
};