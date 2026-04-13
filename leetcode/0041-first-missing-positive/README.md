## [41\. 缺失的第一个正数](https://leetcode.cn/problems/first-missing-positive/)

&nbsp;

下面是我所写的方法

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int found = 1;
        std::sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0)
            {
                continue;
            }
            if(found == nums[i])
            {
                found++;
            }
            else if(nums[i] <= found)
            {
                continue;
            }
            else
            {
                break;
            }
        }

        return found;
    }
};
```

## 复杂度对比

|     | 时间复杂度 | 空间复杂度 |
| --- | --- | --- |
| 题解（原地哈希） | O(n) | O(1) |
| 你的解法（排序） | O(n log n) | O(1) |

**题解更优**，瓶颈在于你的排序是 O(n log n)。

* * *

## 核心思路对比

**题解 — 原地哈希（桶排序思想）**

把每个数放到它"应该在"的位置，即把值 `k` 放到下标 `k-1` 处，然后扫一遍找第一个不匹配的位置。

```cpp
// 把 nums[i] 换到 nums[nums[i]-1] 的位置，直到无法继续
while (nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
    swap(nums[i], nums[nums[i] - 1]);
}
```

整理后数组理想状态：`[1, 2, 3, 4, ...]`，第一个 `nums[i] != i+1` 就是答案。

**你的解法 — 排序 + 线性扫描**

排序后顺序遍历，用 `found` 追踪当前期望的最小正整数，逻辑清晰易懂。

* * *

## 你的解法的优点

虽然性能略逊，但：

- ✅ **可读性极强**，逻辑一目了然
- ✅ **正确处理了重复值**（`else if (nums[i] <= found) continue`）
- ✅ 面试中作为"先想到的解法"完全合格，再优化到 O(n) 展示思维过程更好

* * *
