# 2144. Minimum Cost of Buying Candies With Discount

**Difficulty:** Easy  
**Topic:** Arrays, Greedy, Sorting  
**LeetCode:** [Link](https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount/)

---

## Problem Statement

A shop sells candies at a discount — for every **two** candies bought, you get a **third candy for free** (its cost must be <= minimum of the two bought).

Given array `cost[]`, return the **minimum total cost** to buy all candies.

**Example:**
```
Input:  cost = [6,5,7,9,2,2]
Output: 23
Buy 9,7 get 6 free | Buy 5,2 get 2 free
```

---

## Intuition & Approach

**Goal:** Maximize the value of candies we get for free.

**Key Insight:** The free candy must cost <= min of the two bought. So we want the most expensive candy possible to be the free one. This happens when we always pair the top 2 most expensive together — their min is still high, so an expensive 3rd candy qualifies as free.

**Greedy Strategy:**
1. Sort array in **descending order** (most expensive first)
2. In every group of 3: pay for indices 0 and 1, index 2 is free
3. Pattern: skip every index where `i % 3 == 2`

**Dry run with `[9,7,6,5,2,2]` (sorted desc):**
```
i=0 -> 9  PAY
i=1 -> 7  PAY
i=2 -> 6  FREE  (i%3==2)
i=3 -> 5  PAY
i=4 -> 2  PAY
i=5 -> 2  FREE  (i%3==2)
Total = 9+7+5+2 = 23
```

**Why sorting descending works:** It guarantees the 3rd item in every group is always the cheapest of the three, satisfying the free-candy constraint automatically. No need to check explicitly.

---

## My Solution

```cpp
// Approach 1: Sort ascending, iterate backward
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.begin(), cost.end());
        int total = 0;
        for (int i = n-1; i >= 0; i--) {
            if ((n-i-1) % 3 != 2) {
                total += cost[i];
            }
        }
        return total;
    }
};

// Approach 2 (Cleaner): Sort descending, iterate forward
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int total = 0;
        for (int i = 0; i < cost.size(); i++) {
            if (i % 3 != 2) total += cost[i];
        }
        return total;
    }
};
```

**Complexity:** O(n log n) time | O(1) space

---

## Mistakes to Avoid

- Adding `n <= 2` special case — unnecessary, the loop handles it naturally
- Sorting ascending and iterating forward with `i % 3 == 2` — wrong! The skip index depends on sort direction
- Overcomplicating with explicit group tracking — `i % 3` handles it implicitly

---

## Pattern

**"Sort + Skip every Kth"** — Greedy pattern where sorting by value and skipping at fixed intervals maximizes benefit.

Whenever you see: *"buy X get 1 free"*, *"every Nth item is discounted"* — sort descending, skip at interval.

**Similar problems:**
- LC 1403 - Minimum Subsequence in Non-Increasing Order
- LC 1710 - Maximum Units on a Truck
