## 24. 两两交换链表中的节点

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* slow = dummy;
        ListNode* fast = dummy;
        ListNode* temp = dummy;

        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next->next;

            std::cout << slow->val << " " << fast->val << std::endl;

            slow->next = fast->next;
            fast->next = slow;
            temp->next = fast;

            fast = slow;
            temp = slow;
        }

        return dummy->next;
    }
};

```


### 现有代码的问题

**命名问题**：`slow`/`fast` 在这题没有"快慢"语义，`slow` 实际是"对中第一个节点"，`fast` 是"对中第二个节点"，`temp` 是"对的前驱"——用快慢指针的名字套在这里会误导阅读。

**内存泄漏**：`new ListNode(0)` 分配了堆内存，但函数结束前没有 `delete dummy`。上一题用栈上 `ListNode dummy(0, head)` 更好。

**调试输出没删**：`std::cout` 留在提交代码里。

---

### 标准写法：只用一个前驱指针

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0, head);
        ListNode* prev = &dummy;   // 始终指向"当前待交换对"的前驱

        while (prev->next && prev->next->next) {
            ListNode* a = prev->next;        // 对中第一个
            ListNode* b = prev->next->next;  // 对中第二个

            // 交换：prev → b → a → (原 b 的后继)
            a->next = b->next;
            b->next = a;
            prev->next = b;

            prev = a;  // a 现在在后面，成为下一对的前驱
        }

        return dummy.next;
    }
};
```

你的三个指针对应关系：`temp = prev`，`slow = a`，`fast = b`——本质一样，换个名字可读性立刻提升。

---

### 进阶方法：递归

链表的"每两个一组"结构天然适合递归，代码极简：

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;   // 不足两个节点，直接返回

        ListNode* a = head;
        ListNode* b = head->next;

        a->next = swapPairs(b->next);  // 递归处理后续
        b->next = a;                   // b 接管 a 的位置

        return b;                      // b 成为这一对的新头
    }
};
```

递归版本只需理解一对的交换，其余交给递归栈，思路极清晰。代价是调用栈 O(n/2) 的空间。
