## 19. 删除链表的倒数第 N 个结点

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::stack<ListNode*> myStack;
        ListNode* temp = head;

        while(temp != nullptr)
        {
            myStack.push(temp);
            temp = temp->next;
        }

        for(int i = 0; i < n; i++)
        {
            myStack.pop();
        }
        
        if(myStack.empty())
        {
            return head->next;
        }
        else
        {
            temp = myStack.top();

            temp->next = temp->next->next;
        }


        return head;
    }
};
```


### 现有代码分析

**正确之处**：利用栈的 LIFO 特性，弹 N 次后栈顶就是待删节点的前驱，逻辑清晰。

**不足之处**：

- 空间复杂度 O(n)——所有节点都进了栈，但其实不需要存储它们
- `temp->next->next` 没有判空，如果 `temp->next` 是最后一个节点（即删除尾节点），`next->next` 合法；但如果 `temp->next` 为 `nullptr` 则崩溃——好在逻辑上此处 `temp->next` 必然存在，但可读性差
- 没有加哑节点，导致"删除头节点"需要单独 `if(myStack.empty())` 处理

---

### 进阶方法：快慢双指针（O(1) 空间）

这是本题的标准最优解，一次遍历，不需要额外空间。

**核心思路**：让 `fast` 先走 N 步，然后 `fast` 和 `slow` 同步走，当 `fast` 到达末尾时，`slow` 恰好在待删节点的前驱。

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);      // 哑节点，统一处理删头节点的情况
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; i++) // fast 先走 n+1 步
            fast = fast->next;

        while (fast != nullptr) {    // 同步走到 fast 到末尾
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next; // slow 此时是待删节点的前驱
        return dummy.next;
    }
};
```
---

### 两种方法对比

| 维度 | 栈方法（你的） | 快慢双指针 |
|---|---|---|
| 时间复杂度 | O(n) | O(n) |
| 空间复杂度 | **O(n)**（存了所有节点） | **O(1)** |
| 遍历次数 | 1次入栈 + 弹栈 | 1次 |
| 代码行数 | ~20 行 | ~10 行 |
| 删头节点处理 | 需要额外 `if` | 哑节点自动统一 |

---

### 值得掌握的通用技巧

**快慢指针**是链表题最高频的思维工具，不只用于本题：

- **找中间节点**（876）：slow 走 1 步，fast 走 2 步，fast 到尾时 slow 在中间
- **检测环**（141/142）：fast 追上 slow 则有环
- **删倒数第 N 个**（本题）：fast 先走 N+1 步保持间距

**哑节点（dummy head）**配合双指针几乎是链表删除题的标配，消灭"删头节点"的特判，值得形成肌肉记忆。