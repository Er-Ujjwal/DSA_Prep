# 3904. Find the First Stable Index II

**Difficulty:** Medium  
**Topics:** Arrays, Prefix/Suffix  
**LeetCode:** [Link](https://leetcode.com/problems/find-the-first-stable-index-ii/)

---

## ⚠️ REVISIT — Approach looked up, needs deeper understanding (see LC 3903)

---

## Problem Statement

Part II of LC 3903. Same problem — find smallest index `i` such that:
```
max(nums[0..i]) - min(nums[i..n-1]) <= k
```
Return `-1` if no such index exists. Larger constraints than Part I.

---

## Intuition & Approach

**Identical approach to LC 3903** — prefix max + suffix min.

The solution works for both parts since the algorithm is already O(n) — optimal for any constraint size.

See LC 3903 README for full explanation and dry run.

---

## My Solution

```cpp
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> suffixMin(n);
        suffixMin[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--)
            suffixMin[i] = min(nums[i], suffixMin[i+1]);
        int prefixMax = 0;
        for (int i = 0; i < n; i++) {
            prefixMax = max(nums[i], prefixMax);
            if (prefixMax - suffixMin[i] <= k) return i;
        }
        return -1;
    }
};
```

**Complexity:** O(n) time | O(n) space

---

## Pattern

Same as LC 3903 — **"Prefix max + Suffix min"**. When Part I and Part II share the same optimal approach, the O(n) solution scales naturally to larger constraints.

➡️ See LC 3903 for full intuition and dry run.
