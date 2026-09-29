# 1190. Reverse Substrings Between Each Pair of Parentheses

**Difficulty:** Medium  
**Topics:** Strings, Stack  
**LeetCode:** [Link](https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/)

---

## Problem Statement

Given string `s` with parentheses, reverse the substrings inside each pair of parentheses (innermost first). Return result without parentheses.

**Example:**
```
Input:  s="(abcd)"
Output: "dcba"

Input:  s="(u(love)i)"
Output: "iloveu"
```

---

## Intuition & Approach

**Stack-based simulation:**
- On `(`: push current string onto stack, reset current string
- On `)`: reverse current string, append to stack top, pop as new current
- On letter: append to current string

This naturally handles nested parentheses — innermost reverses first.

**Dry run with `"(u(love)i)"`:**
```
'(': stack=[""], curr=""
'u': curr="u"
'(': stack=["","u"], curr=""
'l','o','v','e': curr="love"
')': reverse->"evol", curr="u"+"evol"="uevol", stack=[""]
'i': curr="uevoli"
')': reverse->"iloveu", curr=""+"iloveu"="iloveu", stack=[]
return "iloveu" ✅
```

---

## My Solution

```cpp
class Solution {
public:
    string reverseParentheses(string s) {
        string curr = "";
        stack<string> st;
        for (char c : s) {
            if (c == '(') {
                st.push(curr);
                curr = "";
            } else if (c == ')') {
                reverse(curr.begin(), curr.end());
                curr = st.top() + curr;
                st.pop();
            } else {
                curr += c;
            }
        }
        return curr;
    }
};
```

**Complexity:** O(n²) time (reverse inside loop) | O(n) space

---

## Mistakes to Avoid

- Reversing after popping instead of before — must reverse current THEN prepend stack top
- Not resetting `curr` on `(` — carry over corrupts inner string

---

## Pattern

**"Stack for nested structure"** — When processing nested brackets/parentheses, push state on `(` and restore+process on `)`. Classic stack application.

Related: LC 394 - Decode String (similar stack pattern with counts)
