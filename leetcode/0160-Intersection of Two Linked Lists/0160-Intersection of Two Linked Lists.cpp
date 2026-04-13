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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> set;
        ListNode* temp = headA;

        while(temp != NULL)
        {
            set.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while(temp != NULL)
        {
            if(set.contains(temp))
            {
                return temp;
            }
            temp = temp->next;
        }
       
        return NULL;
    }
};