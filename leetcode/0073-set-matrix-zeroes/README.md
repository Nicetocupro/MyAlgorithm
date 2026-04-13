## [73\. 矩阵置零](https://leetcode.cn/problems/set-matrix-zeroes/)

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int, int>> dp;
        for(int i = 0; i < matrix.size(); i++)
        {
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    dp.push_back(std::make_pair(i, j));
                }
            }
        }

        for(auto pair: dp)
        {
            for(int i = 0; i < matrix[0].size(); i++)
            {
                matrix[pair.first][i] = 0;
            }

            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][pair.second] = 0;
            }
        }
    }
};
```

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        std::set<int> mySets;

        for(int i = 0; i < matrix.size(); i++)
        {
            bool row = false;
            for(int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    row = true;
                    mySets.insert(j);
                }
            }

            if(row)
            {
                for(int j = 0; j < matrix[0].size(); j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for(auto mySet: mySets)
        {
            for(int i = 0; i < matrix.size(); i++)
            {
                matrix[i][mySet] = 0;
            }
        }
    }
};
```

上面是我写的两种方法

下面是O1的解法，运用第一列和第一行作为标记列和行（天才！）

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Step 1: 先记录第一行、第一列自身是否含零
        bool firstRowZero = false;
        bool firstColZero = false;
        
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0) { firstRowZero = true; break; }
        
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0) { firstColZero = true; break; }
        
        // Step 2: 用第一行/列记录其余位置的零
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;  // 标记第i行需清零
                    matrix[0][j] = 0;  // 标记第j列需清零
                }
            }
        }
        
        // Step 3: 根据第一行/列的标记，清零其余位置
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        
        // Step 4: 最后处理第一行/列自身
        if (firstRowZero)
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
        
        if (firstColZero)
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};
```
