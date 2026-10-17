# 1541. Minimum Insertions to Balance a Parentheses String

**Difficulty:** Medium  
**Topics:** Strings, Greedy, Stack  
**LeetCode:** [Link](https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/)

---

## Problem Statement

Each `(` must be closed by `))`. Given string with `(` and `)`, return minimum insertions to balance it.

**Example:**
```
Input:  s="(()))"  -> 1  (need one more `(` at start or extra `)`)
Input:  s="))())(" -> 3
```

---

## Intuition & Approach

**Track open brackets needed, greedily consume `)`:**
- `open` = unmatched `(` count
- `ans` = insertions needed

For `(` → open++
For `)`:
- Check if next char is also `)` (need two consecutive)
- If yes: consume both → open matched, or add `(` if no open
- If no (single `)`): need to insert one more `)`, and still need to match `(`

**Dry run with `"(()))":`**
```
'(': open=1
'(': open=2
')': next=')', consume both, open=1
')': next=end (single)), ans+=1 (insert ')'), open-- → open=0... 
Actually: single ')' → ans++ (insert one ')') and open-- or ans++ (insert '(')
return 1 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int minInsertions(string s) {
        int open = 0, ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') open++;
            else {
                if (i+1 < s.size() && s[i+1] == ')') i++;
                else ans++;
                if (open > 0) open--;
                else ans++;
            }
        }
        return ans + open*2;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Returning `ans + open` instead of `ans + open*2` — each unmatched `(` needs two `)` to close
- Not advancing `i` when consuming two `)` together — causes double processing

---

## Pattern

**"Modified bracket counting"** — When closing requires multiple characters, consume greedily and count insertions for single occurrences. Generalization of LC 921.

Related: LC 921 - Min Add to Make Valid, LC 20 - Valid Parentheses
