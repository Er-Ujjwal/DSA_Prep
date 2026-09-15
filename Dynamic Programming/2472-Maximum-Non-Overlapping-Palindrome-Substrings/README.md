# 2472. Maximum Number of Non-Overlapping Palindrome Substrings

**Difficulty:** Hard  
**Topics:** Dynamic Programming, Strings  
**LeetCode:** [Link](https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/)

---

## ⚠️ REVISIT — Approach looked up

---

## Problem Statement

Given string `s` and integer `k`, find the maximum number of **non-overlapping** palindrome substrings of length **at least k**.

**Example:**
```
Input:  s="abaccdbbd", k=3
Output: 2
```

---

## Intuition & Approach

**Two-phase DP:**

**Phase 1 — Precompute all palindromes:**
`pal[l][r]` = true if `s[l..r]` is a palindrome.

Build by length:
- Length 1: always palindrome
- Length 2: palindrome if `s[l]==s[r]`
- Length >2: palindrome if `s[l]==s[r]` AND `pal[l+1][r-1]`

**Phase 2 — Interval DP for max non-overlapping count:**
`dp[i]` = max palindromes using first `i` characters.

For each position `i`:
- Skip it: `dp[i] = dp[i-1]`
- End a palindrome at `i`: try all starting positions `j` where substring `[j..i-1]` is a palindrome of length ≥ k
  - `dp[i] = max(dp[i], dp[j] + 1)`

The constraint `j <= i-k` ensures length `i-j >= k`.

**Dry run with `s="abac", k=2`:**
```
Phase 1 palindromes: "a","b","a","c","aba","abac"?
pal[0][0]=T, pal[1][1]=T, pal[2][2]=T, pal[3][3]=T
pal[0][2]: s[0]='a'==s[2]='a', pal[1][1]=T -> pal[0][2]=T ("aba")

Phase 2:
dp[0]=0
dp[1]: dp[0]=0, j=0: len=1<2 skip -> dp[1]=0
dp[2]: dp[1]=0, j=0: pal[0][1]? s[0]='a'!=s[1]='b' -> no
dp[3]: dp[2]=0, j=0: pal[0][2]=T, len=3>=2 -> dp[3]=max(0, dp[0]+1)=1
dp[4]: dp[3]=1, j=0: pal[0][3]? no. j=1: pal[1][3]? no. j=2: pal[2][3]? no -> dp[4]=1
return 1
```

---

## My Solution

```cpp
class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l+len-1 < n; l++) {
                int r = l+len-1;
                if (s[l]==s[r] && (len<=2 || pal[l+1][r-1]))
                    pal[l][r] = true;
            }
        }
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i-1];
            for (int j = 0; j <= i-k; j++) {
                if (pal[j][i-1])
                    dp[i] = max(dp[i], dp[j]+1);
            }
        }
        return dp[n];
    }
};
```

**Complexity:** O(n²) time | O(n²) space

---

## Mistakes to Avoid

- Building palindrome table by index instead of length — causes accessing uncomputed states
- Using `j < i-k` instead of `j <= i-k` — off by one, misses palindromes of exactly length k
- Forgetting `dp[i] = dp[i-1]` — must carry forward the best without using position i

---

## Pattern

**"Precompute palindromes + interval DP"** — When problems involve palindrome substrings, first build `pal[l][r]` table in O(n²), then use it in a second DP pass. Classic two-phase approach.

Related:
- LC 516 - Longest Palindromic Subsequence
- LC 647 - Palindromic Substrings
- LC 5 - Longest Palindromic Substring
