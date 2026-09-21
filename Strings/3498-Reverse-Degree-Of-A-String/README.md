# 3498. Reverse Degree of a String

**Difficulty:** Easy  
**Topics:** Strings, Math  
**LeetCode:** [Link](https://leetcode.com/problems/reverse-degree-of-a-string/)

---

## Problem Statement

Given string `s`, return the sum of `reverse_position(s[i]) * (i+1)` for all indices, where `reverse_position('a')=26, 'b'=25, ..., 'z'=1`.

**Example:**
```
Input:  s="abc"
Output: 1*26 + 2*25 + 3*24 = 26+50+72 = 148
```

---

## Intuition & Approach

Reverse position of character `c` = `'z' - c + 1`.
Multiply by 1-indexed position `(i+1)`. Sum all up.

**Dry run with `"abc"`:**
```
i=0: ('z'-'a'+1)*(1) = 26*1 = 26
i=1: ('z'-'b'+1)*(2) = 25*2 = 50
i=2: ('z'-'c'+1)*(3) = 24*3 = 72
ans = 148 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int reverseDegree(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++)
            ans += ('z' - s[i] + 1) * (i + 1);
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Pattern

**"Character mapping + weighted sum"** — Map characters to values, multiply by position weight, accumulate. Common in string scoring problems.

Related:
- LC 1119 - Remove Vowels from a String
- LC 1941 - Check if All Characters Have Equal Number of Occurrences
