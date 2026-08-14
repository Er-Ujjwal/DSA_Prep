# 3090. Maximum Length Substring With Two Occurrences

**Difficulty:** Easy  
**Topics:** Strings, Sliding Window & Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/)

---

## Problem Statement

Given a string `s`, return the length of the **longest substring** where every character appears **at most twice**.

**Example:**
```
Input:  s = "bcbbbcba"
Output: 4  -> "bcbb" or "cbbc" etc.

Input:  s = "aababab"
Output: 5
```

---

## Intuition & Approach

**Sliding window with fixed k=2** — exact same pattern as LC 2958 but `k` is hardcoded to 2 and input is a string. Use a fixed-size `freq[26]` array instead of hash map since input is lowercase letters only.

Expand `right`, track char frequency. When `s[right]` exceeds 2 occurrences, shrink from `left`.

**Dry run with `"bcbbbcba"`:**
```
r=0(b): freq[b]=1, window=1, ans=1
r=1(c): freq[c]=1, window=2, ans=2
r=2(b): freq[b]=2, window=3, ans=3
r=3(b): freq[b]=3 > 2 -> shrink:
        remove s[0]='b' -> freq[b]=2, left=1
        window=3, ans=3
r=4(b): freq[b]=3 > 2 -> shrink:
        remove s[1]='c' -> freq[c]=0, left=2... freq[b] still 3
        remove s[2]='b' -> freq[b]=2, left=3
        window=2, ans=3
r=5(c): freq[c]=1, window=3, ans=3
r=6(b): freq[b]=3 > 2 -> shrink until freq[b]<=2
        left moves to 4, window=3, ans=3
r=7(a): freq[a]=1, window=4, ans=4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int maximumLengthSubstring(string s) {
        vector<int> freq(26, 0);
        int left = 0, ans = 0;
        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;
            while (freq[s[right] - 'a'] > 2) {
                freq[s[left] - 'a']--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space *(freq array is fixed size 26)*

---

## Relation to LC 2958

| | LC 2958 | LC 3090 |
|---|---|---|
| Input | `vector<int>` | `string` |
| k | variable | hardcoded 2 |
| Freq storage | `unordered_map` | `vector<int>(26)` |
| Pattern | identical | identical |

LC 3090 is a special case of LC 2958 with `k=2` and string input.

---

## Mistakes to Avoid

- Using `unordered_map` here — wasteful since input is only lowercase letters, `freq[26]` is O(1) space and faster
- Same pitfalls as LC 2958 — don't check all frequencies, only `s[right]`

---

## Pattern

**"Sliding Window + Frequency Array"** — When input is bounded characters (lowercase letters), prefer `freq[26]` over hash map. Same shrink-on-violation template as LC 2958.

Related:
- LC 2958 - At Most K Frequency (generalized version)
- LC 1358 - Substrings With All Three Characters
- LC 904 - Fruit Into Baskets
