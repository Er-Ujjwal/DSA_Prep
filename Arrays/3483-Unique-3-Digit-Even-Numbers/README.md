# 3483. Unique 3-Digit Even Numbers

**Difficulty:** Easy  
**Topics:** Arrays, Enumeration  
**LeetCode:** [Link](https://leetcode.com/problems/unique-3-digit-even-numbers/)

---

## Problem Statement

Given array `digits`, return count of unique 3-digit even numbers that can be formed using 3 different indices from `digits`.

**Example:**
```
Input:  digits=[1,2,3,4]
Output: 12
```

---

## Intuition & Approach

**Brute force — enumerate all valid 3-index combinations:**
- First digit `i`: must be non-zero (no leading zeros)
- Second digit `j`: any, `j != i`
- Third digit `k`: must be even, `k != i`, `k != j`

Use `seen[1000]` boolean array to deduplicate — same number can be formed via different index combinations.

**Why `seen` array instead of set?**
Numbers are in range `[100, 998]` — fixed small range. Boolean array is O(1) vs O(log n) for set.

**Dry run with `[1,2,3,4]`:**
```
i=0(1), j=1(2), k=2(3): 3%2!=0 -> skip
i=0(1), j=1(2), k=3(4): 124, even ✅ -> seen[124]=true
i=0(1), j=2(3), k=1(2): 132, even ✅
i=0(1), j=2(3), k=3(4): 134, even ✅
...and so on
```

---

## My Solution

```cpp
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size(), ans = 0;
        bool seen[1000] = {};
        for (int i = 0; i < n; i++) {
            if (digits[i] == 0) continue;          // no leading zero
            for (int j = 0; j < n; j++) {
                if (j == i) continue;              // different index
                for (int k = 0; k < n; k++) {
                    if (k == i || k == j) continue; // different index
                    if (digits[k] % 2 != 0) continue; // must be even
                    int num = digits[i]*100 + digits[j]*10 + digits[k];
                    if (!seen[num]) {
                        seen[num] = true;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};
```

**Complexity:** O(n³) time | O(1) space — n ≤ 9 so effectively O(1)

---

## Mistakes to Avoid

- Checking `digits[i] == 0` for first digit — correctly skips leading zeros
- Using `i != j != k` instead of separate pair checks — `k != i || k != j` is wrong; must be `k != i && k != j`
- Forgetting deduplication — `[1,1,2]` can form `112` two ways but should count once

---

## Pattern

**"Enumerate permutations + deduplicate"** — When forming numbers from digit arrays with repeated values, enumerate all index combinations and use a seen array/set to count unique values only.

Related:
- LC 1295 - Find Numbers with Even Number of Digits
- LC 3870 - Count Commas in Range
