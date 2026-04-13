class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int len = intervals.size();
        if(intervals.empty())
        {
            return 0;
        }
        std::sort(intervals.begin(), intervals.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[1] < b[1];
              });

        int right = intervals[0][1];
        int ans = 1;

        for(int i = 1 ; i < len ; i++)
        {
            if(intervals[i][0] >= right)
            {
                ans++;
                right = intervals[i][1];
            }
        }

        return len - ans;
    }
};