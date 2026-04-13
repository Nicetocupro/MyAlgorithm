## [234\. 回文链表](https://leetcode.cn/problems/palindrome-linked-list/) 

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
    bool isPalindrome(ListNode* head) {
        std::stack<ListNode*> myStack;
        ListNode* temp = head;
        int nodeSum = 0;

        while(temp != nullptr)
        {
            myStack.push(temp);
            temp = temp->next;
            nodeSum++;
        }

        nodeSum /= 2;
        temp = head;

        for(int i = 0; i <= nodeSum; i++)
        {
            if(temp->val != myStack.top()->val)
            {
                return false;
            }
            temp = temp->next;
            myStack.pop();
        }

        return true;
    }
};
```

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
    bool isPalindrome(ListNode* head) {
        if (!head) return false;
        if (!head->next) return true;

        ListNode* slow = head, *fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        ListNode* prev = nullptr;
        ListNode* cur = slow;
        while (cur) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        while (prev && head) {
            if (prev->val != head->val) return false;
            prev = prev->next;
            head = head->next;
        }
        return true;
    }
};
```

不如栈不如快慢指针迅速的原因是

### 核心原因：缓存局部性 + 常数因子

#### 你的栈方法

```
O(n) 时间 + O(n) 空间
```

每个节点都要：
1. **push 进栈**（写内存）
2. **pop 出栈**（读内存）
3. 栈内部是 `std::stack<ListNode*>`，底层是 `std::deque`，内存**不连续**，缓存命中率低

#### 快慢指针方法

```
O(n) 时间 + O(1) 空间
```

- **不分配额外内存**，没有 heap allocation 开销
- 只是指针操作，CPU 寄存器就能搞定
- 缓存完全不是问题

---

#### 本质差距

| | 你的栈 | 快慢指针 |
|---|---|---|
| 额外空间 | O(n) | O(1) |
| 内存分配 | 有（deque 动态扩容） | 无 |
| 遍历次数 | 2n（全部push + 一半pop） | 1.5n |
| 缓存友好 | ❌ | ✅ |
