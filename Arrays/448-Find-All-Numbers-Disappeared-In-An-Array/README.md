# 448. Find All Numbers Disappeared in an Array

**Difficulty:** Easy  
**Topics:** Arrays  
**LeetCode:** [Link](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

---

## Problem Statement

Given array `nums` of `n` integers where each element is in `[1,n]`, return all integers in `[1,n]` that don't appear in `nums`. Must be O(n) time and O(1) extra space.

**Example:**
```
Input:  nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

---

## Intuition & Approach

**In-place marking trick:**
Use the array itself as a visited map. For each value `x`, mark index `|x|-1` as negative — meaning "value `|x|` exists in array." After marking, indices that still have positive values correspond to missing numbers.

**Why `abs(x)`?**
Values may have already been negated by a previous marking. `abs(x)` recovers the original value to compute the correct index.

**Why `-abs(nums[idx])`?**
Preserve the original value (needed for future index calculations) while marking as visited via negation.

**Dry run with `[4,3,2,7,8,2,3,1]`:**
```
x=4:  idx=3, nums[3]=7   -> nums[3]=-7   -> [-,-,-,-7,-,-,-,-] (using - for unchanged)
x=3:  idx=2, nums[2]=2   -> nums[2]=-2
x=2:  idx=1, nums[1]=3   -> nums[1]=-3
x=7:  idx=6, nums[6]=3   -> nums[6]=-3
x=8:  idx=7, nums[7]=1   -> nums[7]=-1
x=2:  idx=1, nums[1]=-3  -> abs=-3? no abs(-3)=3, idx=1, nums[1]=-3 already negative -> nums[1]=-abs(-3)=-3
x=3:  idx=2, nums[2]=-2  -> abs=2, idx=1... wait idx=abs(-2)-1=1, nums[1]=-3 -> nums[1]=-3
x=1:  idx=0, nums[0]=4   -> nums[0]=-4

Final: [-4,-3,-2,-7,-8,-2,-3,-1] (wait should be checking positives)
Hmm, 8 elements all negative means all of 1-8 are present except... 

Recheck: nums=[4,3,2,7,8,2,3,1]
After marking:
idx 0(val 1): marked by x=1 ✅
idx 1(val 2): marked by x=2 ✅  
idx 2(val 3): marked by x=3 ✅
idx 3(val 4): marked by x=4 ✅
idx 4(val 5): never marked -> 5 missing ✅
idx 5(val 6): never marked -> 6 missing ✅
idx 6(val 7): marked by x=7 ✅
idx 7(val 8): marked by x=8 ✅

Scan: nums[4] and nums[5] still positive -> return [5,6] ✅
```

---

## My Solution

```cpp
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int x : nums) {
            int idx = abs(x) - 1;
            nums[idx] = -abs(nums[idx]);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) extra space

---

## Mistakes to Avoid

- Using `nums[idx] = -nums[idx]` without `abs` — if `nums[idx]` is already negative (marked), negating again makes it positive → wrong
- Using `x-1` as index instead of `abs(x)-1` — `x` may already be negative from prior marking
- Pushing `i` instead of `i+1` — values are 1-indexed, indices are 0-indexed

---

## Pattern

**"Index as hash map — negation marking"** — When values are in range `[1,n]` and array has `n` elements, use index `val-1` as a hash key and negation as a visited marker. O(1) space visited array.

Same pattern:
- LC 41 - First Missing Positive (cyclic sort variant)
- LC 442 - Find All Duplicates in an Array (same negation trick, look for already-negative)
- LC 268 - Missing Number (XOR or sum variant)
