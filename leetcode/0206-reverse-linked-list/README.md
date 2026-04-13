## [206\. 反转链表](https://leetcode.cn/problems/reverse-linked-list/)

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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)
        {
            return NULL;
        }

        std::stack<ListNode*> myStack;
        ListNode* temp = head;

        while(temp != nullptr)
        {
            myStack.push(temp);
            temp = temp->next;
        }

        head = myStack.top();
        temp = head;
        myStack.pop();
        
        while(!myStack.empty())
        {
            temp->next = myStack.top();
            temp = temp->next;
            myStack.pop();
        }

        temp->next = nullptr;

        return head;
    }
};
```

**重点是最后 temp->next一定要为nullptr，否则还会继续往下延申**

