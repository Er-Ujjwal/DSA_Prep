# 2029. Stone Game IX

**Difficulty:** Medium  
**Topics:** Arrays, Math, Game Theory, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/stone-game-ix/)

---

## Problem Statement

Alice and Bob take turns removing stones (Alice first). Alice loses if at any point the running sum is divisible by 3, OR if she can't move. Bob loses if Alice survives all stones. Return `true` if Alice wins with optimal play.

**Example:**
```
Input:  stones = [2,1]   -> Output: true
Input:  stones = [2]     -> Output: false
Input:  stones = [5,1,2,4,3] -> Output: false
```

---

## Intuition & Approach

**Key Insight — Only mod 3 matters.**
The losing condition is sum % 3 == 0. So only the remainder of each stone mod 3 is relevant.

Group stones into:
- `c0` → count of stones where `x%3 == 0`
- `c1` → count of stones where `x%3 == 1`
- `c2` → count of stones where `x%3 == 2`

**Valid sequences to avoid sum%3==0:**

If Bob picks a `1` first: `1,1,2,1,2,1,2...` (alternating after two 1s)
If Bob picks a `2` first: `2,2,1,2,1,2,1...`

Zeros (mod 3 == 0) don't change sum mod 3 but flip whose turn advantage it is. Each zero effectively lets Bob skip Alice's turn.

**Two cases based on c0:**

**Case 1: `c0 % 2 == 0` (even zeros)**
Zeros cancel out. Alice wins if **both** `c1 > 0` AND `c2 > 0`.
- If c1 == 0: Bob always starts with 2, Alice is forced into losing sequence
- If c2 == 0: Bob always starts with 1, same problem

**Case 2: `c0 % 2 == 1` (odd zeros)**
One extra zero gives Bob more skipping power. Alice can only win if one group **significantly** outnumbers the other: `abs(c1 - c2) > 2`.

---

## My Solution

```cpp
class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int x : stones) {
            if (x % 3 == 0) c0++;
            if (x % 3 == 1) c1++;
            if (x % 3 == 2) c2++;
        }
        if (c0 % 2 == 0) {
            return c1 > 0 && c2 > 0;
        }
        return abs(c1 - c2) > 2;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Simulating the game — exponential, completely wrong approach
- Ignoring c0 — zeros seem irrelevant but they flip turn advantage, critical to the solution
- Thinking c0 count matters beyond parity — only even/odd matters, not the actual count

---

## Pattern

**"Game Theory + Mod Arithmetic + Parity Analysis"** — When the losing condition involves divisibility, reduce to mod classes. Parity of special elements (zeros here) determines which case applies.

This is a pure math observation problem — no DP needed unlike LC 877 or LC 1510.

Related:
- LC 877 - Stone Game (interval DP)
- LC 1510 - Stone Game IV (game theory DP)
- LC 292 - Nim Game (mod pattern)
