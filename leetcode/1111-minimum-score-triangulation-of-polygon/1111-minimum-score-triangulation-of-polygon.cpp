class Solution {
public:
    int minScoreTriangulation(vector<int>& values) 
    {
        int len = values.size();
        vector<vector<int>> t(len, vector<int>(len, 0));

        for(int r = 2 ; r < len ; r++)
        {
            for(int i = 0 ; i < len - r; i++)
            {
                int j = i + r;
                t[i][j] = INT_MAX;
                for (int k = i + 1; k < j; ++k)
                {
                    t[i][j] = min(t[i][j], t[i][k] + t[k][j] + values[i] * values[k] * values[j]);
                }
            }
        }
        return t[0][len - 1];
    }
};