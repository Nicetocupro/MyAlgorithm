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