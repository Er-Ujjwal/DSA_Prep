# 3069. Distribute Elements Into Two Arrays I

**Difficulty:** Easy  
**Topics:** Arrays, Simulation  
**LeetCode:** [Link](https://leetcode.com/problems/distribute-elements-into-two-arrays-i/)

---

## Problem Statement

Given array `nums`, distribute elements into two arrays `arr1` and `arr2`:
- `arr1` starts with `nums[0]`, `arr2` starts with `nums[1]`
- For each subsequent element: append to `arr1` if `arr1.back() > arr2.back()`, else append to `arr2`
- Return concatenation of `arr1` and `arr2`

**Example:**
```
Input:  nums = [2,1,3]
Output: [2,3,1]

arr1=[2], arr2=[1]
i=2: nums[2]=3, arr1.back()=2 > arr2.back()=1 -> append to arr1
arr1=[2,3], arr2=[1]
result: [2,3,1] ✅
```

---

## Intuition & Approach

Pure simulation — follow the rules exactly as stated. No tricks needed.

At each step, compare last elements of both arrays. Append current element to whichever array has the larger last element. If equal, append to `arr2` (problem constraint).

**Dry run with `[2,1,3,4,5]`:**
```
arr1=[2], arr2=[1]
i=2: 2>1 -> arr1=[2,3]
i=3: 3>1 -> arr1=[2,3,4]
i=4: 4>1 -> arr1=[2,3,4,5]
result: [2,3,4,5,1]
```

---

## My Solution

```cpp
class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        int n = nums.size();
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < n; i++) {
            if (arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        for (auto x : arr2) arr1.push_back(x);
        return arr1;
    }
};
```

**Complexity:** O(n) time | O(n) space

---

## Mistakes to Avoid

- Using `arr1[arr1.size()-1]` instead of `arr1.back()` — both work but `.back()` is cleaner and more readable
- Forgetting to handle tie case (equal last elements) — problem says append to `arr2`, the `else` branch handles this correctly

---

## Pattern

**"Simulation"** — When the problem states explicit rules for each step, just implement them directly. No greedy or DP needed. Recognize simulation problems early and don't overthink them.

Related:
- LC 2974 - Minimum Number Game
- LC 1313 - Decompress Run-Length Encoded List
