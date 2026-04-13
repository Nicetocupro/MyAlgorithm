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