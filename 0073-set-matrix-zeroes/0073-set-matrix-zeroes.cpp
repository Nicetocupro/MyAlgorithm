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