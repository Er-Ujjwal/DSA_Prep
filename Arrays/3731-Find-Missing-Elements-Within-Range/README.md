# 3731. Find Missing Elements Within a Range

**Difficulty:** Easy  
**Topics:** Arrays, Hash Set  
**LeetCode:** [Link](https://leetcode.com/problems/find-missing-elements-within-a-range/)

---

## Problem Statement

Given an integer array `nums`, return all integers in the range `(min(nums), max(nums))` that are **not present** in `nums`, in sorted order.

**Example:**
```
Input:  nums = [1,3,5,6]
Output: [2,4]
```

---

## Intuition & Approach

**Simple and clean:**
1. Find `min` and `max` of array in one pass
2. Store all elements in an `unordered_set` for O(1) lookup
3. Iterate from `min+1` to `max-1`, collect elements not in set

No sorting needed since we iterate the range in order naturally.

**Dry run with `[1,3,5,6]`:**
```
mn=1, mx=6, st={1,3,5,6}
i=2: not in st -> ans=[2]
i=3: in st -> skip
i=4: not in st -> ans=[2,4]
i=5: in st -> skip
return [2,4] ✅
```

---

## My Solution

```cpp
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        unordered_set<int> st;
        for (int x : nums) {
            mn = min(mn, x);
            mx = max(mx, x);
            st.insert(x);
        }
        vector<int> ans;
        for (int i = mn+1; i < mx; i++) {
            if (!st.count(i)) ans.push_back(i);
        }
        return ans;
    }
};
```

**Complexity:** O(n + range) time | O(n) space

---

## Mistakes to Avoid

- Iterating `mn` to `mx` inclusive — problem asks for elements **strictly between** min and max, so `mn+1` to `mx-1`
- Using sorted set (`set<int>`) instead of `unordered_set` — O(log n) lookup vs O(1), unnecessary overhead here

---

## Pattern

**"Hash Set + Range Scan"** — Store elements in a set, scan a known range checking membership. Standard missing-element pattern when range is bounded by array's own min/max.

Related:
- LC 41 - First Missing Positive (cyclic sort variant)
- LC 448 - Find All Numbers Disappeared in an Array
