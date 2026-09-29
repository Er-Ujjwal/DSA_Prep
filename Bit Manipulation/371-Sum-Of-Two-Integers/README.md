# 371. Sum of Two Integers

**Difficulty:** Medium  
**Topics:** Bit Manipulation, Math  
**LeetCode:** [Link](https://leetcode.com/problems/sum-of-two-integers/)

---

## Problem Statement

Calculate the sum of two integers without using `+` or `-` operators.

**Example:**
```
Input:  a=1, b=2
Output: 3

Input:  a=2, b=3
Output: 5
```

---

## Intuition & Approach

**XOR + AND carry simulation:**

In binary addition:
- XOR gives sum without carry: `1^1=0, 1^0=1, 0^0=0`
- AND gives carry bits: `1&1=1` (need to shift left by 1)

Repeat until no carry remains.

**Dry run with `a=2(010), b=3(011)`:**
```
Step 1: carry = (010 & 011) << 1 = 010 << 1 = 100
        a = 010 ^ 011 = 001
        b = 100
Step 2: carry = (001 & 100) << 1 = 000
        a = 001 ^ 100 = 101 = 5
        b = 0
return 5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int getSum(int a, int b) {
        while (b) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }
};
```

**Complexity:** O(1) time (max 32 iterations) | O(1) space

---

## Mistakes to Avoid

- Updating `a` before computing carry — carry uses original `a`, compute it first
- Infinite loop — guaranteed to terminate since carry shifts left, eventually exceeds int range and becomes 0

---

## Pattern

**"XOR for sum, AND+shift for carry"** — Fundamental bit manipulation. Used in adder circuits. Any addition can be broken down this way.

Related: LC 67 - Add Binary, LC 989 - Add to Array-Form of Integer
