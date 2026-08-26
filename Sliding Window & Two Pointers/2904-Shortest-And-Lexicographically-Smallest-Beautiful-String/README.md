# 2904. Shortest and Lexicographically Smallest Beautiful String

**Difficulty:** Medium  
**Topics:** Strings, Sliding Window & Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/shortest-and-lexicographically-smallest-beautiful-string/)

---

## Problem Statement

Given binary string `s` and integer `k`, find the **shortest substring** containing exactly `k` ones. If tie in length, return the **lexicographically smallest**. Return `""` if none exists.

**Example:**
```
Input:  s="100011001", k=3
Output: "11001"
```

---

## Intuition & Approach

**Sliding window with exact count of ones.**

Expand `right`, track `ones`. Shrink `left` under two conditions:
1. `ones > k` — too many ones, must shrink
2. `s[left]=='0' && ones==k` — leading zero is wasteful, remove it to minimize length

Once window has exactly `k` ones and no leading zeros → valid candidate. Compare with current best by length then lexicographic order.

**Why the shrink condition works:**
- `ones > k` → obvious, window invalid
- `s[left]=='0' && ones==k` → removing a leading zero keeps `ones==k` but shortens the window → strictly better candidate, so always shrink

**Dry run with `s="100011001", k=3`:**
```
r=0(1): ones=1
r=1(0): ones=1
r=2(0): ones=1
r=3(0): ones=1
r=4(1): ones=2
r=5(1): ones=3 -> valid, shrink leading zeros:
  s[0]='1' -> stop (can't remove, would lose a 1)
  cur="100011", ans="100011"
  Wait: s[left=0]='1' not '0' so no shrink
  cur="100011", ans="100011"
r=6(0): ones=3, s[left=0]='1' -> no shrink
  cur="1000110", ans="100011" (shorter)
r=7(0): ones=3, shrink: s[0]='1'->stop
  cur="10001100"... hmm
r=8(1): ones=4 > 3 -> shrink: s[0]='1'->ones=3, left=1
  s[1]='0' && ones==3 -> shrink: left=2
  s[2]='0' && ones==3 -> shrink: left=3
  s[3]='0' && ones==3 -> shrink: left=4
  s[4]='1' -> stop
  cur=s[4..8]="11001", size=5 < 6 -> ans="11001"
return "11001" ✅
```

---

## My Solution

```cpp
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size(), left = 0, ones = 0;
        string ans = "";
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') ones++;
            while (left <= right && (ones > k || (s[left] == '0' && ones == k))) {
                if (s[left] == '1') ones--;
                left++;
            }
            if (ones == k) {
                string cur = s.substr(left, right-left+1);
                if (ans.empty() || cur.size() < ans.size() ||
                   (cur.size() == ans.size() && cur < ans))
                    ans = cur;
            }
        }
        return ans;
    }
};
```

**Complexity:** O(n²) time (substr is O(n)) | O(n) space  
*Can be optimized to O(n) by tracking indices instead of extracting substrings*

---

## Mistakes to Avoid

- Only shrinking when `ones > k` — misses the leading zero optimization, gives wrong length
- Using `ans > cur` for lexicographic comparison — correct but confusing; `cur < ans` is cleaner
- Forgetting `ans.empty()` check — comparing empty string with `<` is undefined behavior

---

## Pattern

**"Sliding window with exact count + trim leading waste"** — When window needs exactly k of something AND minimum length, shrink aggressively: remove excess AND remove leading "useless" elements that don't contribute to the count.

Related:
- LC 1358 - Substrings Containing All Three Characters
- LC 2958 - Longest Subarray With At Most K Frequency
- LC 3090 - Maximum Length Substring With Two Occurrences
