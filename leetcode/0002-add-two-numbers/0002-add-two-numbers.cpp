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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int lastNum = 0;

        while (temp1 != nullptr || temp2 != nullptr) {
            if (temp1 != nullptr && temp2 != nullptr) {
                temp1->val = temp1->val + temp2->val + lastNum;
                lastNum = temp1->val / 10;
                temp1->val %= 10;
                temp->next = temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp2 == nullptr) {
                
                temp1->val += lastNum;
                lastNum = temp1->val / 10;
                temp1->val %= 10;
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp2->val += lastNum;
                lastNum = temp2->val / 10;
                temp2->val %= 10;
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if(lastNum)
        {
            temp->next = new ListNode(lastNum);
        }
        else 
        {
            temp->next = nullptr;
        }
        
        return result->next;
    }
};