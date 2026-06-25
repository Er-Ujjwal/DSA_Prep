# 3737. Count Majority Subarrays

**Difficulty:** Easy  
**Topics:** Arrays, Sliding Window & Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/count-majority-subarrays/)

---

## Problem Statement

Given array `nums` and integer `target`, count subarrays where `target` appears **more than half** the subarray's length (strict majority).

**Example:**
```
Input:  nums = [1,2,1,1,2], target = 1
Output: 7
```

---

## Intuition & Approach

**Brute Force — O(n²):** Fix left end `i`, expand right end `j`. Track count of `target` seen so far. At each `j`, check if `count > (j-i+1)/2`.

**Why integer division works for the majority check:**
```
sub_len=3 -> 3/2=1 -> count>1 means >=2 out of 3 -> correct
sub_len=4 -> 4/2=2 -> count>2 means >=3 out of 4 -> correct
sub_len=5 -> 5/2=2 -> count>2 means >=3 out of 5 -> correct
```
Integer division naturally handles both odd and even lengths correctly.

**Dry run with `[1,2,1,1,2]`, target=1:**
```
i=0: j=0 -> [1]      count=1, len=1, 1>0 ✅
     j=1 -> [1,2]    count=1, len=2, 1>1 ❌
     j=2 -> [1,2,1]  count=2, len=3, 2>1 ✅
     j=3 -> [1,2,1,1]count=3, len=4, 3>2 ✅
     ...and so on
```

---

## My Solution

```cpp
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = i; j < n; j++) {
                if (nums[j] == target) count++;
                int sub_len = (j - i + 1);
                if (count > sub_len / 2) ans++;
            }
        }
        return ans;
    }
};
```

**Complexity:** O(n²) time | O(1) space  
*(Accepted given small constraints)*

---

## Mistakes to Avoid

- Using `sub_len / 2.0` (float) instead of integer division — both work but integer division is cleaner and avoids float precision issues
- Resetting `count` inside the `j` loop — count must accumulate as `j` expands

---

## Pattern

**"Fix left, expand right"** — Classic brute force subarray enumeration. Every subarray starting at `i` is explored by moving `j` rightward, accumulating state.

Upgrade path → Sliding Window when you need O(n):
- Convert to +1/-1 (target → +1, others → -1), find subarrays with positive sum using prefix sums.

Similar problems:
- LC 169 - Majority Element
- LC 229 - Majority Element II
