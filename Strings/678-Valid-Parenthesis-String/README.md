# 678. Valid Parenthesis String

**Difficulty:** Medium  
**Topics:** Strings, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/valid-parenthesis-string/)

---

## Problem Statement

Given string `s` containing `(`, `)`, and `*` (can be `(`, `)`, or empty), return `true` if it's valid.

**Example:**
```
Input:  s="(*)"   -> true
Input:  s="(*))"  -> true
Input:  s="((*)"  -> false
```

---

## Intuition & Approach

**Track range of possible open counts:**
- `low` = minimum possible open brackets (treat `*` as `)` or empty)
- `high` = maximum possible open brackets (treat `*` as `(`)

For each character:
- `(` → low++, high++
- `)` → low--, high--
- `*` → low--, high++ (min: treat as `)`, max: treat as `(`)

If `high < 0` → too many `)`, impossible → return false.
Clamp `low = max(low, 0)` — can't have negative open count.

At end: `low == 0` means it's possible to balance.

**Dry run with `"(*)":`**
```
'(': low=1, high=1
'*': low=0, high=2
')': low=-1->0, high=1
low==0 -> true ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool checkValidString(string s) {
        int low = 0, high = 0;
        for (char c : s) {
            if (c == '(') { low++; high++; }
            else if (c == ')') { low--; high--; }
            else { low--; high++; }
            if (high < 0) return false;
            low = max(low, 0);
        }
        return low == 0;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Not clamping `low = max(low, 0)` — negative low is meaningless
- Checking `low == 0 && high >= 0` — just `low == 0` suffices since `high < 0` already returns false

---

## Pattern

**"Range tracking greedy"** — When wildcards add uncertainty, track min/max possible values. Valid if ranges can include the target (0 open brackets). Used for parentheses with wildcards.

Related: LC 20 - Valid Parentheses, LC 921 - Min Add to Make Valid
