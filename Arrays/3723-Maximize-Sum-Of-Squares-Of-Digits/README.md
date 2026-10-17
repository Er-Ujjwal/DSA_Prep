# 3723. Maximize Sum of Squares of Digits

**Difficulty:** Medium  
**Topics:** Arrays, Math, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/)

---

## Problem Statement

Given integer `num` and integer `sum`, construct a `num`-digit number whose digit sum equals `sum` and whose sum of squares of digits is maximized. Return as string, or `""` if impossible.

**Example:**
```
Input:  num=2, sum=15
Output: "96"  (9²+6²=81+36=117, max possible)
```

---

## Intuition & Approach

**Greedy — assign largest possible digit at each position:**
For each digit position, assign `min(9, sum)` to maximize squares (larger digits contribute more to sum of squares). Decrease `sum` accordingly.

**Why greedy works:** `9² + 6² = 117` > `8² + 7² = 113`. Always prefer larger digits.

**Edge case:** If `sum > 9 * num` → impossible (can't reach sum even with all 9s).

**Dry run with `num=2, sum=15`:**
```
i=0: digit=min(9,15)=9, sum=6, ans="9"
i=1: digit=min(9,6)=6, sum=0, ans="96"
return "96" ✅
```

---

## My Solution

```cpp
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9*num) return "";
        string ans;
        for (int i = 0; i < num; i++) {
            int digit = min(9, sum);
            ans += char('0' + digit);
            sum -= digit;
        }
        return ans;
    }
};
```

**Complexity:** O(num) time | O(1) space

---

## Pattern

**"Greedy digit construction"** — Assign max possible digit at each position. Constraint check first (`sum > 9*num`). Classic digit construction greedy.

Related: LC 2384 - Largest Palindromic Number
