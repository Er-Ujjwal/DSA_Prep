# 258. Add Digits

**Difficulty:** Easy  
**Topics:** Math, Simulation  
**LeetCode:** [Link](https://leetcode.com/problems/add-digits/)

---

## Problem Statement

Given integer `num`, repeatedly add its digits until result is a single digit. Return that digit.

**Example:**
```
Input:  num = 38
Output: 2
38 -> 3+8=11 -> 1+1=2
```

---

## Intuition & Approach

**Simulation approach:**
Keep summing digits until result ≤ 9. Simple and correct.

**O(1) Math — Digital Root:**
The answer is the **digital root** of n, based on modular arithmetic with 9:
```
if n == 0: return 0
return 1 + (n-1) % 9
```

**Why does this work?**
Any number `n` and its digit sum have the same remainder mod 9 (since `10 ≡ 1 mod 9`, so `10^k ≡ 1 mod 9`). Repeatedly summing digits preserves `n % 9`. The only edge case is when `n % 9 == 0` (and n > 0) → answer is 9, not 0. The formula `1 + (n-1) % 9` handles this cleanly.

**Verification:**
```
n=38: 1+(38-1)%9 = 1+37%9 = 1+1 = 2 ✅
n=9:  1+(9-1)%9  = 1+8%9  = 1+8 = 9 ✅
n=0:  special case -> 0 ✅
```

---

## My Solution

```cpp
// Simulation
class Solution {
public:
    int digitsum(int num) {
        int sum = 0;
        while (num > 0) { sum += num%10; num /= 10; }
        return sum;
    }
    int addDigits(int num) {
        int sum = num;
        while (sum > 9) sum = digitsum(sum);
        return sum;
    }
};

// O(1) Math
int addDigits(int num) {
    if (num == 0) return 0;
    return 1 + (num-1) % 9;
}
```

**Complexity:** Simulation: O(log n) | Math: O(1)

---

## Mistakes to Avoid

- Using `n % 9` directly — returns 0 for multiples of 9, but answer should be 9
- Forgetting `n == 0` edge case — `1 + (0-1) % 9` gives wrong result in some languages

---

## Pattern

**"Digital root via mod 9"** — Repeated digit sum converges to `n % 9` (with 9 instead of 0 for multiples). Classic number theory trick.

Related:
- LC 3622 - Check Divisibility by Digit Sum and Product
- LC 3345 - Smallest Divisible Digit Product
