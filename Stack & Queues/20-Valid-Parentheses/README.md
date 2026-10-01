# 20. Valid Parentheses

**Difficulty:** Easy  
**Topics:** Stack & Queues, Strings  
**LeetCode:** [Link](https://leetcode.com/problems/valid-parentheses/)

---

## Problem Statement

Given string `s` containing just `(`, `)`, `{`, `}`, `[`, `]`, determine if the input string is valid. Open brackets must be closed by the same type in the correct order.

**Example:**
```
Input:  s="()[]{}"  -> true
Input:  s="(]"      -> false
Input:  s="([)]"    -> false
```

---

## Intuition & Approach

**Stack — push opening, match closing:**

For every opening bracket `(`, `{`, `[` → push onto stack.
For every closing bracket → check if stack top is the matching opener. If not or stack is empty → invalid.

At end, stack must be empty (all openers matched).

**Dry run with `"([)]"`:**
```
'(': push -> stack=['(']
'[': push -> stack=['(','[']
')': top='[' != '(' -> return false ✅
```

**Dry run with `"()[]{}"`:**
```
'(': push  -> ['(']
')': top='(' match, pop -> []
'[': push  -> ['[']
']': top='[' match, pop -> []
'{': push  -> ['{']
'}': top='{' match, pop -> []
stack empty -> return true ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') st.push(c);
            else {
                if (st.empty()) return false;
                char top = st.top(); st.pop();
                if ((c == ')' && top != '(') ||
                    (c == '}' && top != '{') ||
                    (c == ']' && top != '[')) return false;
            }
        }
        return st.empty();
    }
};
```

**Complexity:** O(n) time | O(n) space

---

## Mistakes to Avoid

- Not checking `st.empty()` before `st.top()` — crashes on unmatched closing bracket
- Returning `true` without checking `st.empty()` — `"((("` would incorrectly return true
- Using map for matching — cleaner but unnecessary; direct comparison is faster

---

## Pattern

**"Stack for bracket matching"** — Push openers, match closers against top. If mismatch or empty stack on closing → invalid. Must be empty at end. Foundation of all bracket/parenthesis problems.

Related:
- LC 1190 - Reverse Substrings Between Parentheses
- LC 394 - Decode String
- LC 739 - Daily Temperatures (monotonic stack)
