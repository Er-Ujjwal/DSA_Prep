# 921. Minimum Add to Make Parentheses Valid

**Difficulty:** Medium  
**Topics:** Strings, Greedy, Stack  
**LeetCode:** [Link](https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/)

---

## Problem Statement

Given parentheses string `s`, return minimum number of parentheses to add to make it valid.

**Example:**
```
Input:  s="())"  -> 1
Input:  s="((("  -> 3
```

---

## Intuition & Approach

**Count unmatched brackets:**
- `open` tracks unmatched `(`
- `ans` tracks unmatched `)` (needed additions)

For each char:
- `(` → increment `open` (waiting for match)
- `)` → if `open > 0`, match it (open--), else it's unmatched (ans++)

At end, `open` = unmatched `(` remaining → add to ans.

**Dry run with `"())"`:**
```
'(': open=1
')': open=1>0 → open=0
')': open=0 → ans=1
return ans+open = 1+0 = 1 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, ans = 0;
        for (char c : s) {
            if (c == '(') open++;
            else {
                if (open > 0) open--;
                else ans++;
            }
        }
        return ans + open;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Returning just `ans` — must add `open` for unmatched `(` at end
- Using stack — works but O(n) space; counter approach is O(1)

---

## Pattern

**"Count unmatched brackets"** — Track open count, greedily match on `)`. Unmatched `)` → ans++, leftover `(` → ans+=open. O(1) space alternative to stack.

Related: LC 20 - Valid Parentheses, LC 678 - Valid Parenthesis String
