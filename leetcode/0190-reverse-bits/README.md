# reverse-bits

---

## 代码分析

你的思路是**双指针从两端向中间交换位**，逻辑正确，终止条件也没有问题。主要可以优化的地方是**交换逻辑过于冗长**。

### 可改进：交换逻辑用 XOR 简化

当前四个 if 分支可以用经典的 XOR bit-swap 替代，只在两位不同时才翻转：

```cpp
uint32_t reverseBits(uint32_t n) {
    unsigned int left = 1, right = 1u << 31;
    while (left < right) {
        int lb = (n & left) ? 1 : 0;
        int rb = (n & right) ? 1 : 0;
        if (lb != rb) {
            n ^= left;
            n ^= right;
        }
        left <<= 1;
        right >>= 1;
    }
    return n;
}
```

---

## 更好的方法

### 方法一：逐位移位（最经典，O(32)）

```cpp
uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;
    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1);
        n >>= 1;
    }
    return result;
}
```

每次把 `n` 的最低位"喂"给 `result` 的最低位，同时 `result` 左移腾出空间。

---

### 方法二：分治位翻转（O(1) 位操作，最优雅）

```cpp
uint32_t reverseBits(uint32_t n) {
    n = (n >> 16) | (n << 16);
    n = ((n & 0xFF00FF00) >> 8)  | ((n & 0x00FF00FF) << 8);
    n = ((n & 0xF0F0F0F0) >> 4)  | ((n & 0x0F0F0F0F) << 4);
    n = ((n & 0xCCCCCCCC) >> 2)  | ((n & 0x33333333) << 2);
    n = ((n & 0xAAAAAAAA) >> 1)  | ((n & 0x55555555) << 1);
    return n;
}
```

思路是**每次把问题规模减半**：

```
原始:   [31..16] [15..0]
第1步:  [15..0]  [31..16]   ← 交换两个半段
第2步:  交换每个半段内的两个字节
第3步:  交换每字节内的两个 nibble
...以此类推直到交换每对相邻 bit
```

这个方法特别适合硬件/嵌入式或需要对同一函数调用百万次的场景。

---

## 总结对比

| 方法 | 迭代次数 | 推荐场景 |
|------|--------|----------|
| 你的双指针 | 16 次 | 思路直观，可用 XOR 精简 |
| 逐位移位 | 32 次 | ✅ 面试首选，最易理解 |
| 分治位操作 | O(1) | ✅ 进阶，性能敏感场景 |