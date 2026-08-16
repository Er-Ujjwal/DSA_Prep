# 2029. Stone Game IX

**Difficulty:** Medium  
**Topics:** Arrays, Math, Game Theory, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/stone-game-ix/)

---

## Problem Statement

Alice and Bob take turns removing stones (Alice first). Alice loses if at any point the **running sum is divisible by 3**. Bob loses if all stones are removed without Alice losing. Bob can also remove any stone on his turn. Return `true` if Alice wins with optimal play.

---

## Intuition & Approach

**Key Insight — Only mod 3 matters.**

Since losing condition is sum % 3 == 0, only the remainder of each stone mod 3 matters. Group stones into:
- `c0` → count of stones where `x%3 == 0`
- `c1` → count of stones where `x%3 == 1`
- `c2` → count of stones where `x%3 == 2`

**Two valid safe sequences (to avoid sum%3==0):**
- Bob picks `1` first → sequence must go: `1,1,2,1,2,1,2...`
- Bob picks `2` first → sequence must go: `2,2,1,2,1,2,1...`

Bob chooses whichever sequence wins for him.

**Role of c0 (zeros mod 3):**
Zeros don't change sum mod 3 but consume a turn — effectively skipping a player's productive move. Each zero flips the turn advantage.
- Even c0 → zeros cancel out, no net effect
- Odd c0 → one extra flip, reverses the advantage

**Case 1: `c0 % 2 == 0` (even zeros)**
Alice wins if BOTH `c1 > 0` AND `c2 > 0`. Bob needs both sequences available. If either group is empty, Bob is stuck and Alice wins.

**Case 2: `c0 % 2 == 1` (odd zeros)**
The extra zero gives Bob more power. Alice can only survive if one group heavily outnumbers the other: `abs(c1 - c2) > 2`.

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
        if (c0 % 2 == 0) return c1 > 0 && c2 > 0;
        return abs(c1 - c2) > 2;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Simulating the game — exponential, completely unnecessary
- Forgetting that stones with `x%3==0` don't affect sum parity but DO affect turn order
- Mixing up Alice wins vs Bob wins — `true` means Alice wins

---

## Pattern

**"Game Theory + Mod arithmetic + Case analysis"** — When losing condition involves divisibility, reduce to mod classes and analyze sequences. Zeros (mod 0 elements) act as turn-flippers — count their parity separately.

Related:
- LC 877 - Stone Game (pick from ends)
- LC 1510 - Stone Game IV (perfect squares)
- LC 319 - Bulb Switcher (divisor parity)
