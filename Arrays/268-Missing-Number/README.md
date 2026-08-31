# 268. Missing Number

**Difficulty:** Easy  
**Topics:** Arrays, Math, Bit Manipulation  
**LeetCode:** [Link](https://leetcode.com/problems/missing-number/)

---

## Problem Statement

Given array of `n` distinct numbers in range `[0,n]`, find the missing number.

**Example:**
```
Input:  nums = [3,0,1]
Output: 2
```

---

## Intuition & Approach

**Math approach:** Sum of `[0..n]` = `n*(n-1)/2`. Subtract actual sum → missing number.

**Note:** `n = nums.size() + 1`? No — `n = nums.size()` since array has n elements from range [0,n], one is missing.

Wait: `n*(n-1)/2` should be `n*(n+1)/2` for sum of 0 to n. Let me verify:
- `nums=[3,0,1]`, n=3
- Expected sum = 0+1+2+3 = 6 = 3*4/2... but code uses `n*(n-1)/2`
- `n = nums.size()+1 = 4`, `sum = 4*3/2 = 6` ✅

So `n = nums.size()+1` and `sum = n*(n-1)/2` → equivalent to standard `(size)*(size+1)/2`.

**Dry run with `[3,0,1]`:**
```
n = 3+1 = 4
sum = 4*3/2 = 6
actual_sum = 3+0+1 = 4
return 6-4 = 2 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() + 1;
        int sum = n*(n-1)/2;
        int actual_sum = 0;
        for (int x : nums) actual_sum += x;
        return sum - actual_sum;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Alternative — XOR approach

```cpp
int missingNumber(vector<int>& nums) {
    int xorAll = 0;
    int n = nums.size();
    for (int i = 0; i <= n; i++) xorAll ^= i;
    for (int x : nums) xorAll ^= x;
    return xorAll;
}
```

XOR all indices 0..n with all elements — pairs cancel, missing survives.

---

## Mistakes to Avoid

- Using `n = nums.size()` and `sum = n*(n+1)/2` — also correct, just different formulation
- Integer overflow for large n — use `long long` if n is very large

---

## Pattern

**"Expected vs actual sum"** — When range is known, math gives expected sum. Difference = missing. Alternative: XOR (more overflow-safe).

Related: LC 41, LC 448, LC 136
