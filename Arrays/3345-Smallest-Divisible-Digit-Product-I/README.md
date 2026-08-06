# 3345. Smallest Divisible Digit Product I

**Difficulty:** Easy  
**Topics:** Arrays, Math, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/smallest-divisible-digit-product-i/)

---

## Problem Statement

Given integers `n` and `t`, find the smallest integer `>= n` whose **digit product** is divisible by `t`.

**Constraints:** `1 <= n <= 100`, `1 <= t <= 10`

**Example:**
```
Input:  n=10, t=2
Output: 10   (digit product = 1×0 = 0, 0%2==0 ✅)

Input:  n=15, t=3
Output: 15   (digit product = 1×5 = 5... no, 5%3!=0 -> try 16: 6%3==0 ✅) -> 16
```

---

## Intuition & Approach

**Brute force is fine here** — constraints are tiny (n ≤ 100, t ≤ 10). Start from `n`, compute digit product, check divisibility, increment until found.

**Key edge case — digit 0:**
If any digit is 0, product = 0. Since `0 % t == 0` for any `t`, any number containing 0 automatically qualifies. This is **intentional per problem definition**.

**Dry run with `n=15, t=3`:**
```
i=15: product = 1×5 = 5, 5%3 != 0
i=16: product = 1×6 = 6, 6%3 == 0 -> return 16 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int smallestNumber(int n, int t) {
        for (int i = n; ; i++) {
            int product = 1;
            int x = i;
            while (x > 0) {
                product *= (x % 10);
                x /= 10;
            }
            if (product % t == 0) return i;
        }
    }
};
```

**Complexity:** O(range × digits) time | O(1) space  
*(Effectively O(1) given tiny constraints)*

---

## Mistakes to Avoid

- Worrying about digit 0 as a bug — `0 % t == 0` is always true and is correct per problem definition
- Initializing `product = 0` instead of `1` — multiplying from 0 always gives 0, wrong
- Using `while (x >= 0)` instead of `while (x > 0)` — infinite loop since x never goes negative

---

## Pattern

**"Brute force with digit decomposition"** — When constraints are tiny, linear scan + digit extraction is perfectly valid. Don't over-engineer.

Digit extraction pattern: `while (x > 0) { digit = x%10; x /= 10; }`

Related:
- LC 2520 - Count the Digits That Divide a Number
- LC 1085 - Sum of Digits in the Minimum Number
