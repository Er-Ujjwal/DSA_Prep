# 392. Is Subsequence

**Difficulty:** Easy  
**Topics:** Strings, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/is-subsequence/)

---

## Problem Statement

Given strings `s` and `t`, return `true` if `s` is a subsequence of `t`.

**Example:**
```
Input:  s="ace", t="abcde"
Output: true  (a_c_e in abcde)

Input:  s="aec", t="abcde"
Output: false
```

---

## Intuition & Approach

**Two pointer greedy:**
Pointer `i` on `s`, pointer `j` on `t`. When characters match, advance both. Always advance `j`. If `i` reaches end of `s` → all chars matched → true.

**Dry run with `s="ace", t="abcde"`:**
```
i=0(a), j=0(a): match → i=1, j=1
i=1(c), j=1(b): no match → j=2
i=1(c), j=2(c): match → i=2, j=3
i=2(e), j=3(d): no match → j=4
i=2(e), j=4(e): match → i=3
i==s.size() → return true ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0, j = 0;
        while (i < s.size() && j < t.size()) {
            if (s[i] == t[j]) i++;
            j++;
        }
        return i == s.size();
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Returning `j == t.size()` — wrong, check `i == s.size()` (all of s matched)
- Advancing `i` without advancing `j` on match — must advance both

---

## Pattern

**"Two pointer matching"** — Match elements of smaller sequence against larger. Greedy — take match whenever found. Classic subsequence check.

Related: LC 792 - Number of Matching Subsequences, LC 1143 - LCS
