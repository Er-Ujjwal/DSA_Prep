# 198. House Robber

**Difficulty:** Medium  
**Topics:** Dynamic Programming  
**LeetCode:** [Link](https://leetcode.com/problems/house-robber/)

---

## Problem Statement

Given an array `nums` representing money in each house, return the maximum amount you can rob without robbing **two adjacent houses**.

**Example:**
```
Input:  nums = [2,7,9,3,1]
Output: 12  (rob house 0,2,4 -> 2+9+1=12)

Input:  nums = [1,2,3,1]
Output: 4   (rob house 0,2 -> 1+3=4)
```

---

## Intuition & Approach

**At each house `i`, two choices:**
- **Rob it:** take `nums[i]` + best from `i+2` onwards (can't rob adjacent)
- **Skip it:** take best from `i+1` onwards

`f(i)` = max money from index `i` to end.

**Recurrence:**
```
f(i) = max(nums[i] + f(i+2),   // rob house i
                      f(i+1))   // skip house i
f(i) = 0 if i >= n             // base case
```

**Memoize** with `dp[i]` to avoid recomputing overlapping subproblems.

**Dry run with `[2,7,9,3,1]`:**
```
f(4) = max(1+f(6), f(5)) = max(1,0) = 1
f(3) = max(3+f(5), f(4)) = max(3,1) = 3
f(2) = max(9+f(4), f(3)) = max(10,3) = 10
f(1) = max(7+f(3), f(2)) = max(10,10) = 10
f(0) = max(2+f(2), f(1)) = max(12,10) = 12 ✅
```

---

## My Solution (Top-Down Memoization)

```cpp
class Solution {
public:
    int dp[401];
    int f(int i, vector<int>& nums) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int r  = nums[i] + f(i+2, nums);  // rob
        int nr = f(i+1, nums);             // skip
        return dp[i] = max(r, nr);
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return f(0, nums);
    }
};
```

**Complexity:** O(n) time | O(n) space

---

## Bottom-Up Alternative (Tabulation)

```cpp
int rob(vector<int>& nums) {
    int n = nums.size();
    if (n == 1) return nums[0];
    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    for (int i = 2; i < n; i++)
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    return dp[n-1];
}
```

**Space optimized (O(1)):**
```cpp
int rob(vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int curr = max(x + prev2, prev1);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
```

---

## Mistakes to Avoid

- Using global `dp[401]` without `memset` — stale values from previous test cases
- Base case `i >= n` returning -1 instead of 0 — -1 is the uninitialized sentinel, not a valid answer
- Forgetting the space-optimized O(1) version — interviewers love asking for it as follow-up

---

## Pattern

**"Linear DP — take or skip"** — At each index, decide to include or exclude. Result depends only on previous 1-2 states. Classic template that extends to:
- LC 213 - House Robber II (circular array)
- LC 337 - House Robber III (binary tree)
- LC 740 - Delete and Earn (same recurrence, different setup)
