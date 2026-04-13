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
    struct compare {
        bool operator()(ListNode* list1, ListNode* list2)
        {
            return list1->val > list2->val;
        }
    };
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* result;

        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        }

        std::priority_queue<ListNode*, std::vector<ListNode*>, compare> myQueue;
        ListNode* temp = list1;

        while (temp != nullptr) {
            myQueue.push(temp);
            temp = temp->next;
        }

        temp = list2;

        while (temp != nullptr) {
            myQueue.push(temp);
            temp = temp->next;
        }

        result = myQueue.top();
        myQueue.pop();
        temp = result;

        while (!myQueue.empty()) {
            temp->next = myQueue.top();
            temp = temp->next;
            myQueue.pop();
        }

        temp->next = nullptr;

        return result;
    }
};