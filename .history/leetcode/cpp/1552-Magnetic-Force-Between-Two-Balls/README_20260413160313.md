## 1552. 两球之间的磁力

这个是PDD的面试题，极难，答案如下

```cpp
class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        std::sort(position.begin(), position.end());
        int lower = 0;
        int high = position.back() - position.front();

        while (lower < high) {
            int mid = lower + (high - lower + 1) / 2;

            int count = 1;
            int prev = position[0];

            for(int i = 0; i < position.size(); i++)
            {
                if(position[i] - prev >= mid)
                {
                    count++;
                    prev = position[i];
                }
            }

            if(count >= m)
            {
                lower = mid;
            }
            else
            {
                high = mid - 1;
            }
        }

        return lower;
    }
};
```
