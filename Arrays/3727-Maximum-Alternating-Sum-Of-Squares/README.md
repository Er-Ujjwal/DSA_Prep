# 3727. Maximum Alternating Sum of Squares

**Difficulty:** Medium  
**Topics:** Arrays, Math, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/maximum-alternating-sum-of-squares/)

---

## Problem Statement

Given array `nums`, rearrange it to maximize the alternating sum of squares: `nums[0]² - nums[1]² + nums[2]² - nums[3]² + ...`

**Example:**
```
Input:  nums=[2,-4,3]
Output: 29  -> sort desc by abs: [4,3,2] -> 16-9+4=11? 
Actually: abs values sorted desc, alternating +/-
```

---

## Intuition & Approach

**Key insight:** Since we square values, sign doesn't matter — only absolute values count. To maximize: put largest values at even indices (+) and smallest at odd indices (-).

Sort absolute values in descending order, then apply alternating signs.

**Dry run with `[2,-4,3]`:**
```
abs values: [2,4,3] -> sorted desc: [4,3,2]
ans = 4²-3²+2² = 16-9+4 = 11
```

---

## My Solution

```cpp
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) nums[i] = abs(nums[i]);
        sort(nums.begin(), nums.end(), greater<int>());
        long long ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            long long sq = (long long)nums[i] * nums[i];
            if (i % 2 == 0) ans += sq;
            else ans -= sq;
        }
        return ans;
    }
};
```

**Complexity:** O(n log n) time | O(1) space

---

## Mistakes to Avoid

- Not using `long long` for squares — large values overflow int
- Not converting to absolute values first — signs don't affect squares

---

## Pattern

**"Sort by abs + alternating signs"** — When squaring, convert to abs, sort desc, apply alternating +/- to maximize positive terms.
