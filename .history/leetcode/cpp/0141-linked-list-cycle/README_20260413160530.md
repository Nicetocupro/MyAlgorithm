## 141\. 环形链表

```cpp
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
    bool hasCycle(ListNode *head) {
        // 快慢指针 或者 set
        std::unordered_set<ListNode*> mySet;
        ListNode* temp = head;
        while(temp != nullptr)
        {
            if(!mySet.contains(temp))
            {
                mySet.insert(temp);
            }
            else
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }
};
```

```cpp
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
    bool hasCycle(ListNode *head) {
        // 快慢指针 或者 set
        if(head == nullptr)
        {
            return false;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(slow != nullptr && fast != nullptr)
        {
            if(slow == fast)
            {
                return true;
            }
            slow = slow->next;
            fast = fast->next;
            if(fast != nullptr)
            {
                fast = fast->next;
            }
        }

        return false;
    }
};
```

### 1\. 快慢指针法的细微优化

第二段代码已经是 $O(1)$ 空间复杂度的最优思路了，但代码实现上可以更精简，减少逻辑判断。

- **初始化逻辑：** 你将 `fast` 初始化为 `head->next`，这需要额外判断 `head` 是否为空。通常更简洁的做法是让 `slow` 和 `fast` 都从 `head` 出发。
- **循环条件：** 只需要检查 `fast` 和 `fast->next` 即可。因为 `fast` 走得快，如果没环，它一定先撞到 `nullptr`。

* * *

### 2\. 进阶学习建议：Floyd 判圈算法的深度

要达到“最高效率”，不仅是写出代码，还要理解其数学背后的逻辑。

#### 为什么快慢指针一定能相遇？

想象两个人在环形跑道上跑步：

1.  **相对速度：** 慢指针步长为 1，快指针步长为 2。相对于慢指针，快指针的速度是 1。
2.  **必然相遇：** 只要有环，快指针最终会进入环并在后面“追赶”慢指针。因为相对速度为 1，它们之间的距离每走一步就缩短 1，所以**绝对不会跳过彼此**，必然会相遇。

#### 优化后的推荐写法 (C++)

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
        
        ListNode *slow = head;
        ListNode *fast = head;

        // 只要 fast 和 fast->next 不为空，就可以继续跑
        while (fast && fast->next) {
            slow = slow->next;          // 走一步
            fast = fast->next->next;    // 走两步
            
            if (slow == fast) {         // 相遇了，说明有环
                return true;
            }
        }

        return false; // fast 走到头了，说明没环
    }
};
```
