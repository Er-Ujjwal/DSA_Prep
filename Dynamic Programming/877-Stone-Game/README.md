# 877. Stone Game

**Difficulty:** Medium  
**Topics:** Dynamic Programming, Math, Game Theory  
**LeetCode:** [Link](https://leetcode.com/problems/stone-game/)

---

## Problem Statement

Alex and Lee take turns picking from either **end** of a piles array. Alex goes first. Whoever has the most stones wins. Both play optimally. Return `true` if Alex wins.

**Example:**
```
Input:  piles = [5,3,4,5]
Output: true
```

---

## Intuition & Approach

**`dp[i][j]` = max score difference (current player - opponent) for subarray `piles[i..j]`**

At each state, the current player picks either `piles[i]` or `piles[j]`, then the opponent plays optimally on the remaining subarray.

**Transition:**
```
dp[i][j] = max(piles[i] - dp[i+1][j],   // pick left, opponent gets dp[i+1][j] advantage
               piles[j] - dp[i][j-1])    // pick right, opponent gets dp[i][j-1] advantage
```

**Base case:** `dp[i][i] = piles[i]` — only one pile, current player takes it all.

**Answer:** `dp[0][n-1] > 0` means Alex (first player) ends up with more stones.

**Fill order:** By increasing subarray length (len=1 → len=n).

**Dry run with `[5,3,4,5]`:**
```
len=1: dp[0][0]=5, dp[1][1]=3, dp[2][2]=4, dp[3][3]=5

len=2:
dp[0][1] = max(5-3, 3-5) = max(2,-2) = 2
dp[1][2] = max(3-4, 4-3) = max(-1,1) = 1
dp[2][3] = max(4-5, 5-4) = max(-1,1) = 1

len=3:
dp[0][2] = max(5-dp[1][2], 4-dp[0][1]) = max(5-1, 4-2) = max(4,2) = 4
dp[1][3] = max(3-dp[2][3], 5-dp[1][2]) = max(3-1, 5-1) = max(2,4) = 4

len=4:
dp[0][3] = max(5-dp[1][3], 5-dp[0][2]) = max(5-4, 5-4) = max(1,1) = 1

dp[0][3]=1 > 0 -> Alex wins ✅
```

---

## Two Approaches

**Approach 1 — Math trick (O(1)):**
```cpp
// n is always even, Alex can always guarantee the larger group
// (even-indexed or odd-indexed piles), so she always wins
return true;
```
⚠️ Only works because n is even in this specific problem. Useless in interviews without explanation.

**Approach 2 — Proper DP (O(n²)):**
```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) dp[i][i] = piles[i];
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = max(piles[i] - dp[i+1][j],
                               piles[j] - dp[i][j-1]);
            }
        }
        return dp[0][n-1] > 0;
    }
};
```

**Complexity:** O(n²) time | O(n²) space

---

## Mistakes to Avoid

- Filling dp by index (i from 0 to n) instead of by length — causes accessing uncomputed states
- Using `dp[i][j] = max(piles[i] + dp[i+1][j], piles[j] + dp[i][j-1])` — wrong! dp stores **difference**, not absolute score. Subtracting opponent's advantage is correct.
- Returning `dp[0][n-1] >= 0` instead of `> 0` — problem says "more stones", strict inequality

---

## Pattern

**"Interval DP — optimal play on subarrays"** — Fill by increasing subarray length. Current player maximizes score difference, opponent minimizes it. Template reused across all pick-from-ends game problems.

Related:
- LC 1510 - Stone Game IV (pick perfect squares)
- LC 486 - Predict the Winner (same template, n can be odd)
- LC 1140 - Stone Game II
