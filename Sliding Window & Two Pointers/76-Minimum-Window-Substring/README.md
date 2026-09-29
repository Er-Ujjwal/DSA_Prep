# 76. Minimum Window Substring

**Difficulty:** Hard  
**Topics:** Strings, Sliding Window & Two Pointers, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/minimum-window-substring/)

---

## Problem Statement

Given strings `s` and `t`, find the minimum window substring of `s` that contains all characters of `t`. Return `""` if no such window exists.

**Example:**
```
Input:  s="ADOBECODEBANC", t="ABC"
Output: "BANC"
```

---

## Intuition & Approach

**Sliding window with frequency maps:**

1. Build frequency map of `t`
2. Expand `right` — when a needed character is found, decrement its count in need map; if count hits 0, decrement `formed` (characters fully satisfied)
3. When `formed == required` (all characters satisfied), try to shrink from `left`
4. Track minimum window throughout

**Key variables:**
- `required` = number of unique chars in `t`
- `formed` = number of unique chars currently satisfied in window
- `need` = frequency map of remaining needed chars

**Dry run with `s="ADOBECODEBANC", t="ABC"`:**
```
need={A:1,B:1,C:1}, required=3, formed=0

Expand until formed==3:
...window reaches "ADOBEC" -> formed=3, ans="ADOBEC"(len=6)
Shrink: remove 'A' -> formed=2, stop
Expand: ...find 'A' at index 10 -> "DOBECODEBA" formed=3
Shrink: remove 'D','O','B'... until "BANC" -> ans="BANC"(len=4)
return "BANC" ✅
```

---

## My Solution

```cpp
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()) return "";
        unordered_map<char, int> need;
        for (char c : t) need[c]++;
        int required = need.size();
        int formed = 0, left = 0;
        unordered_map<char, int> window;
        int minLen = INT_MAX, minLeft = 0;
        for (int right = 0; right < s.size(); right++) {
            char c = s[right];
            window[c]++;
            if (need.count(c) && window[c] == need[c]) formed++;
            while (formed == required) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    minLeft = left;
                }
                char lc = s[left++];
                window[lc]--;
                if (need.count(lc) && window[lc] < need[lc]) formed--;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(minLeft, minLen);
    }
};
```

**Complexity:** O(|s| + |t|) time | O(|s| + |t|) space

---

## Mistakes to Avoid

- Tracking `formed` by character count not unique chars — need to check `window[c] == need[c]` exactly
- Using `window[c] == 0` to decrement `formed` instead of `window[c] < need[c]` — misses cases where t has duplicate chars
- Returning `s.substr(minLeft, minLen)` when `minLen == INT_MAX` — return `""` instead

---

## Pattern

**"Shrinkable sliding window with two frequency maps"** — Expand right freely, shrink left when valid. Track `formed/required` to know validity. Classic hard sliding window template.

Related:
- LC 567 - Permutation in String
- LC 438 - Find All Anagrams in a String
- LC 1358 - Substrings With All Three Characters
