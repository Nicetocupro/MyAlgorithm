## [238\. 除了自身以外数组的乘积](https://leetcode.cn/problems/product-of-array-except-self/)

首先是利用前后缀进行乘积，但是这个并不是最优解，还可以考虑不用额外空间开销实现

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> result;
        
        prefix[0] = 1;
        suffix[nums.size() - 1] = 1;

        for(int i = 1; i < nums.size(); ++i)
        {
            prefix[i] = prefix[i - 1] * nums[i - 1];
        }

        for(int i = nums.size() - 2; i >= 0; --i)
        {
            suffix[i] = suffix[i + 1] * nums[i + 1];
        }

        for(int i = 0; i < nums.size(); ++i)
        {
            result.push_back(suffix[i] * prefix[i]);
        }

        return result;
    }
};
```

下面这种办法不需要进行额外开销，并且速度更快

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(), 1);

        int left = 1;
        int right = 1;

        for(int i = 0; i < nums.size(); ++i)
        {
            answer[i] *= left;
            left *= nums[i];
        }

        for(int i = nums.size() - 1 ; i >= 0; --i)
        {
            answer[i] *= right;
            right *= nums[i];
        }

        return answer;
    }
};
```

### 两份代码对比分析

#### 问题本质

`result[i]` = 左边所有数的积 × 右边所有数的积

```
nums   = [1,  2,  3,  4]

prefix = [1,  1,  2,  6]   // prefix[i] = nums[0..i-1] 的积
suffix = [24, 12, 4,  1]   // suffix[i] = nums[i+1..n-1] 的积
result = [24, 12, 8,  6]
```

* * *

#### 你的代码：「显式前后缀数组」

```cpp
prefix[0] = 1;
suffix[n-1] = 1;
// 分别建两个数组，再合并
result[i] = prefix[i] * suffix[i];
```

思路非常清晰，**把"前缀积"和"后缀积"的概念直接映射成代码**，可读性强，是理解这道题最自然的方式。

**代价：** 额外空间 O(n) + O(n) = O(n)，开了三个数组。

* * *

#### 别人的代码：「滚动变量压缩」

关键洞察：**不需要把前缀/后缀数组完整存下来**，因为最终只用一次。

```cpp
// 第一遍：把前缀积直接写入 answer
int left = 1;
for(int i = 0; i < n; ++i) {
    answer[i] = left;   // 此时 left = nums[0..i-1] 的积
    left *= nums[i];
}

// 第二遍：用滚动的 right 乘进去
int right = 1;
for(int i = n-1; i >= 0; --i) {
    answer[i] *= right;  // 此时 right = nums[i+1..n-1] 的积
    right *= nums[i];
}
```

两遍扫描合并了"建数组"和"使用数组"两个步骤，**用单个变量代替整条数组**。

* * *

#### 执行过程对比（nums = \[1,2,3,4\]）

**第一遍（写入前缀积）：**

```
i=0: answer[0]=1,  left=1
i=1: answer[1]=1,  left=2
i=2: answer[2]=2,  left=6
i=3: answer[3]=6,  left=24
→ answer = [1, 1, 2, 6]
```

**第二遍（乘入后缀积）：**

```
i=3: answer[3]*=1  → 6,   right=4
i=2: answer[2]*=4  → 8,   right=12
i=1: answer[1]*=12 → 12,  right=24
i=0: answer[0]*=24 → 24,  right=24
→ answer = [24, 12, 8, 6]  ✅
```

* * *

#### 核心差异

|     | 你的代码 | 别人的代码 |
| --- | --- | --- |
| **空间** | O(n)，三个数组 | O(1)，复用 answer |
| **可读性** | ⭐⭐⭐⭐⭐ 概念直接 | ⭐⭐⭐ 需要理解滚动 |
| **是否需要提前存完整前后缀** | 是   | 否   |
| **适合** | 理解阶段 | 面试/优化阶段 |

* * *

#### 你需要掌握的内容

**1\. 「滚动变量」优化思想**

当你只需要**从左到右用一次**前缀信息时，不需要存整个数组，一个变量滚动累乘即可。这个模式在很多 DP 优化中也出现：

```
前缀数组  →  单个滚动变量
dp[i] = f(dp[i-1])  →  prev = f(prev)
```

**2\. 「复用 answer 数组」意识**

题目要求返回一个新数组，这个数组本身就可以当"草稿纸"用，不需要再额外开 prefix/suffix。**先写一遍，再原地修改**，是常见的空间压缩手法。