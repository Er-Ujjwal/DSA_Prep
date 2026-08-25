# 260. Single Number III

**Difficulty:** Medium  
**Topics:** Arrays, Bit Manipulation  
**LeetCode:** [Link](https://leetcode.com/problems/single-number-iii/)

---

## Problem Statement

Given an integer array where every element appears **twice** except for exactly **two** elements which appear once. Return those two elements in any order.

**Example:**
```
Input:  nums = [1,2,1,3,2,5]
Output: [3,5]
```

---

## Intuition & Approach

### Approach 1 — Sort + Boundary Check (My Solution)

Sort the array. A unique element either:
- Is at index 0 and differs from index 1
- Is at last index and differs from second-last
- Is in middle and differs from both neighbors

**Dry run with `[1,1,2,2,3,5]` (sorted):**
```
i=0: nums[0]=1, nums[1]=1 -> not unique
i=1(mid): nums[0]=1==nums[1] -> not unique
i=2(mid): nums[1]=1!=nums[2]=2, nums[2]=2==nums[3]=2 -> not unique
i=3(mid): nums[2]=2==nums[3] -> not unique
i=4(mid): nums[3]=2!=nums[4]=3, nums[4]=3!=nums[5]=5 -> unique! push 3
i=5(last): nums[4]=3!=nums[5]=5 -> unique! push 5
return [3,5] ✅
```

**Complexity:** O(n log n) time | O(1) space

### Approach 2 — XOR Bit Manipulation (Optimal)

**Step 1:** XOR all elements → `xorAll = a ^ b` (pairs cancel, only two uniques remain)

**Step 2:** Find **lowest set bit** of `xorAll` → this bit differs between `a` and `b`
```
bit = xorAll & (-xorAll)   // isolates lowest set bit
```

**Step 3:** Split all numbers into two groups by this bit → XOR each group separately → one group gives `a`, other gives `b`

**Why `xorAll & (-xorAll)` works:**
In two's complement, `-x` flips all bits and adds 1. AND with original isolates the rightmost set bit — guaranteed to differ between `a` and `b`.

**Dry run with `[1,2,1,3,2,5]`:**
```
xorAll = 1^2^1^3^2^5 = 3^5 = 6 = 110
bit = 6 & (-6) = 010 = 2

Group 1 (bit set):   2,3,2 -> XOR = 3
Group 2 (bit unset): 1,1,5 -> XOR = 5
return [3,5] ✅
```

**Complexity:** O(n) time | O(1) space

---

## My Solution (Sort)

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        if (nums[0] != nums[1]) ans.push_back(nums[0]);
        for (int i = 1; i < n-1; i++) {
            if (nums[i-1] != nums[i] && nums[i] != nums[i+1])
                ans.push_back(nums[i]);
        }
        if (nums[n-1] != nums[n-2]) ans.push_back(nums[n-1]);
        return ans;
    }
};
```

## Optimal Solution (XOR)

```cpp
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;
        int bit = xorAll & (-(long long)xorAll);
        int a = 0, b = 0;
        for (int x : nums) {
            if (x & bit) a ^= x;
            else b ^= x;
        }
        return {a, b};
    }
};
```

---

## Mistakes to Avoid

- Forgetting boundary checks in sort approach — first and last elements need separate handling
- Using `xorAll / 2` to find the bit — wrong, use `xorAll & (-xorAll)` for lowest set bit
- Thinking any set bit works — any set bit is fine actually, lowest is just convention

---

## Pattern

**"XOR to isolate uniques + bit split"** — XOR all to get `a^b`, find a distinguishing bit, split into two groups. Each group XORs to one unique. Classic bit manipulation template.

Related:
- LC 136 - Single Number (one unique, pure XOR)
- LC 137 - Single Number II (appears 3 times)
- LC 3702 - Longest Subsequence With XOR > 0
