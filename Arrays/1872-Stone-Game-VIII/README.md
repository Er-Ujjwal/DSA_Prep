# 1872. Stone Game VIII

**Difficulty:** Hard  
**Topics:** Arrays, Dynamic Programming, Prefix Sum, Game Theory  
**LeetCode:** [Link](https://leetcode.com/problems/stone-game-viii/)

---

## Problem Statement

Alice and Bob take turns (Alice first). On each turn, a player picks index `i > 0`, takes all stones from index `0` to `i` (scoring their sum), and the game continues with remaining stones. Both play optimally. Return the score difference (Alice - Bob).

**Example:**
```
Input:  stones = [-1,2,-3,3,-5]
Output: 5
```

---

## Intuition & Approach

**Step 1 — Prefix Sum simplification:**
When a player picks index `i`, they score `stones[0] + ... + stones[i]` = `prefix[i]`. Convert array to prefix sums once → O(1) per pick.

**Step 2 — DP definition:**
`ans` = best score difference (current player - opponent) from current state onwards with optimal play.

Same template as LC 877 — whoever's turn it is wants to maximize their advantage.

**Step 3 — Base case:**
If current player picks `n-1` (last index), they score `prefix[n-1]` and opponent has nothing left. Score difference = `prefix[n-1]`.

```
ans = stones[n-1]
```

**Step 4 — Transition (right to left):**
At index `i`, current player picks `i` → gains `prefix[i]`, but opponent then has advantage `ans` from remaining game.

Score difference if pick `i` = `prefix[i] - ans`

Take max over all choices:
```
ans = max(ans, stones[i] - ans)
```

**Why subtract `ans`?** Because `ans` represents opponent's best score difference after your pick. Your net gain = what you take minus opponent's future advantage.

**Dry run with `[-1,2,-3,3,-5]`:**
```
After prefix sum: [-1, 1, -2, 1, -4]

ans = -4          (base: pick index 4)
i=3: ans = max(-4, 1-(-4))  = max(-4, 5)  = 5
i=2: ans = max(5,  -2-(5))  = max(5, -7)  = 5
i=1: ans = max(5,  1-(5))   = max(5, -4)  = 5
return 5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        for (int i = 1; i < n; i++)
            stones[i] += stones[i-1];      // prefix sum in-place
        int ans = stones[n-1];             // base case
        for (int i = n-2; i >= 1; i--)
            ans = max(ans, stones[i] - ans); // transition
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Starting loop from `i=0` — index 0 can never be picked (must pick i > 0), start from `i=1`
- Thinking `ans` is Alice's absolute score — it's the **score difference** (current player - opponent), not absolute score
- Iterating left to right — must go right to left since base case is at `n-1` and we build backwards

---

## Pattern

**"Game Theory DP — score difference, right to left"** — `ans` = best score difference for current player. Transition: `max(ans, prefix[i] - ans)`. Same template as LC 877 but with prefix sum preprocessing.

Key insight: subtracting `ans` flips perspective from current player to opponent — classic game theory trick.

Related:
- LC 877 - Stone Game (pick from ends)
- LC 1510 - Stone Game IV
- LC 2029 - Stone Game IX
