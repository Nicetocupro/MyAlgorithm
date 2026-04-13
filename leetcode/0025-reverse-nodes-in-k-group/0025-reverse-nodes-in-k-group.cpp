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
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::stack<ListNode*> myStack;
        ListNode* temp = head;

        for(int i = 0; i < k; i++)
        {
            if(temp == nullptr)
            {
                return head;
            }

            myStack.push(temp);
            temp = temp->next;
        }

        ListNode* nextNode = temp;
        ListNode dummy(0);
        temp = &dummy;

        for(int i = 0; i < k; i++)
        {
            temp->next = myStack.top();
            myStack.pop();
            temp = temp->next;
        }

        temp->next = reverseKGroup(nextNode, k);

        return dummy.next;
    }
};