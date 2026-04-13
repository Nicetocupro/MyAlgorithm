class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        int len1 = board.size();
        int len2 = board[0].size();
        vector<vector<bool>> dp(len1, vector<bool>(len2, true));

        if (!checkWordInBoard(board, word))
        {
            return false;
        }

        for (int i = 0; i < len1; ++i)
        {
            for (int j = 0; j < len2; ++j)
            {
                if (board[i][j] == word[0])
                {
                    dp[i][j] = false;
                    if (solve(board, word, i, j, 1, dp))
                    {
                        return true;
                    }
                    dp[i][j] = true;
                }
            }
        }
        return false;
    }

private:
    bool checkWordInBoard(vector<vector<char>> &board, const string &word)
    {
        unordered_set<char> boardChars;
        for (const auto &row : board)
        {
            for (char c : row)
            {
                boardChars.insert(c);
            }
        }

        for (char c : word)
        {
            if (boardChars.find(c) == boardChars.end())
            {
                return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, const string &word, int pos_i, int pos_j, int pos, vector<vector<bool>> &dp)
    {
        if (pos == word.size())
        {
            return true;
        }

        static const vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        for (const auto &dir : directions)
        {
            int new_i = pos_i + dir.first;
            int new_j = pos_j + dir.second;
            if (new_i >= 0 && new_i < board.size() && new_j >= 0 && new_j < board[0].size() && board[new_i][new_j] == word[pos] && dp[new_i][new_j])
            {
                dp[new_i][new_j] = false;
                if (solve(board, word, new_i, new_j, pos + 1, dp))
                {
                    return true;
                }
                dp[new_i][new_j] = true;
            }
        }

        return false;
    }
};