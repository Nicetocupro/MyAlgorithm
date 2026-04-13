class Solution
{
public:
    int findMaximizedCapital(int k, int w, vector<int> &profits, vector<int> &capital)
    {
        vector<pair<int, int>> projects;
        for (int i = 0; i < profits.size(); i++)
        {
            projects.push_back({capital[i], profits[i]});
        }
        // 按照资本从小到大排序
        sort(projects.begin(), projects.end());
        // 最大堆，用来存储可投资的项目的利润
        priority_queue<int> maxProfitPQ;

        // 初始化当前资本
        int currentCapital = w;
        int i = 0; // 用于迭代所有项目

        while (k--)
        {
            // 将所有当前资本以下的项目加入到最大堆中
            while (i < projects.size() && projects[i].first <= currentCapital)
            {
                maxProfitPQ.push(projects[i].second);
                i++;
            }

            // 如果最大堆不为空，则从堆中取出一个利润最大的项目
            if (!maxProfitPQ.empty())
            {
                currentCapital += maxProfitPQ.top();
                maxProfitPQ.pop();
            }
            else
            {
                // 如果没有可投资的项目，直接跳出循环
                break;
            }
        }

        return currentCapital;
    }
};