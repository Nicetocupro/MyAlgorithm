## [200\. 岛屿数量](https://leetcode.cn/problems/number-of-islands/)

这是我用的bfs深度有线搜索的答案，但是还是比较耗时间

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int sum = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(visited[i][j] == false)
                {
                    visited[i][j] = true;
                    if(grid[i][j] == '1')
                    {
                        // 将所有的同一陆地遍历完
                        sum++;
                        stack<pair<int, int>> myStack;
                        myStack.push(std::make_pair(i, j));
                        while(!myStack.empty())
                        {
                            auto temp_pair = myStack.top();
                            myStack.pop();
                            int temp_row = temp_pair.first;
                            int temp_col = temp_pair.second;
                            for(auto it : directions)
                            {
                                int visited_row = temp_row + it.first;
                                int visited_col = temp_col + it.second;
                                if(visited_row >= 0 && visited_row < n && visited_col >= 0 && visited_col < m  && !visited[visited_row][visited_col])
                                {
                                    if(grid[visited_row][visited_col] == '1')
                                    {
                                        myStack.push(std::make_pair(visited_row, visited_col));
                                    }
                                    visited[visited_row][visited_col] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return sum;
    }
};
```

```cpp
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res=0;
        int m=grid.size(),n=grid[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;
    }

    void dfs(vector<vector<char>>& grid,int i,int j)
    {
        int m=grid.size(),n=grid[0].size();
        if(i<0||j<0||i>=m||j>=n)
        {
            return;
        }
        if(grid[i][j]=='0')
        {
            return;
        }
        grid[i][j]='0';
         dfs(grid, i + 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i - 1, j);
        dfs(grid, i, j - 1);
    }

};
```

这样更快些，但是会改变grid的数组

### 1\. 空间效率：从 O(M \* N)\$ 降至 O(1)（不计递归栈)

这是最大的进步。

- **旧代码**：你创建了一个同等大小的 `visited` 矩阵。在 C++ 中，`vector<vector<bool>>` 即使有特殊优化，依然会消耗大量内存。更重要的是，初始化这个矩阵需要 \$O(M \\times N)\$ 的时间。
    
- **新代码**：直接在原地图 `grid` 上操作。当你访问过一块陆地 `'1'`，直接把它改成 `'0'`（就像是把岛屿“淹没”了）。这样不需要额外的辅助数组，极大地节省了空间。
    

### 2\. 时间效率：消除分配与辅助容器开销

- **内存分配**：旧代码在循环开始前要分配并初始化 `visited` 内存，这是非常耗时的系统调用。新代码“拿起就用”。
    
- **容器开销**：旧代码手动维护了一个 `std::stack`。`std::stack` 默认基于 `std::deque`，频繁的 `push` 和 `pop` 涉及到内存块的管理。新代码利用\*\*系统调用栈（System Call Stack）\*\*进行递归，处理速度通常比手动维护容器快得多。
    
- **分支预测更优**：新代码的 `dfs` 函数在入口处就进行了边界和内容的统一检查，逻辑路径更集中。
    

### 3\. 代码可读性与维护性

新代码采用了“**Sink the Island（淹没岛屿）**”的策略，逻辑非常符合直觉：

- **主循环**：发现陆地 \$\\rightarrow\$ 计数 +1 \$\\rightarrow\$ 把它所在的整块陆地全部抹除。
    
- **DFS 函数**：只负责扩散和抹除，职责极其单一明确。
    

* * *

### 核心对比总结

| **特性** | **旧版本 (迭代 + visited)** | **新版本 (递归 + 原地修改)** |
| --- | --- | --- |
| **额外空间** | \$O(M \\times N)\$ | \$O(1)\$ (不计系统栈) |
| **分配耗时** | 高 (初始化嵌套 vector) | 零   |
| **逻辑复杂度** | 较高 (需管理 pair、stack、方向向量) | 极低 (递归四方向) |
| **安全性** | 稳定，无栈溢出风险 | 极深递归可能栈溢出 (但本题规模 300x300 没问题) |
