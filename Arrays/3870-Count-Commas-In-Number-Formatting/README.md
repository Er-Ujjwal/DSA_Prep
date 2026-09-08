# 3870. Count Commas in Number Formatting

**Difficulty:** Easy  
**Topics:** Math  
**LeetCode:** [Link](https://leetcode.com/problems/count-commas-in-number-formatting/)

---

## Problem Statement

Given integer `n`, return total commas used when writing all integers from `[1, n]` in standard formatting (comma after every 3 digits from right).

**Constraints:** `1 <= n <= 10^5`

**Example:**
```
Input:  n=1002
Output: 3
1000->1 comma, 1001->1 comma, 1002->1 comma -> total=3 ✅

Input:  n=998
Output: 0
All numbers < 1000, no commas needed
```

---

## Intuition & Approach

Numbers with commas start at 1000 (4 digits). With `n <= 10^5`, max is 100,000 — every number in `[1000, n]` has **exactly 1 comma**.

Total commas = count of numbers in `[1000, n]` = `n - 1000 + 1` = `n - 999`

If `n < 1000` → 0 commas.

**Why only 1 comma per number here?**
2 commas start at 1,000,000 (7 digits) which exceeds constraint of 10^5. So within this constraint, every 4-5 digit number has exactly 1 comma.

---

## My Solution

```cpp
class Solution {
public:
    int countCommas(int n) {
        if (n < 1000) return 0;
        return n - 1000 + 1;
    }
};
```

**Complexity:** O(1) time | O(1) space

---

## Generalized approach (if n could be larger)

```
Numbers with 1 comma: [1000, 999999]       -> min(n, 999999) - 999  if n >= 1000
Numbers with 2 commas: [1000000, 999999999] -> min(n, 999999999) - 999999 if n >= 1000000
...and so on
```

Total = sum across all comma tiers.

---

## Mistakes to Avoid

- Counting commas IN n instead of total commas across ALL numbers 1 to n
- Forgetting constraint analysis — always check if multi-comma numbers are possible

---

## Pattern

**"Count elements in range satisfying property"** — Numbers with k commas form a contiguous range. Count elements in that range and multiply by k. Constraint analysis determines which ranges are relevant.
