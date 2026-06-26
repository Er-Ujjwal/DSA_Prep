# 3739. Count Majority Subarrays

**Difficulty:** Medium  
**Topics:** Arrays, Sliding Window & Two Pointers, Prefix Sum, PBDS  
**LeetCode:** [Link](https://leetcode.com/problems/count-majority-subarrays/)

---

## Problem Statement

Given array `nums` and integer `target`, count subarrays where `target` appears **more than half** the subarray's length (strict majority). Return count as `long long`.

**Example:**
```
Input:  nums = [1,2,1,1,2], target = 1
Output: 7
```

---

## Intuition & Approach

**Key Insight — Convert to +1/-1 prefix sum:**

Transform the array: `target → +1`, everything else `→ -1`.
Now "target is majority in subarray [j+1..i]" becomes:
```
prefix[i] - prefix[j] > 0
=> prefix[i] > prefix[j]
=> count all j where prefix[j] < prefix[i]
```

So the problem reduces to: **for each index i, count how many previous prefix values are strictly less than current prefix.**

**Why PBDS ordered_set?**
- `order_of_key(x)` gives count of elements strictly less than `x` in O(log n)
- We store `{pref, index}` pairs (index breaks ties so duplicates are handled correctly)
- `order_of_key({pref, -1})` counts all stored pairs with first value < pref (since -1 < any valid index)

**Dry run with `[1,2,1,1,2]`, target=1 (+1,-1,+1,+1,-1):**
```
Init: st = {(0,0)}, pref=0, ans=0

i=0: pref=1, order_of_key({1,-1})=1 (only (0,0)<1) -> ans=1, st={(0,0),(1,1)}
i=1: pref=0, order_of_key({0,-1})=0                 -> ans=1, st={(0,0),(0,2),(1,1)}
i=2: pref=1, order_of_key({1,-1})=2 (two 0s)        -> ans=3, st={(0,0),(0,2),(1,1),(1,3)}
i=3: pref=2, order_of_key({2,-1})=4                 -> ans=7, st={...,(2,4)}
i=4: pref=1, order_of_key({1,-1})=2                 -> ans=9... 
```
*(verify against expected output on LC)*

**Complexity:** O(n log n) time | O(n) space

---

## My Solution

```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<
    pair<int,int>,
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        ordered_set st;
        long long ans = 0;
        int pref = 0;
        st.insert({0, 0});
        for (int i = 0; i < nums.size(); i++) {
            pref += (nums[i] == target ? 1 : -1);
            ans += st.order_of_key({pref, -1});
            st.insert({pref, i + 1});
        }
        return ans;
    }
};
```

---

## Why `{pref, -1}` in order_of_key?

`ordered_set` stores `pair<int,int>` sorted lexicographically.
`order_of_key({pref, -1})` counts all pairs where:
- first element < pref, OR
- first element == pref AND second < -1 (impossible since index >= 0)

So it cleanly counts **strictly less than current prefix** — exactly what we need.

---

## Mistakes to Avoid

- Using plain `order_of_key(pref)` on an `ordered_set<int>` — fails for duplicate prefix values, undercounts
- Forgetting to insert `{0, 0}` before the loop — misses subarrays starting from index 0
- Using `int` for `ans` — can overflow for large inputs, must be `long long`

---

## Pattern

**"Prefix Sum + Count of smaller elements"** — Convert majority condition to prefix inequality, then count inversions/smaller-elements using PBDS or BIT/Merge Sort.

Classic upgrade path:
- O(n²) brute force (LC 3737) → O(n log n) with PBDS ordered set

Related problems:
- LC 315 - Count of Smaller Numbers After Self
- LC 493 - Reverse Pairs
- LC 327 - Count of Range Sum
