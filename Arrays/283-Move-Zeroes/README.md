# 283. Move Zeroes

**Difficulty:** Easy  
**Topics:** Arrays, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/move-zeroes/)

---

## Problem Statement

Given an integer array `nums`, move all `0`s to the end while maintaining the relative order of non-zero elements. Must be done **in-place**.

**Example:**
```
Input:  [0,1,0,3,12]
Output: [1,3,12,0,0]
```

---

## Intuition & Approach

**Key Insight:** Use two pointers — `j` tracks the position where the next non-zero element should go, `i` scans the array. Whenever a non-zero is found, swap it to position `j` and advance `j`.

This naturally pushes zeroes to the end because every non-zero "bubbles left" to where `j` points, and `j` only moves when a non-zero is placed.

**Dry run with `[0,1,0,3,12]`:**
```
j=0, i=0 -> nums[0]=0, skip
j=0, i=1 -> nums[1]=1, swap(1,0) -> [1,0,0,3,12], j=1
j=1, i=2 -> nums[2]=0, skip
j=1, i=3 -> nums[3]=3, swap(3,1) -> [1,3,0,0,12], j=2
j=2, i=4 -> nums[4]=12, swap(12,0) -> [1,3,12,0,0], j=3
```

**Why this works:** `j` always points to a zero (or hasn't been touched yet), so swapping a non-zero element with `j` never loses data.

---

## My Solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int j = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Using extra array — problem says in-place
- Moving zeroes explicitly instead of pulling non-zeroes left — same result but more work
- Forgetting relative order of non-zeroes must be preserved — swap (not just overwrite) handles this

---

## Pattern

**"Write pointer / Two pointer partition"** — One pointer scans, one pointer marks the next valid write position. Non-qualifying elements naturally end up at the back.

Same pattern used in:
- LC 27 - Remove Element
- LC 26 - Remove Duplicates from Sorted Array
- LC 75 - Sort Colors (Dutch National Flag)
