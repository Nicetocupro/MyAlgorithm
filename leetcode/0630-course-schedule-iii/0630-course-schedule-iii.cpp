//优先队列方法
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int len = courses.size();
        if (len == 0) {
            return 0;
        }

        // 按照结束时间排序
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        // 优先队列用于存储当前已选课程（按照课程持续时间的最大堆）
        priority_queue<int> pq;

        int time = 0; // 当前已选课程的总时间

        // 遍历课程
        for (int i = 0; i < len; ++i) {
            // 将课程加入当前已选课程
            time += courses[i][0];
            pq.push(courses[i][0]);

            // 如果当前总时间超过课程的结束时间，则需要移除一门课程
            if (time > courses[i][1]) {
                time -= pq.top(); // 移除持续时间最长的课程
                pq.pop();
            }
        }

        // 堆的大小即为选取的课程数量
        return pq.size();
    }
};