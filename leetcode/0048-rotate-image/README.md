## [48\. 旋转图像](https://leetcode.cn/problems/rotate-image/)

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int top = 0, left = 0, right = matrix.size() - 1, bottom = matrix.size() - 1;

        while(1)
        {
            if(top >= bottom && left >= right)
            {
                break;
            }

            // 顶部复制
            vector<int> temp;
            for(int i = left; i <= right; i++)
            {
                temp.push_back(matrix[top][i]);
            }

            // 左侧到上部
            for(int i = top, j = right; i <= bottom && j >= left; i++, j--)
            {
                matrix[top][j] = matrix[i][left];
            }

            // 下部到左
            for(int i = left, j = top; i <= right && j <= bottom; i++, j++)
            {
                matrix[j][left] = matrix[bottom][i];
            }

            // 右边到下
            for(int i = bottom, j = left; i >= top && j <= right; i--, j++)
            {
                matrix[bottom][j] = matrix[i][right];
            }

            // 需要注意有一个元素被覆盖，不符合

            matrix[bottom][right] = temp.back();

            // 顶部到右侧
            for(int i = 0, j = top; i < temp.size() && j <= bottom; i++, j++)
            {
                matrix[j][right] = temp[i];
            }
            
            left++;
            top++;
            right--;
            bottom--;
        }
    }
};
```

上面写的虽然对，但是逻辑上可能有点问题，更简单的方式是让矩阵按照对角线转置，然后每行左右翻转

```cpp
void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    // 第一步：沿主对角线转置
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            swap(matrix[i][j], matrix[j][i]);
    // 第二步：每行左右翻转
    for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
}
```

&nbsp;