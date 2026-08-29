# 2948. Make Lexicographically Smallest Array by Swapping Elements

**Difficulty:** Medium  
**Topics:** Arrays, Sorting, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/)

---

## ⚠️ REVISIT — Approach looked up, needs deeper understanding

---

## Problem Statement

Given array `nums` and integer `limit`, you can swap `nums[i]` and `nums[j]` if `|nums[i] - nums[j]| <= limit`. Return the lexicographically smallest array achievable.

**Example:**
```
Input:  nums=[1,5,3,9,8], limit=2
Output: [1,3,5,8,9]
```

---

## Intuition & Approach

**Key Insight:** Elements that can be mutually swapped (directly or transitively via chain) form a **group**. Within each group, elements can be rearranged freely → assign smallest values to smallest positions for lexicographic minimum.

**How to find groups:**
Sort elements by value. Two adjacent sorted elements belong to the same group if their difference ≤ limit. This is transitive — if A↔B and B↔C, then A,B,C are one group.

**Algorithm:**
1. Create index array `idx` sorted by `nums` value
2. Scan `idx` left to right, grouping consecutive elements where `nums[idx[j]] - nums[idx[j-1]] <= limit`
3. For each group:
   - `positions` = original indices of group elements (sorted)
   - Assign sorted values (`nums[idx[i..j]]`) to sorted positions
   - Smallest value → leftmost position → lexicographically smallest

**Dry run with `[1,5,3,9,8], limit=2`:**
```
idx sorted by value: [0,2,1,4,3] (values: 1,3,5,8,9)

Group 1: idx[0]=0(val=1), idx[1]=2(val=3) -> diff=2<=2 ✅
         idx[2]=1(val=5) -> diff=5-3=2<=2 ✅
         idx[3]=4(val=8) -> diff=8-5=3>2 ❌ -> group ends
         positions=[0,1,2] sorted, values=[1,3,5]
         ans[0]=1, ans[1]=3, ans[2]=5

Group 2: idx[3]=4(val=8), idx[4]=3(val=9) -> diff=1<=2 ✅
         positions=[3,4] sorted, values=[8,9]
         ans[3]=8, ans[4]=9

return [1,3,5,8,9] ✅
```

---

## My Solution

```cpp
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return nums[i] < nums[j];
        });
        vector<int> ans(n);
        for (int i = 0; i < n; ) {
            int j = i + 1;
            while (j < n && nums[idx[j]] - nums[idx[j-1]] <= limit) j++;
            vector<int> positions(idx.begin()+i, idx.begin()+j);
            sort(positions.begin(), positions.end());
            for (int k = i; k < j; k++)
                ans[positions[k-i]] = nums[idx[k]];
            i = j;
        }
        return ans;
    }
};
```

**Complexity:** O(n log n) time | O(n) space

---

## Mistakes to Avoid

- Thinking only directly swappable elements form a group — transitivity matters
- Sorting positions but not values — both must be sorted and matched in order
- Using `abs(...)` for difference — after sorting by value, `nums[idx[j]] >= nums[idx[j-1]]` always, so subtraction is safe without abs

---

## Pattern

**"Sort + Group + Reassign"** — Sort by value, group by constraint, reassign sorted values to sorted positions within each group. Classic greedy for "make array smallest by constrained swaps."

Related:
- LC 1509 - Minimum Difference Between Largest and Smallest Value in Three Moves
- LC 561 - Array Partition
