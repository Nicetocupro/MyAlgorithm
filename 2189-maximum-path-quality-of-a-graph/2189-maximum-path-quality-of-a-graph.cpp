class Solution
{
public:
    int ans = 0;

    int maximalPathQuality(vector<int> &values, vector<vector<int>> &edges, int maxTime)
    {
        int n = values.size();
        vector<vector<pair<int, int>>> g(n);
        for (const auto &edge : edges)
        {
            g[edge[0]].emplace_back(edge[1], edge[2]);
            g[edge[1]].emplace_back(edge[0], edge[2]);
        }

        vector<bool> visited(n, false);
        visited[0] = true;
        dfs(0, 0, values[0], g, maxTime, visited, values);
        return ans;
    }

private:
    void dfs(int u, int time, int value, vector<vector<pair<int, int>>> &g, int maxTime, vector<bool> &visited, vector<int> &values)
    {
        if (u == 0)
        {
            ans = max(ans, value);
        }

        for (const auto &[v, dist] : g[u])
        {
            if (time + dist <= maxTime)
            {
                bool wasVisited = visited[v];
                if (!wasVisited)
                {
                    visited[v] = true;
                    dfs(v, time + dist, value + values[v], g, maxTime, visited, values);
                    visited[v] = false;
                }
                else
                {
                    dfs(v, time + dist, value, g, maxTime, visited, values);
                }
            }
        }
    }
};