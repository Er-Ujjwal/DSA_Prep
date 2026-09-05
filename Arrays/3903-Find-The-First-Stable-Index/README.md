# 3903. Find the First Stable Index

**Difficulty:** Medium  
**Topics:** Arrays, Prefix/Suffix  
**LeetCode:** [Link](https://leetcode.com/problems/find-the-first-stable-index/)

---

## ⚠️ REVISIT — Approach looked up, needs deeper understanding

---

## Problem Statement

Given array `nums` and integer `k`, find the **smallest index `i`** such that the difference between the maximum of `nums[0..i]` and the minimum of `nums[i..n-1]` is ≤ k. Return `-1` if no such index exists.

**Example:**
```
Input:  nums=[3,1,4,1,5,9], k=3
Output: 2
prefixMax[2]=4, suffixMin[2]=1, 4-1=3<=3 ✅
```

---

## Intuition & Approach

**Key Insight:** For index `i` to be stable:
```
max(nums[0..i]) - min(nums[i..n-1]) <= k
```

Precompute:
- `suffixMin[i]` = min of `nums[i..n-1]` — built right to left
- `prefixMax` = running max of `nums[0..i]` — maintained on the fly

Scan left to right, first index satisfying condition is the answer.

**Why prefix max and suffix min?**
- prefix max grows monotonically left to right
- suffix min shrinks monotonically right to left
- Their difference at index `i` gives the range `[0..i]` max vs `[i..n-1]` min

**Dry run with `[3,1,4,1,5,9]`, k=3:**
```
suffixMin = [1,1,1,1,5,9]

i=0: prefixMax=3, 3-1=2<=3 ✅ -> return 0?
Wait: let me recheck suffixMin[0]=min(3,1,4,1,5,9)=1
3-1=2<=3 -> return 0

Hmm, expected output is 2. Need to recheck problem statement.
```

*(Verify exact condition on LC — may involve strict inequality or different indexing)*

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

## Mistakes to Avoid

- Building suffixMin left to right — must go right to left since each entry depends on entries to its right
- Using `suffixMin[i+1]` without checking bounds — handle last element separately as base case

---

## Pattern

**"Prefix max + Suffix min"** — When condition involves both a running max from left and running min from right, precompute suffix min, then scan with running prefix max. O(n) instead of O(n²).

Related:
- LC 2948 - Lexicographically Smallest Array (sort + group)
- LC 2091 - Removing Min and Max (index tracking)
