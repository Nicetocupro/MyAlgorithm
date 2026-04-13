## [43\. 字符串相乘](https://leetcode.cn/problems/multiply-strings/)

```cpp
class Solution {
public:
    string multiply(string num1, string num2) 
    {
        if(num2 == "0" || num1 == "0")
        {
            return "0";
        }

        string result = "";
        int step = 0;
        int lastNum = 0;
        while(step <= num1.size() + num2.size() - 2)
        {
            int temp = 0;
            for(int i = 0; i <= step; i++)
            {
                if(i < num1.size() && (step - i) < num2.size())
                {
                    temp += (num1[num1.size() - i - 1] - '0') * (num2[num2.size() - step + i - 1] - '0');
                }
            }
            temp += lastNum;
            lastNum = temp / 10;
            temp = temp % 10;
            result = std::to_string(temp) + result;
            step++;
        }
        if(lastNum)
        {
            result = std::to_string(lastNum) + result;
        }

        return result;
    }
};
```

### 代码分析

你的算法思路本身是对的——按位做卷积（类似多项式乘法），时间复杂度是 **O(m×n)**，这没问题。

效率瓶颈在于**字符串操作**，主要有两处：

* * *

### 问题一：字符串头部插入（最严重）

```cpp
result = std::to_string(temp) + result;  // ❌ 每次都要把整个 result 往后移
```

C++ 的 `string` 底层是连续内存，**头部插入是 O(n)**，加上外层循环，整体字符串操作变成 **O((m+n)²)**，远超算法本身的 O(m×n)。

* * *

### 问题二：对单个数字调用 `std::to_string`

```cpp
std::to_string(temp)  // ❌ 为了一个 0~9 的数字，走了完整的数字转字符串流程
```

单个数字直接用 `'0' + temp` 转字符即可，完全不需要 `to_string`。

* * *

### 优化版本

```cpp
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int m = num1.size(), n = num2.size();
        int total = m + n - 1;
        string result;
        result.reserve(total + 1);  // ✅ 预分配内存，避免多次 realloc

        int lastNum = 0;
        for (int step = 0; step < total; step++) {
            int temp = lastNum;
            for (int i = 0; i <= step; i++) {
                int j = step - i;
                if (i < m && j < n) {
                    temp += (num1[m - i - 1] - '0') * (num2[n - j - 1] - '0');
                }
            }
            lastNum = temp / 10;
            result += (char)('0' + temp % 10);  // ✅ 尾部追加，O(1) 摊销
        }

        if (lastNum) result += (char)('0' + lastNum);

        reverse(result.begin(), result.end());  // ✅ 一次翻转代替所有头部插入
        return result;
    }
};
```

**核心改动**：改为尾部 `+=` 追加，最后 `reverse` 一次，把字符串操作从 O((m+n)²) 降回 O(m+n)。

* * *

### 进阶：还有哪些值得学习的方向

| 方向  | 说明  |
| --- | --- |
| **预分配结果数组** | 用 `vector<int> pos(m+n, 0)` 直接存每个位置的值，无需 carry 跨步传递，代码更清晰 |
| **Karatsuba 算法** | 分治思想，O(n^1.585)，适合极长字符串 |
| **FFT/NTT 大数乘法** | O(n log n)，工业级大数库（如 Python 的 int）的底层原理 |
| **`reserve` 的使用习惯** | 已知最终大小时提前预留，减少内存重分配 |
