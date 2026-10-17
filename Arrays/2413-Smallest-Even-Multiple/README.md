# 2413. Smallest Even Multiple

**Difficulty:** Easy  
**Topics:** Arrays, Math  
**LeetCode:** [Link](https://leetcode.com/problems/smallest-even-multiple/)

---

## Problem Statement

Given positive integer `n`, return the smallest positive integer divisible by both `2` and `n`.

**Example:**
```
Input:  n=5  -> 10  (LCM of 2 and 5)
Input:  n=6  -> 6   (6 is already even)
```

---

## Intuition & Approach

LCM(2, n):
- If `n` is even → `n` itself (already divisible by 2)
- If `n` is odd → `2*n`

Or simply: `n % 2 == 0 ? n : 2*n`

---

## My Solution

```cpp
class Solution {
public:
    int smallestEvenMultiple(int n) {
        if (n % 2 == 0) return n;
        return 2*n;
    }
};
```

**Complexity:** O(1) time | O(1) space

---

## Pattern

**"LCM with small fixed number"** — LCM(2, n) = n if n is even, else 2n. Recognize fixed-number LCM as simple parity check.
