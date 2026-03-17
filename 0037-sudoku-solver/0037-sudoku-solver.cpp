class Solution
{
public:
    void solveSudoku(vector<vector<char>> &board)
    {
        solve(board);
    }

    bool solve(vector<vector<char>> &board)
    {
        vector<bool> dp(10, false);
        int i, j, pos_i = 0, pos_j = 0; // i是行 ， j是列
        for (i = 0; i < 9; i++)
        {
            if (i % 3 == 0)
            {
                pos_i++;
            }
            for (j = 0; j < 9; j++)
            {
                if (j % 3 == 0)
                {
                    pos_j++;
                }
                if (board[i][j] - '.' == 0)
                {
                    break;
                }
            }
            if (board[i][j] - '.' == 0)
            {
                break;
            }
            pos_j = 0;
        }

        if (i == 9)
        {
            return true;
        }

        for (int k = 0; k < 9; k++)
        {
            if (board[i][k] - '.' != 0)
            {
                dp[board[i][k] - '0'] = true;
            }
        }

        for (int k = 0; k < 9; k++)
        {
            if (board[k][j] != '.')
            {
                dp[board[k][j] - '0'] = true;
            }
        }

        for (int k = 3 * pos_i - 3; k < 3 * pos_i; k++)
        {
            for (int t = 3 * pos_j - 3; t < 3 * pos_j; t++)
            {
                if (board[k][t] - '.' != 0)
                {
                    dp[board[k][t] - '0'] = true;
                }
            }
        }

        int u;
        for (u = 1; u < 10; u++)
        {
            if (dp[u] == false)
            {
                board[i][j] = char(u + '0');
                if (solve(board))
                {
                    return true;
                }
                else
                {
                    board[i][j] = '.';
                    continue;
                }
            }
        }
        return false;
    }
};