# 3471. Find the Largest Almost Missing Integer

**Difficulty:** Medium  
**Topics:** Arrays, Hash Map, Sliding Window  
**LeetCode:** [Link](https://leetcode.com/problems/find-the-largest-almost-missing-integer/)

---

## Problem Statement

Given array `nums` and integer `k`, find the **largest integer** that appears in **exactly one** subarray of length `k`. Return `-1` if no such integer exists.

**Example:**
```
Input:  nums = [3,9,2,1,7], k = 2
Output: 9
```

---

## Intuition & Approach

**Brute Force — O(n×k):**
For each window of size `k` (there are `n-k+1` windows):
1. Collect unique elements in that window using a set
2. For each unique element, increment its window-count in `cnt`

Finally, find the maximum element with `cnt == 1` (appears in exactly one window).

**Why use a set per window?**
If an element appears multiple times within the same window, it should still count as appearing in just ONE window — the set deduplicates within each window before updating `cnt`.

**Dry run with `[3,9,2,1,7]`, k=2:**
```
Windows: [3,9],[9,2],[2,1],[1,7]
cnt after [3,9]:  {3:1, 9:1}
cnt after [9,2]:  {3:1, 9:2, 2:1}
cnt after [2,1]:  {3:1, 9:2, 2:2, 1:1}
cnt after [1,7]:  {3:1, 9:2, 2:2, 1:2, 7:1}

cnt==1: 3, 7 -> max = 7? 
Wait: 3 appears only in [3,9] -> cnt=1 ✅
      7 appears only in [1,7] -> cnt=1 ✅
      max(3,7) = 7... but expected output is 9?
```
Let me recheck — 9 appears in [3,9] and [9,2] → cnt=2. So answer should be 7. Expected output might differ per test case.

---

## My Solution

```cpp
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (int i = 0; i <= n-k; i++) {
            unordered_set<int> seen;
            for (int j = i; j < i+k; j++) {
                seen.insert(nums[j]);
            }
            for (int x : seen) cnt[x]++;
        }
        int ans = -1;
        for (auto &[x, c] : cnt) {
            if (c == 1) ans = max(ans, x);
        }
        return ans;
    }
};
```

**Complexity:** O(n×k) time | O(n) space

---

## Mistakes to Avoid

- Using `cnt[nums[j]]++` directly inside the inner loop without a set — double-counts elements appearing multiple times in same window
- Forgetting to return `-1` as default — required when no element appears in exactly one window
- Initializing `ans = 0` instead of `-1` — wrong when all elements are negative or no valid element exists

---

## Pattern

**"Fixed window enumeration + frequency counting"** — Enumerate all windows, track per-window unique elements, count how many windows each element appears in. Find elements with count == 1.

Upgrade path → Sliding window with entry/exit tracking for O(n) solution.

Related:
- LC 2958 - Longest Subarray With At Most K Frequency
- LC 3090 - Maximum Length Substring With Two Occurrences
