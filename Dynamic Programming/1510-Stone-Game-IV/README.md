# 1510. Stone Game IV

**Difficulty:** Hard  
**Topics:** Dynamic Programming, Game Theory, Math  
**LeetCode:** [Link](https://leetcode.com/problems/stone-game-iv/)

---

## Problem Statement

Alice and Bob take turns (Alice first). Each turn, a player removes any **non-zero perfect square** number of stones. The player who cannot move **loses**. Given `n` stones, return `true` if Alice wins with optimal play.

**Example:**
```
Input:  n = 1  -> Output: true   (Alice takes 1, Bob can't move)
Input:  n = 2  -> Output: false  (Alice takes 1, Bob takes 1, Alice can't)
Input:  n = 4  -> Output: true   (Alice takes 4, Bob can't move)
```

---

## Intuition & Approach

**Game Theory DP — "Can current player win?"**

Define `dp[i]` = `true` if the player whose turn it is with `i` stones **wins**.

**Base case:** `dp[0] = false` — player with 0 stones can't move, loses.

**Transition:** Player at `i` can remove any perfect square `j²` where `j² ≤ i`.
- If ANY move leads to a **losing position for opponent** (`dp[i - j²] == false`), current player wins → `dp[i] = true`
- If ALL moves lead to winning positions for opponent, current player loses → `dp[i] = false`

**Key insight:** You win if you can put your opponent in a losing state.

**Dry run for n=1..6:**
```
dp[0] = false (no moves)
dp[1]: j=1 -> dp[1-1]=dp[0]=false -> WIN -> dp[1]=true
dp[2]: j=1 -> dp[2-1]=dp[1]=true  -> can't win this way
       no more j (j=2: 4>2) -> dp[2]=false
dp[3]: j=1 -> dp[3-1]=dp[2]=false -> WIN -> dp[3]=true
dp[4]: j=1 -> dp[4-1]=dp[3]=true  -> not winning
       j=2 -> dp[4-4]=dp[0]=false -> WIN -> dp[4]=true
dp[5]: j=1 -> dp[5-1]=dp[4]=true
       j=2 -> dp[5-4]=dp[1]=true  -> dp[5]=false
dp[6]: j=1 -> dp[6-1]=dp[5]=false -> WIN -> dp[6]=true
```

---

## My Solution

```cpp
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n+1, false);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j*j <= i; j++) {
                if (!dp[i - j*j]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
```

**Complexity:** O(n√n) time | O(n) space

---

## Mistakes to Avoid

- Forgetting `dp[0] = false` — the losing base case, everything builds from this
- Not breaking early once a winning move is found — wastes time but doesn't affect correctness
- Confusing "current player wins" vs "Alice wins" — `dp[i]` means whoever's turn it is with `i` stones wins; since Alice goes first, `dp[n]` directly answers the question

---

## Pattern

**"Game Theory DP — Win/Lose states"** — `dp[i] = true` if current player can win from state `i`. Transition: win if ANY move leads to opponent's losing state. Lose if ALL moves lead to opponent's winning state.

This exact template applies to many stone game variants:
- LC 292 - Nim Game (subtract 1,2,3)
- LC 877 - Stone Game (pick from ends)
- LC 1025 - Divisor Game
- LC 1140 - Stone Game II
