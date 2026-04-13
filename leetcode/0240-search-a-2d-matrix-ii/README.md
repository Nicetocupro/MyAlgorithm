##  [240\. 搜索二维矩阵 II](https://leetcode.cn/problems/search-a-2d-matrix-ii/)

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // 所有数都是左下角的数字最大
        int n = matrix.size();
        int m = matrix[0].size();
        int row = 0, col = 0;

        if(target < matrix[0][0])
        {
            return false;
        }
        else if(target == matrix[0][0])
        {
            return true;
        }

        while(target >= matrix[0][col])
        {
            col++;
            if(col == m)
            {
                break;
            }
        }

        col = col - 1;

        while(target > matrix[row][col])
        {
            row++;
            if(row == n)
            {
                break;
            }
        }

        std::cout << row << " " << col << std::endl;

        if(row < 0 || row >= n || col < 0 || col >= m)
        {
            return false;
        }

        for(int i = 0; i <= col; i++)
        {
            if(target == matrix[row][i])
            {
                return true;
            }
        }

        for(int i = row + 1; i < n; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(target == matrix[i][j])
                {
                    return true;
                }
            }
        }

        return false;

    }
};
```

上面的方法是暴力解法，比较复杂，不如下面巧妙-

```cpp
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = m - 1;
        while(i < n && j >= 0)
        {
            if(mat[i][j] > target) j--;
            else if(mat[i][j] < target) i++;
            else return true;
        }
        return false;
    }
};
```

### 对比分析

#### 题解的核心思路：从右上角出发

```
从右上角 mat[0][m-1] 开始：
- 当前值 > target  →  向左移（j--）
- 当前值 < target  →  向下移（i++）
- 当前值 == target →  找到了
```

这利用了矩阵的性质：右上角的元素**同行最大、同列最小**，每次比较都能**排除一整行或一整列**。

* * *

### 你的代码可以学习的地方

**1\. 没有抓住核心不变量（最重要）**

题解始终维护一个简洁的不变量：*当前位置右上方的矩形已被排除*。 你的代码分了多个阶段（先定列、再定行、再暴力扫描），逻辑分散，也更容易出边界错误。

**2\. 暴力兜底说明搜索策略不完整**

```cpp
// 你最后还需要两层循环扫描剩余区域
for(int i = 0; i <= col; i++) { ... }
for(int i = row+1; i < n; i++)
    for(int j = 0; j < col; j++) { ... }
```

如果前面的策略是正确且完备的，根本不需要这个兜底。**需要兜底往往意味着前面的策略有漏洞。**

**3\. 特判可以删掉**

```cpp
if(target < matrix[0][0]) return false;
else if(target == matrix[0][0]) return true;
```

题解的 while 循环天然覆盖这两种情况，无需单独处理。**好的算法通常不需要特判边界。**

* * *

### 一句话总结

> 你的思路是"先缩小范围再搜索"，方向对，但缩小得不够彻底；  
> 题解的思路是"每步必排除一行或一列"，**每次比较的信息利用率是 100%**。

遇到行列均有序的矩阵，优先想**右上角或左下角**出发的线性扫描。