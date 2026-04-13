## 25. K 个一组翻转链表

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        std::stack<ListNode*> myStack;
        ListNode* temp = head;

        for(int i = 0; i < k; i++)
        {
            if(temp == nullptr)
            {
                return head;
            }

            myStack.push(temp);
            temp = temp->next;
        }

        ListNode* nextNode = myStack.top()->next;
        ListNode dummy(0);
        temp = &dummy;

        for(int i = 0; i < k; i++)
        {
            temp->next = myStack.top();
            myStack.pop();
            temp = temp->next;
        }

        temp->next = reverseKGroup(nextNode, k);

        return dummy.next;
    }
};
```

### 你的解法分析

**思路是对的**，用栈来反转 k 个节点很直观。但有一个 **bug**：

```cpp
ListNode* nextNode = myStack.top()->next;
```

此时栈顶是**最后入栈的节点**（即第 k 个节点），它的 `next` 才是下一组的起始。这个逻辑本身没问题。但更严谨的写法应该在 push 之前就保存好 `temp`（也就是 push 完 k 个节点后，`temp` 本身就已经指向下一组了），所以可以直接用 `temp` 代替 `nextNode`，当前写法多用了一次 `myStack.top()->next` 的访问，逻辑上等价但不够简洁。

**空间复杂度是主要问题**：栈用了 O(k)，加上递归调用栈 O(n/k)，整体空间是 O(n)，不如原地翻转。

---

### 更推荐的两种写法

#### 写法一：递归 + 原地翻转（面试首选）

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 检查是否有 k 个节点
        ListNode* check = head;
        for (int i = 0; i < k; i++) {
            if (!check) return head;  // 不足 k 个，直接返回
            check = check->next;
        }

        // 原地翻转 k 个节点（三指针）
        ListNode* prev = nullptr;
        ListNode* curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // head 现在是翻转后的尾节点，接上下一组的递归结果
        head->next = reverseKGroup(curr, k);
        return prev;  // prev 是翻转后的新头节点
    }
};
```

空间 O(n/k)（递归栈），逻辑清晰，是面试中最推荐的写法。

---

#### 写法二：纯迭代（O(1) 空间，生产环境首选）

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0, head);
        ListNode* groupPrev = &dummy;

        while (true) {
            // 找到第 k 个节点
            ListNode* kth = getKth(groupPrev, k);
            if (!kth) break;

            ListNode* groupNext = kth->next;

            // 翻转 [groupPrev->next, kth] 这一段
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;
            while (curr != groupNext) {
                ListNode* tmp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = tmp;
            }

            // 连接 groupPrev 和新的头部
            ListNode* tail = groupPrev->next;  // 翻转后此节点变成尾部
            groupPrev->next = kth;
            groupPrev = tail;
        }
        return dummy.next;
    }

private:
    ListNode* getKth(ListNode* curr, int k) {
        while (curr && k-- > 0) curr = curr->next;
        return curr;
    }
};
```

空间 O(1)，没有任何额外数据结构。
