# 1477. Find Two Non-Overlapping Sub-arrays Each With Target Sum

**Difficulty:** Medium  
**Topics:** Arrays, Sliding Window & Two Pointers, Dynamic Programming  
**LeetCode:** [Link](https://leetcode.com/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/)

---

## Problem Statement

Given array `arr` and integer `target`, find two **non-overlapping** subarrays each summing to `target`. Return minimum sum of their lengths, or `-1` if impossible.

**Example:**
```
Input:  arr=[3,2,2,4,3], target=3
Output: 2
Subarrays: [3](len=1) and [3](len=1) -> 1+1=2 ✅
```

---

## Intuition & Approach

**Sliding Window + Prefix Best Array:**

For each valid subarray ending at `right` with sum = target:
- Check if there's a valid subarray **ending before** `left` (non-overlapping condition)
- `best[i]` = shortest valid subarray ending at or before index `i`

**Key steps:**
1. Sliding window finds subarrays with sum = target (works since all elements positive)
2. When valid subarray `[left..right]` found:
   - Check `best[left-1]` — best length of any valid subarray ending before current one starts
   - Update `ans = min(ans, len + best[left-1])`
   - Update `best[right] = len`
3. Propagate: `best[right] = min(best[right], best[right-1])` — carry forward best so far

**Why `best[left-1]`?**
Current subarray starts at `left`. Any non-overlapping subarray must end at `left-1` or earlier. `best[left-1]` gives the shortest such subarray.

**Dry run with `[3,2,2,4,3], target=3`:**
```
best = [INF,INF,INF,INF,INF]

right=0: sum=3==target, len=1, left=0
  left-1=-1 -> no left subarray check
  best[0]=1
  best[0]=min(1,INF... no right-1)=1

right=1: sum=5>3 -> shrink: sum=2, left=1
  sum!=3

right=2: sum=4>3 -> shrink: sum=2, left=2
  sum!=3, best[2]=min(INF,best[1])=INF... 
  Wait: best[1]=min(INF,best[0])=1

right=3: sum=6>3->shrink->sum=4->shrink->sum=4? 
  arr=[3,2,2,4,3]: right=3 is 4, sum=2+2+4=8->shrink->sum=2+4=6->shrink->sum=4, left=3
  sum!=3

right=4: sum=4+3=7->shrink->sum=3, left=4
  len=1, best[left-1]=best[3]=min(INF,best[2])=1
  ans=min(INF,1+1)=2 ✅
  best[4]=1
return 2 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);
        int left = 0, sum = 0, ans = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) sum -= arr[left++];
            if (sum == target) {
                int len = right - left + 1;
                if (left > 0 && best[left-1] != INT_MAX)
                    ans = min(ans, len + best[left-1]);
                best[right] = len;
            }
            if (right > 0)
                best[right] = min(best[right], best[right-1]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
```

**Complexity:** O(n) time | O(n) space

---

## Mistakes to Avoid

- Checking `best[left]` instead of `best[left-1]` — subarray starts at `left`, so non-overlapping must end at `left-1`
- Forgetting `best[left-1] != INT_MAX` check — adding INT_MAX causes overflow
- Not propagating `best[right] = min(best[right], best[right-1])` — without this, best[i] only reflects subarrays ending exactly at i, not the global best up to i

---

## Pattern

**"Sliding Window + Prefix Best"** — When finding two non-overlapping subarrays with a property, maintain a prefix array of best results seen so far. For each new valid subarray, combine with prefix best to get the answer.

Related:
- LC 2958 - Longest Subarray With At Most K Frequency
- LC 1358 - Substrings Containing All Three Characters
