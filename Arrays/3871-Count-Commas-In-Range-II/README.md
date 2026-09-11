# 3871. Count Commas in Range II

**Difficulty:** Medium  
**Topics:** Math  
**LeetCode:** [Link](https://leetcode.com/problems/count-commas-in-range-ii/)

---

## Problem Statement

Given integer `n`, return total commas used when writing all integers from `[1, n]` in standard formatting. Large constraints — `n` can have multiple commas per number.

**Example:**
```
Input:  n=1000000
Output: 999001 + 1 = 999002
```

---

## Intuition & Approach

**Key Insight:** Commas come in tiers based on digit count:
- 1st comma introduced at 1,000 (4 digits)
- 2nd comma introduced at 1,000,000 (7 digits)
- 3rd comma introduced at 1,000,000,000 (10 digits)
- ...each tier at `base = 1000^k`

For each tier with `base`:
- Every number in `[base, n]` contributes **one comma from this tier**
- Count = `n - base + 1`

Sum across all tiers gives total commas.

**Dry run with `n=1,001,000`:**
```
base=1000:    n-1000+1    = 1000001  commas (1st comma tier)
base=1000000: n-1000000+1 = 1001     commas (2nd comma tier)
base=1000000000: > n -> stop

Total = 1000001 + 1001 = 1001002 ✅
```

**Why `long long`?** For large `n`, answer can exceed `int` range.

---

## My Solution

```cpp
class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        for (long long base = 1000; base <= n; base *= 1000) {
            ans += n - base + 1;
        }
        return ans;
    }
};
```

**Complexity:** O(log n) time | O(1) space — at most ~4 iterations (1000, 10^6, 10^9, 10^12)

---

## Difference from LC 3870

| | LC 3870 | LC 3871 |
|---|---|---|
| Constraint | n ≤ 10^5 | n can be very large |
| Max commas/number | 1 | Multiple |
| Approach | `n-999` if n≥1000 | Sum across all tiers |

LC 3870's solution is a special case of this — with n ≤ 10^5, only base=1000 tier applies.

---

## Mistakes to Avoid

- Using `int` instead of `long long` — both `n` and `ans` can overflow int
- Starting `base = 1` or `base = 10` — commas start at 4-digit numbers (base=1000)
- Off by one: `n - base` instead of `n - base + 1` — misses the `base` itself

---

## Pattern

**"Tier-based counting"** — When a property (comma, digit count) changes at powers of 10 or 1000, iterate through tiers and count contributions at each level. O(log n) naturally.

Related:
- LC 3870 - Count Commas I (simpler version)
- LC 233 - Number of Digit One
- LC 172 - Factorial Trailing Zeroes
