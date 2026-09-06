# 115. Distinct Subsequences

**Difficulty:** Hard  
**Topics:** Dynamic Programming, Strings  
**LeetCode:** [Link](https://leetcode.com/problems/distinct-subsequences/)

---

## Problem Statement

Given strings `s` and `t`, return the number of distinct subsequences of `s` which equals `t`.

**Example:**
```
Input:  s="rabbbit", t="rabbit"
Output: 3
(three ways to delete one 'b' to get "rabbit")
```

---

## Intuition & Approach

**`dp[i][j]` = number of ways to form `t[0..j-1]` using `s[0..i-1]`**

**Base case:** `dp[i][0] = 1` — empty `t` can always be formed (delete everything from s)

**Transition:**
- Always: `dp[i][j] = dp[i-1][j]` — skip `s[i-1]`, don't use it
- If `s[i-1] == t[j-1]`: also add `dp[i-1][j-1]` — use `s[i-1]` to match `t[j-1]`

**Dry run with `s="rabb", t="rab"`:**
```
     ""  r  a  b
""    1  0  0  0
r     1  1  0  0
a     1  1  1  0
b     1  1  1  1
b     1  1  1  2
```
`dp[4][3] = 2` ✅ (two ways to pick "rab" from "rabb")

**Overflow fix:** Intermediate values can exceed `long long` for extreme inputs (all same characters). Cap at `INT_MAX` since LC guarantees final answer fits in `int`.

---

## My Solution

```cpp
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
        for (int i = 0; i <= n; i++) dp[i][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if (s[i-1] == t[j-1]) dp[i][j] += dp[i-1][j-1];
                dp[i][j] = min(dp[i][j], (long long)INT_MAX); // prevent overflow
            }
        }
        return (int)dp[n][m];
    }
};
```

**Complexity:** O(n×m) time | O(n×m) space

---

## Mistakes to Avoid

- Using `int` for dp — intermediate values overflow even `long long` for extreme inputs; cap at INT_MAX
- `dp[0][j] = 0` for `j > 0` — correct (empty s can't form non-empty t), handled by default initialization
- Forgetting `dp[i][j] += dp[i-1][j-1]` is conditional — only when characters match

---

## Pattern

**"2D DP — string matching / counting subsequences"** — `dp[i][j]` depends on `dp[i-1][j]` (skip) and `dp[i-1][j-1]` (match). Classic template for subsequence counting problems.

Related:
- LC 1143 - Longest Common Subsequence
- LC 72 - Edit Distance
- LC 516 - Longest Palindromic Subsequence
