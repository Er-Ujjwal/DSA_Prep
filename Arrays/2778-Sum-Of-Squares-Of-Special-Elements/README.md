# 2778. Sum of Squares of Special Elements

**Difficulty:** Easy  
**Topics:** Arrays  
**LeetCode:** [Link](https://leetcode.com/problems/sum-of-squares-of-special-elements/)

---

## Problem Statement

Given 1-indexed array `nums` of length `n`, an element `nums[i]` is special if `n % i == 0`. Return sum of squares of all special elements.

**Example:**
```
Input:  nums=[1,2,3,4]  (n=4)
Divisors of 4: 1,2,4
Special: nums[1]=1, nums[2]=2, nums[4]=4
Output: 1+4+16 = 21
```

---

## My Solution

```cpp
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++) {
            if (n % (i+1) == 0)
                sum += nums[i] * nums[i];
        }
        return sum;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Using `i % n == 0` instead of `n % (i+1) == 0` — wrong condition; we check if index divides n, not other way
- Forgetting 1-indexed offset — `i+1` not `i`

---

## Pattern

**"Divisor index check"** — Iterate with 1-indexed check `n % (i+1) == 0`. Clean O(n) scan.
