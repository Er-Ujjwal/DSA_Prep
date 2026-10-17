# 2913. Subarrays Distinct Element Sum of Squares I

**Difficulty:** Easy  
**Topics:** Arrays, Hash Set  
**LeetCode:** [Link](https://leetcode.com/problems/subarrays-distinct-element-sum-of-squares-i/)

---

## Problem Statement

For each subarray of `nums`, compute the number of distinct elements. Return the sum of squares of all these counts.

**Example:**
```
Input:  nums=[1,2,1]
Subarrays: [1]->1, [2]->1, [1]->1, [1,2]->2, [2,1]->2, [1,2,1]->2
Output: 1+1+1+4+4+4 = 15
```

---

## My Solution

```cpp
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                ans += st.size() * st.size();
            }
        }
        return ans;
    }
};
```

**Complexity:** O(n²) time | O(n) space

---

## Mistakes to Avoid

- Using `pow(st.size(), 2)` — returns double, may cause precision issues; use `st.size() * st.size()`

---

## Pattern

**"Brute force subarray + set for distinct count"** — Fix left, expand right, maintain set. Square the distinct count at each step.
