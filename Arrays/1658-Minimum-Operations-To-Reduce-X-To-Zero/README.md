# 1658. Minimum Operations to Reduce X to Zero

**Difficulty:** Medium  
**Topics:** Arrays, Sliding Window & Two Pointers, Prefix Sum  
**LeetCode:** [Link](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

---

## Problem Statement

Given array `nums` and integer `x`, find the minimum number of operations to reduce `x` to zero, where each operation removes either the leftmost or rightmost element and subtracts it from `x`. Return `-1` if impossible.

**Example:**
```
Input:  nums=[1,1,4,2,3], x=5
Output: 2  (remove 3 and 2 from right)
```

---

## Intuition & Approach

**Key Insight — Flip the problem:**
Instead of finding minimum elements to remove from ends summing to `x`, find the **maximum length subarray** in the middle summing to `total - x`.

Why? Elements removed from ends + middle subarray = entire array. Minimizing removed elements = maximizing middle subarray length.

**target = total - x**

Edge cases:
- `target < 0` → impossible (x > total) → return -1
- `target == 0` → remove everything → return n

**Sliding window** finds longest subarray with sum = target (works since all elements positive).

**Answer:** `n - maxlen`

**Dry run with `[1,1,4,2,3], x=5`:**
```
total=11, target=11-5=6

Sliding window for sum=6:
right=0: sum=1
right=1: sum=2
right=2: sum=6 == target -> maxlen=3 (window [0..2])
right=3: sum=8 > 6 -> shrink: sum=7, left=1
         sum=7 > 6 -> shrink: sum=6, left=2
         sum=6 == target -> maxlen=max(3,2)=3
right=4: sum=9 > 6 -> shrink: sum=5, left=3
         sum != 6

maxlen=3, return n-maxlen = 5-3 = 2 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;
        if (target < 0) return -1;
        if (target == 0) return n;
        int left = 0, sum = 0, maxlen = -1;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target && left <= right)
                sum -= nums[left++];
            if (sum == target) maxlen = max(maxlen, right-left+1);
        }
        return maxlen == -1 ? -1 : n - maxlen;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Trying to simulate removing from both ends — exponential, completely wrong approach
- Forgetting `target == 0` edge case — without it, sliding window finds nothing (empty subarray has sum 0 but length 0, not handled)
- Returning `maxlen` instead of `n - maxlen` — maxlen is the middle subarray, not the answer

---

## Pattern

**"Complement + Sliding Window"** — When minimizing elements from ends summing to x, flip to maximizing the middle subarray summing to `total - x`. Classic indirect sliding window.

Related:
- LC 1477 - Find Two Non-Overlapping Subarrays With Target Sum
- LC 560 - Subarray Sum Equals K (prefix sum variant)
- LC 1358 - Substrings Containing All Three Characters
