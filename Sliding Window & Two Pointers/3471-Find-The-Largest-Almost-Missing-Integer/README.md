# 3471. Find the Largest Almost Missing Integer

**Difficulty:** Medium  
**Topics:** Arrays, Hash Map, Sliding Window  
**LeetCode:** [Link](https://leetcode.com/problems/find-the-largest-almost-missing-integer/)

---

## Problem Statement

Given array `nums` and integer `k`, find the **largest integer** that appears in **exactly one** subarray of length `k`. Return `-1` if no such integer exists.

**Constraints:** `1 <= nums.length <= 50`, `0 <= nums[i] <= 50`, `1 <= k <= nums.length`

**Example:**
```
Input:  nums = [3,9,2,1,7], k = 3
Output: 7

Windows of size 3: [3,9,2], [9,2,1], [2,1,7]
cnt: 3->1, 9->2, 2->3, 1->2, 7->1
cnt==1: 3 and 7 -> max = 7 ✅
```

---

## Intuition & Approach

For each window of size `k` (there are `n-k+1` windows):
1. Collect **unique** elements in that window using a set
2. Increment each unique element's window-count in `cnt`

Finally, find the maximum element with `cnt == 1` (appears in exactly one window).

**Why use a set per window?**
If an element appears multiple times within the same window, it should count as appearing in just ONE window — the set deduplicates within each window before updating `cnt`.

**Why brute force is fine here:**
Constraints are tiny (n ≤ 50, k ≤ 50) — O(n×k) = O(2500) max. No optimization needed.

**Dry run with `[3,9,2,1,7]`, k=3:**
```
Window [3,9,2]: seen={3,9,2} -> cnt={3:1,9:1,2:1}
Window [9,2,1]: seen={9,2,1} -> cnt={3:1,9:2,2:2,1:1}
Window [2,1,7]: seen={2,1,7} -> cnt={3:1,9:2,2:3,1:2,7:1}

cnt==1: 3(✅), 7(✅) -> max=7 ✅
```

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
*(Effectively O(1) given n ≤ 50)*

---

## Mistakes to Avoid

- Using `cnt[nums[j]]++` directly inside inner loop without a set — double-counts elements appearing multiple times in same window
- Forgetting to return `-1` as default — required when no element appears in exactly one window
- Initializing `ans = 0` instead of `-1` — wrong when no valid element exists

---

## Pattern

**"Fixed window enumeration + frequency counting"** — Enumerate all windows, track per-window unique elements, count how many windows each element appears in. Find elements with count == 1.

Related:
- LC 2958 - Longest Subarray With At Most K Frequency
- LC 3090 - Maximum Length Substring With Two Occurrences
