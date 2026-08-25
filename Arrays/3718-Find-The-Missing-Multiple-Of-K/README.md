# 3718. Find the Missing Multiple of K

**Difficulty:** Easy  
**Topics:** Arrays, Hash Set  
**LeetCode:** [Link](https://leetcode.com/problems/find-the-missing-multiple-of-k/)

---

## Problem Statement

Given an integer array `nums` and integer `k`, find the **smallest positive multiple of `k`** that is not present in `nums`.

**Example:**
```
Input:  nums=[1,2,3,4,5,6], k=3
Output: 9
Multiples of 3: 3,6,9... -> 3 in nums, 6 in nums, 9 not in nums -> 9 ✅
```

---

## Intuition & Approach

Store all elements in an `unordered_set` for O(1) lookup. Iterate multiples of `k` (k, 2k, 3k...) and return the first one not in the set.

**Dry run with `nums=[1,2,3,5], k=2`:**
```
st = {1,2,3,5}
multiple=2:  in st -> skip
multiple=4:  not in st -> return 4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st(nums.begin(), nums.end());
        int multiple = k;
        while (st.count(multiple)) {
            multiple += k;
        }
        return multiple;
    }
};
```

**Complexity:** O(n + m) time | O(n) space — where m = answer/k (number of multiples checked)

---

## Mistakes to Avoid

- Starting `multiple = 0` — 0 is not a positive multiple, start from `k`
- Using sorted array + binary search — unnecessary, hash set is simpler and faster

---

## Pattern

**"Hash Set + sequential search"** — Store elements, iterate a sequence, return first miss. Same pattern as LC 2996 (missing integer from prefix sum).

Related:
- LC 2996 - Smallest Missing Integer Greater Than Sequential Prefix Sum
- LC 3731 - Find Missing Elements Within a Range
