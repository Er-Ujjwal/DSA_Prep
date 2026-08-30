# 2091. Removing Minimum and Maximum From Array

**Difficulty:** Medium  
**Topics:** Arrays, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/removing-minimum-and-maximum-from-array/)

---

## Problem Statement

Given array `nums`, remove both the minimum and maximum elements. You can only remove from the **front or back** of the array. Return the **minimum number of deletions** required.

**Example:**
```
Input:  nums = [2,10,7,5,4,1,8,6]
Output: 5
min at index 5, max at index 1
l=1, r=5
min(r+1, n-l, l+1+n-r) = min(6, 7, 4) = 4... 
wait: n=8, l=1, r=5
r+1=6, n-l=7, l+1+n-r=1+1+8-5=5 -> min=5 ✅
```

---

## Intuition & Approach

Let `l = min(mn_idx, mx_idx)` and `r = max(mn_idx, mx_idx)` — leftmost and rightmost of the two targets.

**Three ways to remove both:**

1. **Both from left:** Delete indices 0 to r → `r+1` deletions
2. **Both from right:** Delete indices l to n-1 → `n-l` deletions  
3. **Split — one from each side:** Delete 0 to l from left (`l+1` deletions) AND r to n-1 from right (`n-r` deletions) → `l+1 + n-r` total

Take the minimum of all three.

**Why only three cases?**
The two targets divide the array into regions. You either sweep from left to cover both, sweep from right to cover both, or meet in the middle with one from each end. No other strategy exists.

**Dry run with `[2,10,7,5,4,1,8,6]`:**
```
min=1 at index 5 (mn=5)
max=10 at index 1 (mx=1)
l = min(5,1) = 1
r = max(5,1) = 5
n = 8

r+1     = 6   (delete from left up to index 5)
n-l     = 7   (delete from right from index 1)
l+1+n-r = 2+3 = 5 (delete 2 from left, 3 from right)

min(6,7,5) = 5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mn = min_element(nums.begin(), nums.end()) - nums.begin();
        int mx = max_element(nums.begin(), nums.end()) - nums.begin();
        int l = min(mn, mx);
        int r = max(mn, mx);
        return min({r+1, n-l, l+1+n-r});
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Using values instead of indices — need positions, not values of min/max
- Forgetting `l = min(mn,mx)`, `r = max(mn,mx)` — l must be the leftmost index regardless of which is min or max
- Missing the split case `l+1+n-r` — most common mistake, only considering pure left or pure right deletion

---

## Pattern

**"Two target removal — three strategies"** — When removing two elements reachable only from ends, enumerate all strategies: both from left, both from right, one from each. Take minimum. O(1) solution once indices are known.

Related:
- LC 1827 - Minimum Operations to Make Array Increasing
- LC 1221 - Split a String in Balanced Strings
