## [160\. 相交链表](https://leetcode.cn/problems/intersection-of-two-linked-lists/)

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        std::unordered_set<ListNode*> set;
        ListNode* temp = headA;

        while(temp != NULL)
        {
            set.insert(temp);
            temp = temp->next;
        }

        temp = headB;
        while(temp != NULL)
        {
            if(set.contains(temp))
            {
                return temp;
            }
            temp = temp->next;
        }
       
        return NULL;
    }
};
```

本来是暴力求解，后来发现使用unordered_set(不是set,set是平衡二叉树，搜索更慢)更快，记录不重复元素，题解后来更巧妙，用数学证明

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
    /**
     * 找到两个单链表的相交节点
     * 
     * @param headA 链表A的头节点
     * @param headB 链表B的头节点
     * @return 相交节点，如果不相交则返回nullptr
     */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 边界情况：任一链表为空，不可能相交
        if (!headA || !headB) {
            return nullptr;
        }
        
        // 初始化两个指针，分别指向两个链表的头节点
        ListNode *ptrA = headA;
        ListNode *ptrB = headB;
        
        /**
         * 核心算法：双指针遍历法
         * 
         * 算法原理：
         * 1. 两个指针分别从各自链表头开始遍历
         * 2. 当指针到达链表末尾时，切换到另一个链表的头部继续遍历
         * 3. 这样每个指针都会遍历完两个链表
         * 4. 如果链表相交，它们会在相交点相遇
         * 5. 如果不相交，它们会同时到达nullptr
         * 
         * 数学证明：
         * 设链表A独有部分长度=a，链表B独有部分长度=b，公共部分长度=c
         * 指针A遍历的路径：a + c + b
         * 指针B遍历的路径：b + c + a
         * 由于总路径长度相同，它们会在相交点相遇
         */
        while (ptrA != ptrB) {
            // 指针A：如果到达链表A末尾，切换到链表B头节点
            // 否则继续前进
            ptrA = (ptrA == nullptr) ? headB : ptrA->next;
            
            // 指针B：如果到达链表B末尾，切换到链表A头节点
            // 否则继续前进
            ptrB = (ptrB == nullptr) ? headA : ptrB->next;
        }
        
        // 返回结果：ptrA和ptrB要么都指向相交节点，要么都为nullptr
        return ptrA;
    }
};
```

