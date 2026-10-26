# 50. Pow(x, n)

**Difficulty:** Medium  
**Topics:** Math, Recursion, Bit Manipulation  
**LeetCode:** [Link](https://leetcode.com/problems/powx-n/)

---

## Problem Statement

Implement `pow(x, n)` — x raised to power n.

**Example:**
```
Input:  x=2.0, n=10   -> 1024.0
Input:  x=2.1, n=3    -> 9.261
Input:  x=2.0, n=-2   -> 0.25
```

---

## Intuition & Approach

**Fast Power (Binary Exponentiation):**

Instead of multiplying x n times (O(n)), use the fact that:
- `x^n = (x²)^(n/2)` when n is even
- `x^n = x * x^(n-1)` when n is odd

This halves n each step → O(log n).

**Implementation — iterative:**
- If n is odd: multiply current `x` into `ans`, decrement n by 1
- If n is even: square `x`, halve `n`
- Handle negative n: result = `1/ans`

**Why `long long nn`?**
`INT_MIN = -2147483648`. When negated: `-(-2147483648)` overflows int. Cast to `long long` first.

**Dry run with `x=2, n=10`:**
```
nn=10, ans=1
nn=10(even): x=4, nn=5
nn=5(odd):  ans=4, nn=4
nn=4(even): x=16, nn=2
nn=2(even): x=256, nn=1
nn=1(odd):  ans=4*256=1024, nn=0
return 1024.0 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long nn = n;
        if (nn < 0) nn = -1 * nn;
        while (nn) {
            if (nn % 2 == 1) { ans *= x; nn--; }
            else { x *= x; nn /= 2; }
        }
        if (n < 0) ans = 1.0 / ans;
        return ans;
    }
};
```

**Complexity:** O(log n) time | O(1) space

---

## Mistakes to Avoid

- Using `int n` for negation — `INT_MIN` negation overflows; always cast to `long long`
- Checking `n < 0` using `nn` after modification — use original `n` for the final check
- Recursive approach without memoization — not needed here, iterative is cleaner

---

## Pattern

**"Binary Exponentiation / Fast Power"** — Halve exponent each step by squaring base. O(log n) instead of O(n). Fundamental algorithm used in modular exponentiation, cryptography, matrix exponentiation.

Related: LC 372 - Super Pow, modular exponentiation for large numbers
