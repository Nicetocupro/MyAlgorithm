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