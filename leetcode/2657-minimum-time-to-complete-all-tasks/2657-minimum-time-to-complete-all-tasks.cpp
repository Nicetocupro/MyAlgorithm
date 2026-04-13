class Solution
{
public:
    int findMinimumTime(vector<vector<int>> &tasks)
    {
        sort(tasks.begin(), tasks.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int maxLong = 0;

        for(unsigned int i = 0 ; i < tasks.size() ; i++)
        {
            maxLong = max(maxLong , tasks[i][1]);
        }
        vector<bool> dp(maxLong + 1 , false);
        for(unsigned int i = 0 ; i < tasks.size() ; i++)
        {
            int start = tasks[i][0] , end = tasks[i][1] , duration = tasks[i][2];
            for(int j = start ; j <= end ; j++)
            {
                if(duration == 0)
                {
                    break;
                }
                if(dp[j])
                {
                    duration--;
                }
            }
            for(int j = end ; j >= start ; j--)
            {
                if(duration == 0)
                {
                    break;
                }
                if(dp[j] == false)
                {
                    dp[j] = true;
                    duration--;
                }
            }

        }

        int sum = 0;
        for(int i = 0 ; i < maxLong + 1 ; i++)
        {
            if(dp[i])
            {
                sum++;
            }
        }
        return sum;
    }
};