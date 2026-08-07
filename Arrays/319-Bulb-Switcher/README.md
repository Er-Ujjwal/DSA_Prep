# 319. Bulb Switcher

**Difficulty:** Medium  
**Topics:** Math, Brainteaser  
**LeetCode:** [Link](https://leetcode.com/problems/bulb-switcher/)

---

## Problem Statement

`n` bulbs start OFF. In round `i`, toggle every `i`th bulb. After `n` rounds, return how many bulbs are ON.

**Example:**
```
Input:  n = 3
Output: 1  (only bulb 1 is ON)

Input:  n = 0
Output: 0
```

---

## Intuition & Approach

**Key Insight — Which bulbs end up ON?**

A bulb ends ON if toggled an **odd** number of times. Bulb `k` is toggled once per divisor of `k`.

Most numbers have **even** divisors — they pair up: if `d | k` then `k/d | k` too.

**Perfect squares are the exception:** For `k = 9`, divisors are 1, 3, 9. The middle divisor `3` pairs with itself (`3×3=9`), making the total count **odd**.

So only bulbs at **perfect square positions** end up ON: 1, 4, 9, 16, 25...

**How many perfect squares ≤ n?** Exactly `floor(sqrt(n))`.

**Trace for n=9:**
```
Bulb 1: divisors={1}         -> 1 toggle  -> ON  ✅ (perfect square)
Bulb 2: divisors={1,2}       -> 2 toggles -> OFF
Bulb 3: divisors={1,3}       -> 2 toggles -> OFF
Bulb 4: divisors={1,2,4}     -> 3 toggles -> ON  ✅ (perfect square)
Bulb 5: divisors={1,5}       -> 2 toggles -> OFF
Bulb 6: divisors={1,2,3,6}   -> 4 toggles -> OFF
Bulb 7: divisors={1,7}       -> 2 toggles -> OFF
Bulb 8: divisors={1,2,4,8}   -> 4 toggles -> OFF
Bulb 9: divisors={1,3,9}     -> 3 toggles -> ON  ✅ (perfect square)
Answer: 3 = floor(sqrt(9)) ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int bulbSwitch(int n) {
        return (int)sqrt(n);
    }
};
```

**Complexity:** O(1) time | O(1) space

---

## Mistakes to Avoid

- Simulating all rounds — O(n²), completely unnecessary once the math is clear
- Using `round(sqrt(n))` instead of `(int)sqrt(n)` — floating point precision issues; casting to int floors correctly
- Missing why perfect squares have odd divisors — the self-pairing of the square root is the key

---

## Pattern

**"Math observation over simulation"** — Before simulating, ask: what's the mathematical property that determines the answer? Here, odd divisor count = perfect square = bulb stays ON.

Same thinking applies to:
- LC 877 - Stone Game (always true due to parity)
- LC 292 - Nim Game (lose if n%4==0)
- LC 1180 - Count Substrings with Only One Distinct Letter
