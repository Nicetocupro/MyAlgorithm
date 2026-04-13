
## [148\. 排序链表](https://leetcode.cn/problems/sort-list/)

```cpp
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
```

虽然这个题能直接用小顶堆的方法进行实现，但是没有体现出该题目的考点：归并排序

```cpp
class Solution {
private:
    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode dummy(-1);
        ListNode* curr = &dummy;
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 == nullptr) ? l2 : l1;
        return dummy.next;
    }
public:
    ListNode* sortList(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != nullptr && fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* mid = slow->next;
        slow->next = nullptr;
        
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        
        return merge(left,right);
    }
    

};
```
