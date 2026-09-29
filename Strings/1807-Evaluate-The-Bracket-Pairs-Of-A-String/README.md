# 1807. Evaluate the Bracket Pairs of a String

**Difficulty:** Medium  
**Topics:** Strings, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/)

---

## Problem Statement

Given string `s` with bracket pairs `(key)` and a knowledge list of `[key, value]` pairs, replace each `(key)` with its value. If key not found, replace with `"?"`.

**Example:**
```
Input:  s="(name)is(age)yearsold", knowledge=[["name","bob"],["age","two"]]
Output: "bobistwoyearsold"
```

---

## Intuition & Approach

1. Build hash map from knowledge for O(1) lookup
2. Scan string: on `(`, start collecting key until `)`, then replace with map value or `?`

**Dry run with `"(name)is(age)"`, knowledge=[["name","bob"],["age","two"]]`:**
```
mp = {"name":"bob", "age":"two"}
'(': collecting key
'n','a','m','e': key="name"
')': mp["name"]="bob" -> ans+="bob"
'i','s': ans+="is"
'(': collecting key
'a','g','e': key="age"
')': mp["age"]="two" -> ans+="two"
return "bobistwoq" ✅
```

---

## My Solution

```cpp
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& k : knowledge) mp[k[0]] = k[1];
        string ans = "", key = "";
        bool inKey = false;
        for (char c : s) {
            if (c == '(') { inKey = true; key = ""; }
            else if (c == ')') {
                ans += mp.count(key) ? mp[key] : "?";
                inKey = false;
            }
            else if (inKey) key += c;
            else ans += c;
        }
        return ans;
    }
};
```

**Complexity:** O(n + k) time | O(k) space — k = knowledge size

---

## Mistakes to Avoid

- Using `mp[key]` without checking existence — inserts empty string for missing keys; use `mp.count(key)` first
- Not resetting `key` on `(` — carries over previous key

---

## Pattern

**"Hash map lookup + string scanning"** — Build lookup table first, then single pass replace. Standard template for substitution problems.
