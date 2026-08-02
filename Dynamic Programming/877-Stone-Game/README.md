# 877. Stone Game

**Difficulty:** Medium  
**Topics:** Dynamic Programming, Math, Game Theory  
**LeetCode:** [Link](https://leetcode.com/problems/stone-game/)

---

## ⚠️ REVISIT THIS PROBLEM — Math trick used, DP not attempted yet

---

## Problem Statement

Alex and Lee take turns picking from either end of a piles array. Alex goes first. Whoever has the most stones wins. Both play optimally. Return `true` if Alex wins.

**Example:**
```
Input:  piles = [5,3,4,5]
Output: true
```

---

## Intuition & Approach (Math Trick)

**Key Insight:** `n` is always even. Split piles into:
- Even-indexed: piles[0], piles[2], piles[4]...
- Odd-indexed: piles[1], piles[3], piles[5]...

One group always has sum >= the other. Alex knows this upfront and can **always enforce** taking her preferred group:
- Want even-indexed? Take piles[0] first — Bob is forced to expose odd-indexed ends
- Want odd-indexed? Take piles[n-1] first — same logic

So Alex **always wins**. Return `true` unconditionally.

---

## My Solution (Math)

```cpp
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        return true;  // Alex always wins — see intuition
    }
};
```

---

## TODO — Solve with DP

The proper DP approach:
- `dp[i][j]` = max score difference (current player - opponent) for subarray `piles[i..j]`
- Transition: `dp[i][j] = max(piles[i] - dp[i+1][j], piles[j] - dp[i][j-1])`
- Return `dp[0][n-1] > 0`

**Attempt this and update the solution here.**

---

## Mistakes to Avoid

- Returning `true` in interviews without explaining WHY — zero marks without the reasoning
- Missing that n being even is the critical constraint enabling this trick

---

## Pattern

**Game Theory + Math Observation** — Before jumping to DP, check if problem constraints guarantee a fixed winner. Here even-length array + optimal play = always first player wins.

Related problems:
- LC 486 - Predict the Winner (n can be odd, need actual DP)
- LC 1140 - Stone Game II
- LC 1406 - Stone Game III
