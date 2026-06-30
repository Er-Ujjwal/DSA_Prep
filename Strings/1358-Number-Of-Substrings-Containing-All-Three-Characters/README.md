# 1358. Number of Substrings Containing All Three Characters

**Difficulty:** Medium  
**Topics:** Strings, Sliding Window & Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/)

---

## Problem Statement

Given string `s` containing only 'a', 'b', 'c', return the number of substrings containing **at least one** of each character.

**Example:**
```
Input:  s = "abcabc"
Output: 10
```

---

## Intuition & Approach

**Key Insight:** Use a sliding window. Expand `right`, shrink `left` once all three characters are present. The crucial observation:

> Once window `[left..right]` contains all 3 characters, **every extension of right beyond `right` also forms a valid substring with this left.** So we can add `(n - right)` valid substrings at once.

Then shrink from left to find the next minimal valid window.

**Why `ans += (n - right)`?**
If `[left..right]` is valid, then `[left..right], [left..right+1], ..., [left..n-1]` are ALL valid.
That's exactly `n - right` substrings — all counted in one shot.

**Dry run with `"abcabc"`:**
```
right=0(a): count=[1,0,0] -> not valid
right=1(b): count=[1,1,0] -> not valid
right=2(c): count=[1,1,1] -> VALID
  ans += (6-2)=4, remove s[0]='a' -> count=[0,1,1], left=1
  not valid anymore -> stop while
right=3(a): count=[1,1,1] -> VALID
  ans += (6-3)=3, remove s[1]='b' -> count=[1,0,1], left=2
  not valid -> stop while
right=4(b): count=[1,1,1] -> VALID
  ans += (6-4)=2, remove s[2]='c' -> count=[1,1,0], left=3
  not valid -> stop while
right=5(c): count=[1,1,1] -> VALID
  ans += (6-5)=1, remove s[3]='a' -> count=[0,1,1], left=4
  not valid -> stop while

Total = 4+3+2+1 = 10 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int left = 0, ans = 0;
        int n = s.size();
        for (int right = 0; right < n; right++) {
            count[s[right] - 'a']++;
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                ans += (n - right);
                count[s[left] - 'a']--;
                left++;
            }
        }
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Adding `ans++` inside the while loop instead of `ans += (n - right)` — correct but O(n²) in worst case, misses the counting trick
- Using `ans += (n - right - 1)` — off by one, current `right` itself is a valid endpoint so include it

---

## Pattern

**"Shrinkable Sliding Window + Count extensions"** — When a valid window is found, instead of counting one substring, count all valid extensions to the right in O(1) using `n - right`. Shrink left to find next minimal window.

Same pattern used in:
- LC 713 - Subarray Product Less Than K
- LC 930 - Binary Subarrays With Sum
- LC 992 - Subarrays with K Different Integers
