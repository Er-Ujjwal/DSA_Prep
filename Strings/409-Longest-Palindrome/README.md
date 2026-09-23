# 409. Longest Palindrome

**Difficulty:** Easy  
**Topics:** Strings, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/longest-palindrome/)

---

## Problem Statement

Given a string `s`, return the length of the longest palindrome that can be built using its characters.

**Example:**
```
Input:  s="abccccdd"
Output: 7  -> "dccaccd"
```

---

## Intuition & Approach

**Frequency count:**
- Even frequency characters → use all of them (pairs fit perfectly)
- Odd frequency characters → use `freq-1` (drop one to make it even)
- If any odd frequency exists → add 1 for center character

**Dry run with `"abccccdd"`:**
```
freq: a=1, b=1, c=4, d=2
size: c->4, d->2, a->0(+1-1), b->0(+1-1) = 6
odd=true -> size+1 = 7 ✅
```

---

## My Solution (fixed)

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c-'a']++;
        int size = 0;
        bool odd = false;
        for (int x : freq) {
            if (x % 2 == 0) size += x;
            else {
                size += x-1;
                odd = true;
            }
        }
        if (odd) size++;
        return size;
    }
};
```

**Bug fix:** Added braces around `else` block — without them, `odd = true` ran unconditionally regardless of whether `x` was odd or even.

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Missing braces in else block — `odd = true` must be inside else, not standalone
- Forgetting the +1 for center — any single odd-frequency character can sit in the middle

---

## Pattern

**"Frequency + palindrome construction"** — Even pairs fill both halves, one odd character goes in center. Same foundation as LC 2384 and LC 3517.

Related:
- LC 2384 - Largest Palindromic Number
- LC 3517 - Smallest Palindrome Rearrangement
