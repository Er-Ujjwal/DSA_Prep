# 3524. Find X Value of Array II

**Difficulty:** Hard  
**Topics:** Dynamic Programming, Math  
**LeetCode:** [Link](https://leetcode.com/problems/find-x-value-of-array-ii/)

---

## ⚠️ REVISIT — Approach looked up, needs deeper understanding

---

## Problem Statement

Given array `nums` and integer `k`, for each remainder `r` in `[0, k-1]`, count the number of subarrays whose product mod k equals `r`. Return array of size `k` with these counts.

**Example:**
```
Input:  nums=[1,2,3], k=3
Output: [1,2,2]  (1 subarray with product%3=0, 2 with =1, 2 with =2)
```

---

## Intuition & Approach

**DP where `dp[r]` = count of subarrays ending at current element with product % k == r**

For each new element `num` with `mod = num % k`:

**Starting a new subarray with just `num`:**
`next[mod] = 1` — one subarray containing only `num`

**Extending existing subarrays:**
For each previous remainder `r` in `dp`, extending with `num` gives new remainder `(r * mod) % k`:
`next[(r * mod) % k] += dp[r]`

**Accumulate into answer:**
`ans[r] += next[r]` — all subarrays ending here contribute to final count

**Why this works:**
- `dp` tracks counts of subarrays ending at previous element
- `next` transitions those counts to current element by multiplying remainders
- `next[mod] = 1` adds the single-element subarray starting fresh

**Complexity:** O(n×k) time | O(k) space

---

## My Solution

```cpp
class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            int mod = num % k;
            vector<long long> next(k, 0);
            next[mod] = 1;
            for (int r = 0; r < k; r++) {
                int newR = (1LL * r * mod) % k;
                next[newR] += dp[r];
            }
            for (int r = 0; r < k; r++) ans[r] += next[r];
            dp = next;
        }
        return ans;
    }
};
```

---

## Mistakes to Avoid

- Using `r * mod` without `1LL` cast — can overflow int when k is large
- Forgetting `next[mod] = 1` — misses single-element subarrays
- Updating `dp` before accumulating into `ans` — must accumulate first

---

## Pattern

**"Modular DP — track remainder counts"** — When counting subarrays by product/sum mod k, maintain `dp[r]` = count of subarrays ending here with remainder r. Transition by multiplying/adding the new element's remainder.

Related:
- LC 974 - Subarray Sums Divisible by K (sum variant)
- LC 523 - Continuous Subarray Sum
