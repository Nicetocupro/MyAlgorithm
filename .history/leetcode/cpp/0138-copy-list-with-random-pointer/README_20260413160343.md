## 138. 随机链表的复制

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node dummy(0);
        Node* newTemp = &dummy;
        Node* prev = &dummy;
        Node* temp = head;
        std::unordered_map<Node*, Node*> myMap;

        while(temp != nullptr)
        {
            newTemp->next = new Node(temp->val);
            prev->next = newTemp->next;

            myMap[temp] = newTemp->next;
            temp = temp->next;
            newTemp = newTemp->next;
            prev = prev->next;
        }

        newTemp->next = nullptr;

        newTemp = dummy.next;
        temp = head;

        while(temp != nullptr)
        {
            if(temp->random == nullptr)
            {
                newTemp->random = nullptr;
            }
            else
            {
                newTemp->random = myMap[temp->random];
            }

            newTemp = newTemp->next;
            temp = temp->next;
        }

        return dummy.next;
    }
};
```

### 你的解法复杂度

| 项目 | 复杂度 |
|---|---|
| 时间 | O(n)，两次遍历 |
| 空间 | O(n)，哈希表存映射 |

这是哈希表解法的理论极限，**时间上无法再优化**，但空间可以压缩到 O(1)。

---

### 值得学习：O(1) 空间的交织节点法

这是此题最经典的进阶解法，核心思想是把新节点**插入到原节点的后面**，借助链表结构本身来存储映射关系，省去哈希表。

分三个步骤：

**第一步：交织复制**，在每个原节点后插入克隆节点

```
原来：  A  → B  → C  → null
之后：  A  → A' → B  → B' → C  → C' → null
```

**第二步：处理 random 指针**，此时 `node->next` 就是克隆节点，`node->random->next` 就是克隆节点的 random 目标

```
clone->random = original->random->next
```

**第三步：拆分链表**，把交织链表分离成原链表和克隆链表

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 第一步：每个节点后插入克隆节点
        Node* curr = head;
        while (curr) {
            Node* clone = new Node(curr->val);
            clone->next = curr->next;
            curr->next = clone;
            curr = clone->next;
        }

        // 第二步：设置 random 指针
        curr = head;
        while (curr) {
            if (curr->random)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 第三步：拆分链表
        Node dummy(0);
        Node* cloneTail = &dummy;
        curr = head;
        while (curr) {
            Node* clone = curr->next;
            curr->next = clone->next;   // 恢复原链表
            cloneTail->next = clone;    // 拼接克隆链表
            cloneTail = clone;
            curr = curr->next;
        }

        return dummy.next;
    }
};
```

---

### 两种解法对比

| 项目 | 你的哈希表法 | 交织节点法 |
|---|---|---|
| 时间复杂度 | O(n) | O(n) |
| 空间复杂度 | O(n) | O(1) |
| 代码复杂度 | 低，直观 | 中，需理解交织 |
| 会修改原链表 | 否 | 是（第三步恢复） |
| 面试推荐度 | ★★★★ 先写这个 | ★★★★★ 进阶亮点 |

---