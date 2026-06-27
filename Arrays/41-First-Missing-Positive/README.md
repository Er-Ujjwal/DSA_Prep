# 41. First Missing Positive

**Difficulty:** Hard  
**Topics:** Arrays  
**LeetCode:** [Link](https://leetcode.com/problems/first-missing-positive/)

---

## Problem Statement

Given an unsorted integer array `nums`, return the **smallest missing positive integer**. Must run in O(n) time and O(1) space.

**Examples:**
```
Input: [1,2,0]    -> Output: 3
Input: [3,4,-1,1] -> Output: 2
Input: [7,8,9,11] -> Output: 1
```

---

## Intuition & Approach

**Key Insight:** The answer always lies in range `[1, n+1]`. Why? Because with `n` elements, even in the best case (array is `[1,2,3,...,n]`), the answer is `n+1`. So we only care about positive integers in `[1..n]`.

**Cyclic Sort Strategy:**
Place each number at its "correct" index — number `x` belongs at index `x-1`.
After rearranging, the first index `i` where `nums[i] != i+1` gives the answer.

**Three conditions to swap `nums[i]` to its correct position:**
1. `nums[i] > 0` — only positive numbers have a valid target index
2. `nums[i] <= n` — number must be in range [1..n], else ignore
3. `nums[nums[i]-1] != nums[i]` — avoid infinite swap on duplicates

**Dry run with `[3,4,-1,1]`:**
```
i=0: nums[0]=3, target idx=2, nums[2]=-1 -> swap -> [−1,4,3,1]
     nums[0]=-1, negative -> stop while
i=1: nums[1]=4, target idx=3, nums[3]=1  -> swap -> [−1,1,3,4]
     nums[1]=1, target idx=0, nums[0]=-1 -> swap -> [1,−1,3,4]
     nums[1]=-1, negative -> stop while
i=2: nums[2]=3, target idx=2, nums[2]=3  -> already correct (cond 3 fails) -> stop
i=3: nums[3]=4, target idx=3, nums[3]=4  -> already correct -> stop

Final array: [1,-1,3,4]
Scan: i=1, nums[1]=-1 != 2 -> return 2 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i]-1] != nums[i])
                swap(nums[i], nums[nums[i]-1]);
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
```

**Complexity:** O(n) time | O(1) space  
*(Each element is swapped at most once → total swaps ≤ n)*

---

## Mistakes to Avoid

- Using `nums[i] != i+1` as while condition instead of `nums[nums[i]-1] != nums[i]` — causes infinite loop on duplicates like `[1,1]`
- Thinking the while loop makes it O(n²) — it doesn't, each element is placed at most once
- Forgetting to return `n+1` — when array is perfect `[1,2,...,n]`, answer is `n+1`

---

## Pattern

**Cyclic Sort** — When asked to find missing/duplicate numbers in range `[1..n]` in O(n) time O(1) space, place each number at its correct index using a while loop swap, then scan for the mismatch.

Same pattern used in:
- LC 268 - Missing Number
- LC 442 - Find All Duplicates in an Array
- LC 448 - Find All Numbers Disappeared in an Array
- LC 645 - Set Mismatch
