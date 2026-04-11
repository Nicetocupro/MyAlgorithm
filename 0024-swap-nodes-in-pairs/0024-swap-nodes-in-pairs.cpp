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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;
        ListNode* temp = &dummy;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            slow->next = fast->next;
            fast->next = slow;
            temp->next = fast;

            fast = slow;
            temp = slow;
        }

        return dummy.next;
    }
};