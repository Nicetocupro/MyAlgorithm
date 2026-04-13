## 2. 两数相加

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode();
        ListNode* temp = result;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int lastNum = 0;

        while (temp1 != nullptr || temp2 != nullptr) {
            if (temp1 != nullptr && temp2 != nullptr) {
                temp1->val = temp1->val + temp2->val + lastNum;
                lastNum = temp1->val / 10;
                temp1->val %= 10;
                temp->next = temp1;
                temp1 = temp1->next;
                temp2 = temp2->next;
            } else if (temp2 == nullptr) {
                
                temp1->val += lastNum;
                lastNum = temp1->val / 10;
                temp1->val %= 10;
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp2->val += lastNum;
                lastNum = temp2->val / 10;
                temp2->val %= 10;
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }

        if(lastNum)
        {
            temp->next = new ListNode(lastNum);
        }
        else 
        {
            temp->next = nullptr;
        }
        
        return result->next;
    }
};
```


### 现有代码的问题

**设计问题**：
- 直接修改了输入链表 `l1`/`l2` 的 `val`，破坏了入参，这在工程中是不好的习惯。
- `while` 里三个分支（`if/else if/else`）的逻辑高度重复——每支都在做"加法 + 进位 + 接链表"，只是操作的节点不同。

---

### 标准精简写法

核心技巧：**统一处理缺省值**，用 `val1/val2` 变量代替分支判断，再统一求和。

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy;          // 哑节点，避免处理头节点特例
        ListNode* cur = &dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int val = carry;
            if (l1) { val += l1->val; l1 = l1->next; }
            if (l2) { val += l2->val; l2 = l2->next; }

            carry = val / 10;
            cur->next = new ListNode(val % 10);  // 新建节点，不修改入参
            cur = cur->next;
        }

        return dummy.next;
    }
};
```

两者对比的关键改进：

| 维度 | 原代码 | 精简版 |
|---|---|---|
| 分支数 | 3个 if/else | 0个分支（统一处理）|
| 修改入参 | 会修改 `l1`/`l2` 的 val | 只读入参 |
| 进位最后处理 | 单独 if 在循环外 | `carry` 作为循环条件，自动处理 |
| 代码行数 | ~35 行 | ~10 行 |

---
