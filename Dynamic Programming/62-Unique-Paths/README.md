# 62. Unique Paths

**Difficulty:** Medium  
**Topics:** Dynamic Programming, Math  
**LeetCode:** [Link](https://leetcode.com/problems/unique-paths/)

---

## Problem Statement

A robot starts at top-left of an `m x n` grid and wants to reach bottom-right. It can only move **right or down**. Return the number of unique paths.

**Example:**
```
Input:  m=3, n=7
Output: 28
```

---

## Intuition & Approach

**Top-down DP (Memoization):**
To reach `(i,j)`, robot must come from either `(i-1,j)` (up) or `(i,j-1)` (left).

```
fxn(i,j) = fxn(i-1,j) + fxn(i,j-1)
```

**Base cases:**
- `(0,0)` → 1 way (already there)
- `i<0 || j<0` → 0 ways (out of bounds)

**Dry run with `m=3, n=3`:**
```
fxn(2,2) = fxn(1,2) + fxn(2,1)
fxn(1,2) = fxn(0,2) + fxn(1,1)
fxn(0,2) = fxn(-1,2) + fxn(0,1) = 0 + 1 = 1
fxn(1,1) = fxn(0,1) + fxn(1,0) = 1+1 = 2
fxn(1,2) = 1+2 = 3
fxn(2,1) = 3 (symmetric)
fxn(2,2) = 3+3 = 6 ✅
```

---

## My Solution (Top-Down)

```cpp
class Solution {
public:
    vector<vector<int>> dp;
    int fxn(int i, int j) {
        if (i==0 && j==0) return 1;
        if (i<0 || j<0) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = fxn(i-1, j) + fxn(i, j-1);
    }
    int uniquePaths(int m, int n) {
        dp.assign(m, vector<int>(n, -1));
        return fxn(m-1, n-1);
    }
};
```

**Bottom-Up Alternative:**
```cpp
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 1));
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[m-1][n-1];
}
```

**Math O(1) solution:**
Answer = C(m+n-2, m-1) — choose m-1 down moves from m+n-2 total moves.

**Complexity:** O(m×n) time | O(m×n) space

---

## Mistakes to Avoid

- Base case `i==0 || j==0` returning 1 in top-down — correct for bottom-up but in top-down only `(0,0)` is the true base; first row/col recurse naturally
- Forgetting `dp.assign()` before recursive call — uninitialized dp causes wrong answers

---

## Pattern

**"Grid DP — count paths"** — `dp[i][j] = dp[i-1][j] + dp[i][j-1]`. Foundation for LC 63 (with obstacles), LC 64 (min path sum), LC 1301 (max score paths).

Related:
- LC 63 - Unique Paths II (with obstacles)
- LC 64 - Minimum Path Sum
- LC 1301 - Number of Paths with Max Score
