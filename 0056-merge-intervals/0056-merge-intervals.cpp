class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;

        sort(intervals.begin(), intervals.end(), [](const& vector<int> interval1, const& vector<int>interval2){
            if(interval1[0] == interval2[0])
            {
                return interval1[1] < interval2[1];
            }
            return interval1[0] < interval2[0];
        });

        vector<int> temp = intervals[0];
        
        for(int i = 1; i < intervals.size(); i++)
        {
            if(temp[1] >= intervals[i][0])
            {
                if(temp[1] <= intervals[i][1])
                {
                    temp[1] = intervals[i][1];
                }
                continue;
            }
            else
            {
                result.push_back(temp);
                temp = intervals[i];
            }
        }

        result.push_back(temp);

        return result;
    }
};