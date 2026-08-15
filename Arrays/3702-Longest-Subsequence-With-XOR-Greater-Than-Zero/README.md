# 3702. Longest Subsequence With Decreasing Adjacent Difference

**Difficulty:** Medium  
**Topics:** Arrays, Bit Manipulation  
**LeetCode:** [Link](https://leetcode.com/problems/longest-subsequence-with-xor-greater-than-zero/)

---

## Problem Statement

Given an integer array `nums`, return the length of the **longest subsequence** whose XOR is **greater than 0** (non-zero).

**Example:**
```
Input:  nums = [1,2,3]
Output: 3  (XOR of full array = 1^2^3 = 0... wait, try subsequences)

Input:  nums = [0,0]
Output: 0

Input:  nums = [1,0,0]
Output: 3  (XOR = 1^0^0 = 1 > 0)
```

---

## Intuition & Approach

**Three cases based on XOR of full array:**

**Case 1: `XOR of all elements != 0`**
The full array itself is a valid subsequence. Since we want the longest, return `nums.size()`.

**Case 2: `XOR of all == 0` but array has at least one non-zero element**
Removing any one non-zero element changes the XOR from 0 to that element (since `0 XOR x = x`). So remove one non-zero element → XOR becomes non-zero → return `nums.size() - 1`.

**Case 3: All elements are 0**
XOR of any subsequence = 0. No valid subsequence exists → return `0`.

**Why removing a non-zero element works:**
If `a ^ b ^ c ^ ... = 0`, then `a ^ b ^ c ^ ... ^ x = x` (for any x already in the XOR).
So removing element `x` from the full XOR gives `0 ^ x = x` which is > 0 if x != 0.

---

## My Solution

```cpp
class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xr = 0;
        for (int x : nums) xr ^= x;
        if (xr != 0) return nums.size();         // Case 1
        for (int x : nums) {
            if (x != 0) return nums.size() - 1;  // Case 2
        }
        return 0;                                  // Case 3
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Thinking you need to try all subsequences — O(2^n), completely unnecessary
- Missing the all-zeros edge case — if no non-zero element exists, answer is 0 not `nums.size()-1`
- Confusing subsequence with subarray — subsequence doesn't need to be contiguous, so we can always pick any subset

---

## Pattern

**"XOR properties + case analysis"** — XOR of full array tells you everything. Non-zero → done. Zero → remove one non-zero element. All zeros → impossible.

Key XOR properties used:
- `x ^ x = 0` (self-cancellation)
- `0 ^ x = x` (identity)
- Removing element `x` from XOR = XORing it again (since `a ^ x ^ x = a`)

Related:
- LC 136 - Single Number
- LC 260 - Single Number III
- LC 1442 - Count Triplets That Can Form Two Arrays of Equal XOR
