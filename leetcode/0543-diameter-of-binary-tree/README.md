# 0543-diameter-of-binary-tree

## 代码评价

整体来说，这份代码**思路清晰、逻辑正确**，核心思想——"在后序遍历中顺手更新全局最大值"——是解这道题的标准最优解法，时间复杂度 O(n)，空间复杂度 O(h)（h 为树高）。

---

## 可以改进的地方

### 1. 成员变量的问题（最重要）

```cpp
// ❌ 当前写法：maxDiameter 是成员变量
int maxDiameter = 0;
```

如果同一个 `Solution` 对象被**多次调用** `diameterOfBinaryTree()`，`maxDiameter` 不会重置，会产生错误结果。

```cpp
// ✅ 改法一：在函数内部初始化
int diameterOfBinaryTree(TreeNode* root) {
    maxDiameter = 0;  // 每次调用前重置
    deepOfNode(root);
    return maxDiameter;
}

// ✅ 改法二（更推荐）：用局部变量 + 引用传递，彻底避免成员变量
int diameterOfBinaryTree(TreeNode* root) {
    int maxDiameter = 0;
    deepOfNode(root, maxDiameter);
    return maxDiameter;
}

int deepOfNode(TreeNode* root, int& maxDiameter) { ... }
```

---

### 2. 命名规范

```cpp
// ❌ 函数名描述不够准确
int deepOfNode(TreeNode* root)

// ✅ 更语义化
int maxDepth(TreeNode* root)
int height(TreeNode* root)
```

---

### 3. 更新逻辑可以简化

```cpp
// ❌ 手动 if 判断
if(total > maxDiameter) {
    maxDiameter = total;
}

// ✅ 一行搞定
maxDiameter = std::max(maxDiameter, leftDeep + rightDeep);
```

---

### 改进后的完整版本

```cpp
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        height(root, maxDiameter);
        return maxDiameter;
    }

private:
    int height(TreeNode* root, int& maxDiameter) {
        if (!root) return 0;
        
        int left  = height(root->left,  maxDiameter);
        int right = height(root->right, maxDiameter);
        
        maxDiameter = std::max(maxDiameter, left + right);
        
        return std::max(left, right) + 1;
    }
};
```

---

## 值得延伸学习的相关题目

这道题是**后序遍历 + 全局状态维护**的经典模板，掌握后可以解一系列同类题：

| 题号 | 题目 | 关联点 |
|------|------|--------|
| 104 | Maximum Depth of Binary Tree | 本题 `height()` 的子问题 |
| 124 | Binary Tree Maximum Path Sum | 完全相同的框架，值换成路径和 |
| 687 | Longest Univalue Path | 加了"值相同"的约束条件 |
| 1522 | Diameter of N-Ary Tree | 本题推广到 N 叉树 |
| 863 | All Nodes Distance K in Binary Tree | 直径思维的延伸 |

**重点推荐 124 题**——它和本题框架几乎一模一样，但难度上升一个台阶，是理解这类"递归返回值 vs 全局更新"模式的最好练习。