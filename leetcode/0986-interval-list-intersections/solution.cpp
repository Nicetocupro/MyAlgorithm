/*
 * @lc app=leetcode id=986 lang=cpp
 *
 * [986] Interval List Intersections
 */
#ifdef LOCAL
#include <iostream>
#include <vector>

using namespace std;
#endif

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> result;

        int i = 0, j = 0;

        while(i < firstList.size() && j < secondList.size())
        {
            int begin1 = firstList[i][0];
            int end1 = firstList[i][1];
            int begin2 = secondList[j][0];
            int end2 = secondList[j][1];

            if(begin1 <= begin2 && end1 >= begin2)
            {
                vector<int> temp;
                temp.push_back(begin2);
                if(end1 <= end2)
                {
                    temp.push_back(end1);
                    i++;
                }
                else
                {
                    temp.push_back(end2);
                    j++;
                }

                result.push_back(temp);
            }
            else if(begin2 <= begin1 && end2 >= begin1)
            {
                vector<int> temp;
                temp.push_back(begin1);
                if(end2 <= end1)
                {
                    temp.push_back(end2);
                    j++;
                }
                else
                {
                    temp.push_back(end1);
                    i++;
                }
                result.push_back(temp);
            }
            else
            {
                if(end1 <= end2)
                {
                    i++;
                }
                else
                {
                    j++;
                }
            }
        }

        return result;
    }
};

#ifdef LOCAL
int main()
{
    vector<vector<int>> firstList = {
        {0, 2},
        {5, 10},
        {13, 23},
        {24, 25},
    };

    vector<vector<int>> secondList = {
        {1, 5},
        {8, 12},
        {15, 24},
        {25, 26},
    };    

    Solution s;

    vector<vector<int>> result = s.intervalIntersection(firstList, secondList);

    std::cout << result.size() << std::endl;
    for(int i = 0; i < result.size(); i++)
    {
        std::cout << result[i][0] << " " << result[i][1] << std::endl;
    }

    return 0;
}
#endif
// @lc code=end

