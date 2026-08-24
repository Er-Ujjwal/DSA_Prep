# 2523. Closest Prime Numbers in Range

**Difficulty:** Medium  
**Topics:** Arrays, Math, Number Theory  
**LeetCode:** [Link](https://leetcode.com/problems/closest-prime-numbers-in-range/)

---

## Problem Statement

Given integers `left` and `right`, find two primes `num1` and `num2` in `[left, right]` such that `num2 - num1` is minimized. Return `{num1, num2}` or `{-1, -1}` if fewer than 2 primes exist.

**Example:**
```
Input:  left=10, right=19
Output: [11,13]
Primes in range: 11,13,17,19
Min diff pair: (11,13) diff=2 ✅
```

---

## Intuition & Approach

**Linear scan + trial division:**
Iterate through `[left, right]`, check each number for primality. Track previous prime and compute difference with current prime. Update answer when a smaller difference is found.

**Trial division primality:** Check divisibility up to √num — O(√num) per check.

**Dry run with `left=10, right=19`:**
```
i=11: prime, prev=-1 -> prev=11
i=13: prime, prev=11, diff=2 < INT_MAX -> ans={11,13}, minDiff=2, prev=13
i=17: prime, prev=13, diff=4 > 2 -> skip, prev=17
i=19: prime, prev=17, diff=2 == 2 -> not strictly less -> skip, prev=19
return {11,13} ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool isPrime(int num) {
        if (num < 2) return false;
        for (int i = 2; i*i <= num; i++)
            if (num % i == 0) return false;
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans = {-1, -1};
        int prev = -1, minDiff = INT_MAX;
        for (int i = left; i <= right; i++) {
            if (isPrime(i)) {
                if (prev != -1) {
                    int diff = i - prev;
                    if (diff < minDiff) {
                        minDiff = diff;
                        ans = {prev, i};
                    }
                }
                prev = i;
            }
        }
        return ans;
    }
};
```

**Complexity:** O(n√n) time | O(1) space — where n = right - left

---

## Faster Approach — Sieve of Eratosthenes

For large ranges, precompute all primes up to `right` in O(right) time:

```cpp
vector<int> closestPrimes(int left, int right) {
    vector<bool> sieve(right+1, true);
    sieve[0] = sieve[1] = false;
    for (int i = 2; i*i <= right; i++)
        if (sieve[i])
            for (int j = i*i; j <= right; j += i)
                sieve[j] = false;

    vector<int> ans = {-1, -1};
    int prev = -1, minDiff = INT_MAX;
    for (int i = left; i <= right; i++) {
        if (sieve[i]) {
            if (prev != -1 && i - prev < minDiff) {
                minDiff = i - prev;
                ans = {prev, i};
            }
            prev = i;
        }
    }
    return ans;
}
```

**Complexity:** O(right log log right) time | O(right) space

---

## Mistakes to Avoid

- Initializing `ans = {-1, -1}` as `int` vector but comparing with `INT_MAX` — both are fine, just be consistent
- Using `diff <= minDiff` instead of `diff < minDiff` — problem asks for minimum, strict less avoids unnecessary updates
- Forgetting `prev != -1` check before computing diff — first prime has no pair yet

---

## Pattern

**"Range scan + primality + sliding pair tracking"** — Scan a range, track consecutive valid elements, minimize difference between adjacent pair. Classic pattern for "closest pair" problems.

Also note: **Twin primes** (primes differing by 2) are the theoretical minimum gap for primes > 3. If any twin primes exist in range, they're guaranteed to be the answer.

Related:
- LC 3115 - Maximum Prime Difference
- LC 2761 - Prime Pairs With Target Sum
