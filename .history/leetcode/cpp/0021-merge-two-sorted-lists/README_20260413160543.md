## [21\. 合并两个有序链表](https://leetcode.cn/problems/merge-two-sorted-lists/)

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
```

上面我写的过于麻烦不如下面这种

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
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
  if (list1 == nullptr && list2 == nullptr) 
    return nullptr;

  ListNode* head = new ListNode();
  ListNode* cur = head;
  auto n1 = list1;
  auto n2 = list2;
  while (n1 != nullptr && n2 != nullptr) {
    if (n1->val > n2->val) {
      cur->next = n2;
      n2 = n2->next;
    } else {
      cur->next = n1;
      n1 = n1->next;
    }
    cur = cur->next;
  }

  if (n1 == nullptr) {
    cur->next = n2;
  }
  if (n2 == nullptr) {
    cur->next = n1;
  }

  return head->next;
}
};
```

两个链表显得太大材小用了使用priority_queue
