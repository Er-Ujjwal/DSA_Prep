# 2996. Smallest Missing Integer Greater Than Sequential Prefix Sum

**Difficulty:** Easy  
**Topics:** Arrays, Hash Set  
**LeetCode:** [Link](https://leetcode.com/problems/smallest-missing-integer-greater-than-sequential-prefix-sum/)

---

## Problem Statement

Given a **1-indexed** integer array `nums`, find the longest sequential prefix (where each element is exactly 1 more than the previous), compute its sum, then return the **smallest integer >= that sum** not present in `nums`.

**Example:**
```
Input:  nums = [1,2,3,2,5]
Output: 6
Prefix: [1,2,3] -> sum=6, 6 not in nums -> return 6

Input:  nums = [3,4,5,1,12,14,13]
Output: 15
Prefix: [3,4,5] -> sum=12, 12 in nums -> 13 in nums -> 14 in nums -> 15 not in nums -> return 15
```

---

## Intuition & Approach

**Two steps:**

**Step 1 — Find sequential prefix sum:**
Start from `nums[0]`, keep adding while `nums[i] == nums[i-1] + 1`. Stop at first break.

**Step 2 — Find smallest missing >= sum:**
Use `unordered_set` for O(1) lookup. Increment `sum` until it's not in the set.

**Why unordered_set built from entire array?**
The missing integer could be anywhere ≥ sum, not just beyond the prefix. Need to check the full array.

**Dry run with `[3,4,5,1,12,14,13]`:**
```
Step 1: nums[0]=3, nums[1]=4=3+1✅, nums[2]=5=4+1✅, nums[3]=1≠5+1❌
        sum = 3+4+5 = 12

Step 2: st = {3,4,5,1,12,14,13}
        sum=12 -> in st -> sum=13
        sum=13 -> in st -> sum=14
        sum=14 -> in st -> sum=15
        sum=15 -> not in st -> return 15 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int sum = nums[0];
        int i = 1;
        while (i < nums.size() && nums[i] == nums[i-1] + 1) {
            sum += nums[i];
            i++;
        }
        while (st.count(sum)) sum++;
        return sum;
    }
};
```

**Complexity:** O(n) time | O(n) space

---

## Mistakes to Avoid

- Building set from only the prefix — need full array since missing integer could collide with any element
- Starting `sum = 0` instead of `sum = nums[0]` — prefix always includes at least the first element
- Using `i < nums.size() - 1` in while condition — off by one, misses last element of prefix

---

## Pattern

**"Prefix traversal + Hash Set missing search"** — Find a property of a prefix, then use a set to find the next available value. Clean two-phase approach.

Related:
- LC 3731 - Find Missing Elements Within a Range
- LC 41 - First Missing Positive
