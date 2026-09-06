# 28. Find the Index of the First Occurrence in a String

**Difficulty:** Easy  
**Topics:** Strings, String Matching  
**LeetCode:** [Link](https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/)

---

## Problem Statement

Given strings `haystack` and `needle`, return the index of the first occurrence of `needle` in `haystack`, or `-1` if not found.

**Example:**
```
Input:  haystack="sadbutsad", needle="sad"
Output: 0

Input:  haystack="leetcode", needle="leeto"
Output: -1
```

---

## Intuition & Approach

**Brute Force — Sliding Window:**
Try every starting position `i` in `haystack`. Extract substring of length `m` and compare with `needle`. Return first match.

Loop runs from `i=0` to `i=n-m` — no point starting beyond `n-m` since there aren't enough characters left.

**Dry run with `haystack="sadbutsad", needle="sad"`:**
```
i=0: "sad" == "sad" -> return 0 ✅
```

**Dry run with `haystack="leetcode", needle="leeto"`:**
```
i=0: "leetc" != "leeto"
i=1: "eetco" != "leeto"
i=2: "etcod" != "leeto"
i=3: "tcode" != "leeto"
return -1 ✅
```

---

## My Solution (Brute Force)

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();
        for (int i = 0; i <= n-m; i++) {
            if (haystack.substr(i, m) == needle) return i;
        }
        return -1;
    }
};
```

**Complexity:** O(n×m) time | O(m) space (substr creates copy)

---

## Optimal — KMP Algorithm O(n+m)

KMP precomputes a **failure function** (LPS array) for needle — tells us how many characters to skip on mismatch instead of restarting from scratch.

```cpp
int strStr(string haystack, string needle) {
    int n = haystack.size(), m = needle.size();
    // Build LPS (Longest Proper Prefix which is also Suffix)
    vector<int> lps(m, 0);
    for (int i = 1, j = 0; i < m; ) {
        if (needle[i] == needle[j]) lps[i++] = ++j;
        else if (j) j = lps[j-1];
        else lps[i++] = 0;
    }
    // Search
    for (int i = 0, j = 0; i < n; ) {
        if (haystack[i] == needle[j]) { i++; j++; }
        if (j == m) return i - j;
        else if (i < n && haystack[i] != needle[j]) {
            if (j) j = lps[j-1];
            else i++;
        }
    }
    return -1;
}
```

**Complexity:** O(n+m) time | O(m) space

---

## Mistakes to Avoid

- Loop condition `i < n-m` instead of `i <= n-m` — misses the last valid starting position
- Using `haystack.find(needle)` directly — valid in interviews but shows no understanding; explain the algorithm

---

## Pattern

**"Sliding window string match"** — Fix window size = needle length, slide across haystack. Brute force is O(nm). KMP optimizes to O(n+m) via failure function that avoids redundant comparisons.

KMP is a must-know for interviews — understand the LPS array concept even if you don't memorize the code.

Related:
- LC 459 - Repeated Substring Pattern (KMP application)
- LC 686 - Repeated String Match
