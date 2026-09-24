# 3550. Smallest Index With Digit Sum Equal to Index

**Difficulty:** Easy  
**Topics:** Arrays, Math  
**LeetCode:** [Link](https://leetcode.com/problems/smallest-index-with-digit-sum-equal-to-index/)

---

## Problem Statement

Given array `nums`, return the smallest index `i` where the digit sum of `nums[i]` equals `i`. Return `-1` if none exists.

**Example:**
```
Input:  nums=[1,3,2]
Output: 2
digitSum(nums[2]) = digitSum(2) = 2 == index 2 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int digitSum(int digit) {
        int sum = 0;
        while (digit > 0) { sum += digit%10; digit /= 10; }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++)
            if (i == digitSum(nums[i])) return i;
        return -1;
    }
};
```

**Complexity:** O(n log m) time | O(1) space — m = max value in nums

---

## Pattern

**"Digit extraction + index property check"** — Compute a digit property per element, compare with index. Standard digit sum template: `while(n>0){ sum+=n%10; n/=10; }`.
