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
    struct Compare{
        bool operator()(ListNode* a, ListNode* b)
        {
            return a->val > b->val;
        }
    };

    ListNode* sortList(ListNode* head) {
        if(head == nullptr)
        {
            return head;
        }
        
        std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> myQueue;
        while(head != nullptr)
        {
            myQueue.push(head);
            head = head->next;
        }

        head = myQueue.top();
        myQueue.pop();

        ListNode* temp = head;

        while(!myQueue.empty())
        {
            temp->next = myQueue.top();
            myQueue.pop();
            temp = temp->next;
        }
        temp->next = nullptr;

        return head;
    }
};