# 2089. Find Target Indices After Sorting Array

**Difficulty:** Easy  
**Topics:** Arrays, Sorting, Binary Search  
**LeetCode:** [Link](https://leetcode.com/problems/find-target-indices-after-sorting-array/)

---

## Problem Statement

Given array `nums` and integer `target`, sort `nums` and return all indices where `nums[i] == target`.

**Example:**
```
Input:  nums=[1,2,5,2,3], target=2
Output: [1,2]
After sort: [1,2,2,3,5] -> target=2 at indices 1,2
```

---

## Intuition & Approach

Sort the array, then scan linearly for all occurrences of target. Since array is sorted, all target values are contiguous — can break early once past them.

**Dry run with `[1,2,5,2,3], target=2`:**
```
After sort: [1,2,2,3,5]
i=0: 1 != 2
i=1: 2 == 2 -> ans=[1]
i=2: 2 == 2 -> ans=[1,2]
i=3: 3 > 2 -> can break
return [1,2] ✅
```

---

## My Solution

```cpp
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) ans.push_back(i);
        }
        return ans;
    }
};
```

**Complexity:** O(n log n) time | O(1) space

**O(n) alternative without sorting:**
Count elements less than target (`less`) and equal to target (`equal`). Answer is indices `[less, less+equal-1]`.

```cpp
vector<int> targetIndices(vector<int>& nums, int target) {
    int less = 0, equal = 0;
    for (int x : nums) {
        if (x < target) less++;
        if (x == target) equal++;
    }
    vector<int> ans;
    for (int i = less; i < less + equal; i++) ans.push_back(i);
    return ans;
}
```

---

## Mistakes to Avoid

- Not breaking early after passing target — minor optimization but good habit
- Forgetting that output indices are 0-based (after sorting)

---

## Pattern

**"Sort + linear scan"** — Simple but effective. O(n) alternative uses counting to avoid sort entirely — count elements less than target = starting index.

Related: LC 34 - Find First and Last Position of Element in Sorted Array
