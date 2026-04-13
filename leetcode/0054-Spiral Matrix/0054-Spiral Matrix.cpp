class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int x = 0, v = 0, step = 0;
        int max_x = matrix.size() - 1;
        int min_x = 0;
        int max_v = matrix[0].size() - 1;
        int min_v = 0;
        bool flag_x = false, flag_v= false, flag_total = false;
        while(step < matrix.size() * matrix[0].size())
        {
            result.push_back(matrix[x][v]);
            // std::cout << matrix[x][v] << std::endl;
            // 代表需要水平移动
            if(!flag_total)
            {
                // 代表向右移动
                if(!flag_v)
                {
                    if(v == max_v)
                    {
                        x++;
                        min_x++;
                        flag_v = true;
                        flag_total = true;
                    }
                    else
                    {
                        v++;
                    }
                }
                else
                {
                    if(v == min_v)
                    {
                        x--;
                        max_x--;
                        flag_v = false;
                        flag_total = true;
                    }
                    else
                    {
                        v--;
                    }
                }
            }
            else {
               // 代表向右移动
                if(!flag_x)
                {
                    if(x == max_x)
                    {
                        v--;
                        max_v--;
                        flag_x = true;
                        flag_total = false;
                    }
                    else
                    {
                        x++;
                    }
                }
                else
                {
                    if(x == min_x)
                    {
                        v++;
                        min_v++;
                        flag_x = false;
                        flag_total = false;
                    }
                    else
                    {
                        x--;
                    }
                }
            }
            step++;
        }

        return result;
    }
};