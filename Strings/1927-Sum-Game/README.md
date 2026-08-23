# 1927. Sum Game

**Difficulty:** Medium  
**Topics:** Math, Greedy, Game Theory, Strings  
**LeetCode:** [Link](https://leetcode.com/problems/sum-game/)

---

## Problem Statement

Given string `num` of even length containing digits and `?`, Alice and Bob alternate replacing `?` with digits 1-9 (Alice first). Alice wins if both halves have equal digit sum, Bob wins otherwise. Return `true` if Alice wins with optimal play.

**Example:**
```
Input:  num = "5023"
Output: false
ls=5, rs=2+3=5 -> already equal, no ?s -> Alice wins? 
Wait: no ?s so sum is already fixed -> check if equal -> Alice wins if equal

Input:  num = "?3295???"  
Output: false
```

---

## Intuition & Approach

Split into left half and right half. Track:
- `ls`, `rs` = digit sums of left and right halves
- `lq`, `rq` = count of `?` in left and right halves

**Case 1: `(lq + rq) % 2 == 1` (odd total `?`)**

Alice goes first, they alternate. With odd total `?`, Alice makes one more replacement than Bob. She always gets the final move and can always equalize → **Alice wins → return `true`**

**Case 2: `(lq + rq) % 2 == 0` (even total `?`)**

Both make equal replacements. Bob plays optimally to **prevent** equalization — he always places `9` on the side that disrupts balance. Alice mirrors.

After optimal play from both sides, Bob's strategy succeeds (he prevents equality) exactly when:
```
ls + 9*(lq/2) == rs + 9*(rq/2)
2*ls + 9*lq == 2*rs + 9*rq
2*(ls - rs) == 9*(rq - lq)
```

- If this holds → Bob successfully prevents Alice → **Bob wins → return `false`**
- If this does NOT hold → Bob cannot prevent equality → **Alice wins → return `true`**

So: `return 2*(ls-rs) != (rq-lq)*9`

**Why 9?** Bob always places 9 (maximum digit) to create maximum imbalance. Alice counters with 9 on the other side. Net effect per pair of `?` = 9 contributed to one side.

---

## My Solution

```cpp
class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int ls = 0, rs = 0, lq = 0, rq = 0;
        for (int i = 0; i < n/2; i++) {
            if (num[i] == '?') lq++;
            else ls += num[i] - '0';
        }
        for (int i = n/2; i < n; i++) {
            if (num[i] == '?') rq++;
            else rs += num[i] - '0';
        }
        if ((lq + rq) % 2) return true;
        return 2*(ls-rs) != (rq-lq)*9;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Thinking equal sums after formula means Alice wins — the formula represents Bob's optimal outcome; if it holds, Bob wins, not Alice
- Forgetting odd `?` case — always check parity first before applying the math formula
- Using digit range 0-9 for `?` replacement — problem says 1-9, but since Bob optimally places 9 anyway, it doesn't change the analysis

---

## Pattern

**"Game Theory + Math equilibrium"** — Find the condition under which the second player (Bob) can prevent the first player's goal. Express as an equation. If equation holds → Bob wins. If not → Alice wins.

Related:
- LC 877 - Stone Game
- LC 2029 - Stone Game IX
- LC 1510 - Stone Game IV
