# 1846. Maximum Element After Decreasing and Rearranging

**Difficulty:** Medium  
**Topics:** Arrays, Greedy, Sorting  
**LeetCode:** [Link](https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/)

---

## Problem Statement

Given a positive integer array `arr`, perform any number of operations:
- Rearrange elements in any order
- Decrease any element to any positive integer

Return the **maximum possible value** of the last element such that the array satisfies: `|arr[i] - arr[i-1]| <= 1` for all adjacent pairs, with `arr[0] = 1`.

**Example:**
```
Input:  [2,2,1,2,1]
Output: 2

Input:  [100,1,1000]
Output: 3
```

---

## Intuition & Approach

**Key Insight:** We want to maximize the last element. The constraint `|arr[i] - arr[i-1]| <= 1` means each element can increase by at most 1 from the previous. So the maximum achievable sequence is `[1,2,3,...,n]`.

**Greedy Strategy:**
1. Sort ascending — we want to build the sequence greedily from smallest to largest
2. Force `arr[0] = 1` — starting point is always 1
3. For each subsequent element: if it's more than `arr[i-1] + 1`, clamp it down to `arr[i-1] + 1`
4. If it's already ≤ `arr[i-1] + 1`, keep it as-is (it satisfies the constraint naturally)

**Why sorting works:** After sorting, every element is ≥ previous. We only ever need to decrease (never increase — that's not allowed anyway). Sorting ensures we never "waste" a large number early when it could help us reach a higher ceiling later.

**Dry run with `[100,1,1000]` → sorted `[1,100,1000]`:**
```
arr[0] = 1
i=1: arr[1]=100 > arr[0]+1=2 -> clamp to 2  -> [1,2,1000]
i=2: arr[2]=1000 > arr[1]+1=3 -> clamp to 3 -> [1,2,3]
return arr.back() = 3 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > arr[i-1] + 1) {
                arr[i] = arr[i-1] + 1;
            }
        }
        return arr.back();
    }
};
```

**Complexity:** O(n log n) time | O(1) space

---

## Mistakes to Avoid

- Forgetting to set `arr[0] = 1` — problem requires first element to be 1
- Thinking you need to handle the case where `arr[i] < arr[i-1]` after sorting — impossible after sorting, every element is ≥ previous
- Trying to maximize by keeping large numbers — greedy clamping always gives the best result

---

## Pattern

**"Greedy + Sort → build sequence with bounded increments"** — Sort first, then greedily assign the maximum valid value at each position. The answer is limited by gaps in the sequence, not by the actual values.

Same pattern used in:
- LC 945 - Minimum Increment to Make Array Unique
- LC 2136 - Earliest Possible Day of Full Bloom
