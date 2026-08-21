# 3116. Kth Smallest Amount With Single Denomination Combination

**Difficulty:** Hard  
**Topics:** Binary Search, Bit Manipulation, Math (Inclusion-Exclusion), LCM/GCD  
**LeetCode:** [Link](https://leetcode.com/problems/kth-smallest-amount-with-single-denomination-combination/)

---

## Problem Statement

Given an array `coins` and integer `k`, find the **Kth smallest** positive integer that is divisible by at least one coin.

**Example:**
```
Input:  coins=[3,6], k=4
Output: 12
Sequence: 3,6,9,12 -> 4th = 12
```

---

## Intuition & Approach

**Two concepts stacked together:**

### 1. Binary Search on Answer

Instead of generating all valid numbers, binary search on the answer `x`:
> "How many numbers in `[1..x]` are divisible by at least one coin?"

If count >= k → x is a valid candidate, search lower.
If count < k → x too small, search higher.

**Search space:** `lo=1`, `hi = min(coins) * k`
(Worst case: all k numbers are multiples of the smallest coin)

### 2. Inclusion-Exclusion for Counting

Count of numbers in `[1..x]` divisible by **at least one** coin:

```
|A∪B∪C| = |A|+|B|+|C| - |A∩B| - |A∩C| - |B∩C| + |A∩B∩C|
```

Numbers divisible by both coin_i and coin_j = multiples of `lcm(coin_i, coin_j)`.

**Rule:**
- Odd-sized subset  → **add** `x / lcm(subset)`
- Even-sized subset → **subtract** `x / lcm(subset)`

**Bitmask** enumerates all 2^n subsets. Early exit if `lcm > x`.

### Dry run with `coins=[3,6], k=4`

Binary search: lo=1, hi=3*4=12

**Check x=6:**
```
mask=01: lcm=3, odd  -> +6/3=2
mask=10: lcm=6, odd  -> +6/6=1
mask=11: lcm=6, even -> -6/6=1
count = 2+1-1 = 2 < 4 -> lo=7
```

**Check x=9:**
```
mask=01: lcm=3, odd  -> +9/3=3
mask=10: lcm=6, odd  -> +9/6=1
mask=11: lcm=6, even -> -9/6=1
count = 3+1-1 = 3 < 4 -> lo=10
```

**Check x=11:**
```
count = 3+1-1 = 3 < 4 -> lo=12
```

**Check x=12:**
```
mask=01: lcm=3, odd  -> +12/3=4
mask=10: lcm=6, odd  -> +12/6=2
mask=11: lcm=6, even -> -12/6=2
count = 4+2-2 = 4 >= 4 -> hi=12
```
lo==hi=12 -> return 12 ✅

---

## My Solution

**Brute force (TLE for large inputs):**
```cpp
long long findKthSmallest(vector<int>& coins, int k) {
    int n = coins.size();
    set<long long> st;
    for (int i = 0; i < n; i++)
        for (long long j = 1; j <= k; j++)
            st.insert(1LL * coins[i] * j);
    auto it = st.begin();
    advance(it, k-1);
    return *it;
}
```

**Optimal — Binary Search + Inclusion-Exclusion:**
```cpp
class Solution {
public:
    long long gcdll(long long a, long long b) {
        while (b) { long long t = a%b; a=b; b=t; }
        return a;
    }
    long long lcmll(long long a, long long b) {
        return a / gcdll(a, b) * b;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto check = [&](long long x) {
            long long cnt = 0;
            for (int mask = 1; mask < (1<<n); mask++) {
                long long L = 1;
                bool ok = true;
                for (int i = 0; i < n; i++) {
                    if (mask & (1<<i)) {
                        L = lcmll(L, coins[i]);
                        if (L > x) { ok = false; break; }
                    }
                }
                if (!ok) continue;
                if (__builtin_popcount(mask) & 1) cnt += x/L;
                else cnt -= x/L;
            }
            return cnt >= k;
        };
        long long lo = 1;
        long long hi = 1LL * (*min_element(coins.begin(), coins.end())) * k;
        while (lo < hi) {
            long long mid = (lo + hi) / 2;
            if (check(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};
```

**Complexity:** O(2^n × n × log(min_coin × k)) time | O(1) space

---

## Mistakes to Avoid

- Using `a/gcdll(a,b)*b` not `a*b/gcdll(a,b)` for LCM — prevents overflow since division happens first
- Forgetting `1LL` when computing `hi` — `min_coin * k` can overflow int
- Missing early exit when `lcm > x` — without it, LCM can overflow long long on large inputs

---

## Pattern

**"Binary Search on Answer + Inclusion-Exclusion"** — When counting elements satisfying a union condition is hard directly, use IE with LCM for divisibility. Binary search on the answer when the count function is monotone.

Key formulas:
- Numbers in `[1..x]` divisible by `L` = `x/L`
- Odd subset → add, Even subset → subtract (IE principle)

Related:
- LC 878 - Nth Magical Number (2 coins, simpler IE)
- LC 1201 - Ugly Number III (3 coins)
