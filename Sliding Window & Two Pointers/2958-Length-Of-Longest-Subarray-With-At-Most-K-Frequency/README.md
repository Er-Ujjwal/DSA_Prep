# 2958. Length of Longest Subarray With at Most K Frequency

**Difficulty:** Medium  
**Topics:** Arrays, Sliding Window & Two Pointers, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/)

---

## Problem Statement

Given an integer array `nums` and integer `k`, return the length of the **longest subarray** where every element appears **at most `k` times**.

**Example:**
```
Input:  nums = [1,2,1,2,1,2,1,2], k = 2
Output: 6  -> [1,2,1,2,1,2] has each element appearing exactly 2 times
```

---

## Intuition & Approach

**Classic Sliding Window with frequency map.**

Expand `right`, track frequency of `nums[right]`. The moment `nums[right]` exceeds frequency `k`, shrink from `left` until it's back to `k`.

**Key observation:** Only `nums[right]` can ever violate the constraint when expanding — no need to check all elements in the window, just the newly added one. This makes the while condition simply `freq[nums[right]] > k`.

**Dry run with `[1,2,1,2,1,2,1,2]`, k=2:**
```
r=0: freq={1:1}, window=1, ans=1
r=1: freq={1:1,2:1}, window=2, ans=2
r=2: freq={1:2,2:1}, window=3, ans=3
r=3: freq={1:2,2:2}, window=4, ans=4
r=4: freq={1:3,2:2} -> 1 exceeds k=2
     shrink: remove nums[0]=1 -> freq={1:2,2:2}, left=1
     window=4, ans=4... continue
r=5: freq={1:2,2:3} -> 2 exceeds k
     shrink: remove nums[1]=2 -> freq={1:2,2:2}, left=2
     window=4, ans=4
...
Final ans=6 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int left = 0, ans = 0;
        for (int right = 0; right < nums.size(); right++) {
            freq[nums[right]]++;
            while (freq[nums[right]] > k) {
                freq[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
```

**Complexity:** O(n) time | O(n) space

---

## Mistakes to Avoid

- Checking all frequencies in the window instead of just `nums[right]` — O(n²), unnecessary
- Forgetting to decrement `freq[nums[left]]` when shrinking — stale frequencies cause wrong results
- Using `freq[nums[right]] >= k` in while condition — off by one, should be `> k` (at most k is allowed)

---

## Pattern

**"Sliding Window + Frequency Map"** — Expand right freely, shrink left only when the newly added element violates the constraint. Since only the rightmost element can newly violate, while condition targets only `nums[right]`.

Same pattern:
- LC 1358 - Substrings Containing All Three Characters
- LC 904 - Fruit Into Baskets
- LC 992 - Subarrays with K Different Integers
