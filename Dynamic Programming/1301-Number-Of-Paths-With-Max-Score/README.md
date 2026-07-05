# 1301. Number of Paths with Max Score

**Difficulty:** Hard  
**Topics:** Dynamic Programming, Arrays  
**LeetCode:** [Link](https://leetcode.com/problems/number-of-paths-with-max-score/)

---

## Problem Statement

Given a square board of characters, find the maximum sum path from `'E'` (bottom-right) to `'S'` (top-left), moving only **up, left, or diagonally up-left**. Also return the number of such paths with that maximum score. Both answers modulo `1e9+7`.

Special cells: `'S'` = start (score 0), `'E'` = end (score 0), `'X'` = obstacle (blocked).

**Example:**
```
Input:  board = ["E23","2X2","12S"]
Output: [7, 1]
```

---

## Intuition & Approach

**Traverse in reverse:** Instead of going from `S` to `E`, go from `E` (bottom-right) back to `S` (top-left). At each cell, look at the three possible next steps — down, right, diagonal down-right — and pick the best.

**Two DP tables:**
- `dp[i][j]` = maximum score achievable from cell `(i,j)` to `E`
- `cnt[i][j]` = number of paths achieving that maximum score

**Transition at each cell `(i,j)`:**
1. Check all 3 neighbors `(i+dx, j+dy)` where `{dx,dy} ∈ {(1,0),(0,1),(1,1)}`
2. Among reachable neighbors (not -1), find the one with max `dp` value
3. If a neighbor ties the current best, add its count to `ways`
4. `dp[i][j] = best + cell_value`, `cnt[i][j] = ways`

**Base case:** `dp[n-1][n-1] = 0`, `cnt[n-1][n-1] = 1` (at 'E', score=0, one way)

**Key implementation details:**
- `dp = -1` means cell is unreachable (blocked or no valid path)
- Skip `'X'` and `'S'` cells during fill (S is handled implicitly at `dp[0][0]`)
- `'E'` cell adds 0 to score (don't add `board[i][j] - '0'` for 'E')
- Return `{0,0}` if `dp[0][0] == -1` (no valid path exists)

**Dry run with `["E23","2X2","12S"]` (n=3):**
```
Start at (2,2)='S': dp[2][2]=0, cnt[2][2]=1 (skip, it's 'S')
(2,1)='2': neighbors -> (2,2) dp=0 -> best=0, ways=1
           dp[2][1] = 0+2 = 2, cnt[2][1]=1
(2,0)='1': neighbors -> (2,1) dp=2 -> best=2, ways=1
           dp[2][0] = 2+1 = 3, cnt[2][0]=1
(1,2)='2': neighbors -> (2,2) dp=0 -> best=0, ways=1
           dp[1][2] = 0+2 = 2, cnt[1][2]=1
(1,1)='X': skip
(1,0)='2': neighbors -> (2,0) dp=3, (2,1) dp=2 -> best=3, ways=1
           dp[1][0] = 3+2 = 5, cnt[1][0]=1
(0,2)='3': neighbors -> (1,2) dp=2 -> best=2, ways=1
           dp[0][2] = 2+3 = 5, cnt[0][2]=1
(0,1)='2': neighbors -> (1,2) dp=2, (0,2) dp=5 -> best=5, ways=1
           dp[0][1] = 5+2 = 7, cnt[0][1]=1
(0,0)='E': neighbors -> (1,0) dp=5, (0,1) dp=7, (1,1) X=-1
           best=7, ways=1
           dp[0][0] = 7 (E adds 0), cnt[0][0]=1

return {7, 1} ✅
```

---

## My Solution

```cpp
class Solution {
public:
    vector<int> pathsWithMaxScore(vector<string>& board) {
        const int MOD = 1e9 + 7;
        int n = board.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<long long>> cnt(n, vector<long long>(n, 0));
        dp[n-1][n-1] = 0;
        cnt[n-1][n-1] = 1;

        vector<pair<int,int>> dir = {{1,0}, {0,1}, {1,1}};
        for (int i = n-1; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                if (board[i][j] == 'X' || board[i][j] == 'S') continue;
                int best = -1;
                long long ways = 0;
                for (auto &[dx, dy] : dir) {
                    int ni = i + dx, nj = j + dy;
                    if (ni >= n || nj >= n) continue;
                    if (dp[ni][nj] == -1) continue;
                    if (dp[ni][nj] > best) {
                        best = dp[ni][nj];
                        ways = cnt[ni][nj];
                    } else if (dp[ni][nj] == best) {
                        ways = (ways + cnt[ni][nj]) % MOD;
                    }
                }
                if (best == -1) continue;
                dp[i][j] = best;
                if (board[i][j] != 'E') dp[i][j] += board[i][j] - '0';
                cnt[i][j] = ways % MOD;
            }
        }
        if (dp[0][0] == -1) return {0, 0};
        return {dp[0][0], (int)(cnt[0][0] % MOD)};
    }
};
```

**Complexity:** O(n²) time | O(n²) space

---

## Mistakes to Avoid

- Skipping `'S'` cell but forgetting it's the **source** — `dp[0][0]` reads from neighbors, `S` itself isn't processed, which is correct
- Using `int` for `cnt` — path counts can overflow `int`, use `long long`
- Forgetting to mod `cnt` at each step — intermediate counts can exceed `1e9+7`
- Adding cell value for `'E'` — `'E'` contributes 0 to score
- Returning `{0,0}` for unreachable — don't return `{dp[0][0], 0}` when path is blocked, return `{0,0}` explicitly

---

## Pattern

**"Reverse DP on grid + simultaneous max score and count tracking"** — When asked for both optimal value AND number of ways achieving it, maintain two parallel DP tables. Update count only when a neighbor ties the current best; reset count when a strictly better neighbor is found.

Same pattern used in:
- LC 62 - Unique Paths
- LC 64 - Minimum Path Sum
- LC 174 - Dungeon Game
