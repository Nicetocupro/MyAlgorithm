/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL)
        {
            return NULL;
        }

        ListNode* Slow = head;
        ListNode* Fast = head;

        bool found = false;

        while(1)
        {
            Slow = Slow->next;

            if(Slow == NULL)
            {
                break;
            }

            if(Fast->next == NULL)
            {
                break;
            }

            Fast = Fast->next->next;

            if(Fast == NULL)
            {
                break;
            }

            if(Slow == Fast)
            {
                found = true;
                break;
            } 
        }

        if(found)
        {
            ListNode* temp = head;
            while(temp && (temp != Slow))
            {
                temp = temp->next;
                Slow = Slow->next;
            }
            return temp;
        }
        else
        {
            return NULL;
        }
    }
};