# 3622. Check Divisibility by Digit Sum and Product

**Difficulty:** Easy  
**Topics:** Math, Simulation  
**LeetCode:** [Link](https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/)

---

## Problem Statement

Given a positive integer `n`, return `true` if `n` is divisible by the **sum + product** of its digits.

**Example:**
```
Input:  n = 99
Output: true
digits: 9,9 -> sum=18, prod=81 -> sum+prod=99 -> 99%99==0 ✅

Input:  n = 23
Output: false
digits: 2,3 -> sum=5, prod=6 -> sum+prod=11 -> 23%11!=0 ❌
```

---

## Intuition & Approach

Simple digit extraction loop — extract each digit via `n%10`, accumulate sum and product, then check `x % (sum+prod) == 0`.

**Dry run with `n=99`:**
```
digit=9: sum=9,  prod=9
digit=9: sum=18, prod=81
sum+prod = 99
99 % 99 == 0 -> true ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0, prod = 1;
        int x = n;
        while (n) {
            sum += n % 10;
            prod *= n % 10;
            n /= 10;
        }
        return x % (sum + prod) == 0;
    }
};
```

**Complexity:** O(d) time | O(1) space — where d = number of digits

---

## Mistakes to Avoid

- Initializing `prod = 0` instead of `1` — multiplying from 0 always gives 0
- Modifying `n` directly without saving original — need `x = n` before the loop to check divisibility at the end
- Using `if(...) return true; return false;` — simplify to `return x % (sum+prod) == 0`

---

## Pattern

**"Digit extraction"** — `while(n) { digit = n%10; n /= 10; }` is the standard template for processing individual digits of a number.

Related:
- LC 3345 - Smallest Divisible Digit Product
- LC 1085 - Sum of Digits in the Minimum Number
- LC 2520 - Count the Digits That Divide a Number
