# 136. Single Number

**Difficulty:** Easy  
**Topics:** Arrays, Bit Manipulation  
**LeetCode:** [Link](https://leetcode.com/problems/single-number/)

---

## Problem Statement

Every element appears twice except one. Find that one. O(n) time, O(1) space.

**Example:**
```
Input:  nums = [4,1,2,1,2]
Output: 4
```

---

## Intuition & Approach

XOR all elements. Pairs cancel (`a^a=0`), identity holds (`0^a=a`). Only the unique element remains.

```
4^1^2^1^2 = 4^(1^1)^(2^2) = 4^0^0 = 4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int x : nums) ans ^= x;
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Pattern

**"XOR cancellation"** — pairs cancel, unique survives. Foundation for LC 260 (two uniques) and LC 3702 (XOR > 0).
