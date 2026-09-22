# 2384. Largest Palindromic Number

**Difficulty:** Medium  
**Topics:** Strings, Greedy, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/largest-palindromic-number/)

---

## Problem Statement

Given string `num` of digits, return the **largest palindromic integer** (as string) using some or all digits. No leading zeros (except "0" itself).

**Example:**
```
Input:  num="444947137"
Output: "7449447"
```

---

## Intuition & Approach

**Greedy — build largest palindrome digit by digit:**

1. Count frequency of each digit 0-9
2. **Middle digit:** largest digit with odd frequency (placed at center)
3. **Left half:** for each digit 9→0, take `freq/2` pairs → builds largest possible left half
4. **Leading zero check:** if left half starts with '0', all pairs are zeros → return just the middle digit (or "0" if no middle)

**Why 9→0 order?**
Greedy — larger digits first = lexicographically largest palindrome.

**Why largest odd-frequency digit as middle?**
To maximize the palindrome, we want the largest possible digit in the center.

**Dry run with `"444947137"`:**
```
freq: 1->1, 3->1, 4->3, 7->2, 9->1

mid: scan 9→0 for odd freq:
  9: freq=1 (odd) -> mid='9', break

left: scan 9→0 for pairs:
  7: freq=2, pairs=1 -> left="7"
  4: freq=3, pairs=1 -> left="74"
  others: 0 pairs

left="74", mid='9', right="47"
ans = "74" + "9" + "47" = "74947" 

wait: expected "7449447"... let me recheck
freq: 4->3(digit 4 appears 3 times in "444947137"? 
"444947137": 4,4,4,9,4,7,1,3,7 -> 4 appears 4 times!
freq: 1->1, 3->1, 4->4, 7->2, 9->1

mid: 9(odd)-> mid='9'
left: 7->pairs=1->"7", 4->pairs=2->"744"
left="744", right="447"
ans="744"+"9"+"447"="7449447" ✅
```

---

## My Solution

```cpp
class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> freq(10, 0);
        for (char c : num) freq[c-'0']++;
        char mid = '\0';
        for (int d = 9; d >= 0; d--) {
            if (freq[d] % 2 == 1) { mid = char('0'+d); break; }
        }
        string left = "";
        for (int d = 9; d >= 0; d--) {
            int pairs = freq[d] / 2;
            while (pairs--) left += char('0'+d);
        }
        if (!left.empty() && left[0] == '0')
            return mid != '\0' ? string(1, mid) : "0";
        string right = left;
        reverse(right.begin(), right.end());
        string ans = left;
        if (mid != '\0') ans += mid;
        ans += right;
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space (freq array fixed size 10)

---

## Mistakes to Avoid

- Picking ANY odd-frequency digit as middle instead of the LARGEST — greedy requires largest for maximum palindrome
- Forgetting leading zero edge case — `left[0]=='0'` means all pairs are zeros, return middle or "0"
- Building right half independently — it's just `reverse(left)`

---

## Pattern

**"Greedy palindrome construction"** — Count frequencies, use pairs for left/right halves (greedy 9→0), largest odd-freq digit in middle. Same pattern as LC 3517.

Related:
- LC 3517 - Smallest Palindrome Rearrangement (same pattern, ascending order)
- LC 409 - Longest Palindrome (count max palindrome length)
