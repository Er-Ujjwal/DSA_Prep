# 520. Detect Capital

**Difficulty:** Easy  
**Topics:** Strings  
**LeetCode:** [Link](https://leetcode.com/problems/detect-capital/)

---

## Problem Statement

Given a string `word`, return `true` if the usage of capitals is **correct**:
- All letters capital: `"USA"`
- All letters lowercase: `"leetcode"`
- Only first letter capital: `"Google"`

**Example:**
```
Input: "FlaG"  -> false
Input: "USA"   -> true
Input: "Google"-> true
```

---

## Intuition & Approach

Count uppercase letters. Exactly three valid cases:
1. `upper == 0` → all lowercase
2. `upper == word.size()` → all uppercase
3. `upper == 1 && isupper(word[0])` → only first letter capital

Any other combination is invalid.

**Dry run with `"FlaG"`:**
```
F=upper, l=lower, a=lower, G=upper -> upper=2
upper==0? No | upper==4? No | upper==1? No -> return false ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        for (char c : word) {
            if (isupper(c)) upper++;
        }
        return upper == 0 || upper == word.size() ||
               (upper == 1 && isupper(word[0]));
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Checking `upper == 1` without verifying `isupper(word[0])` — `"uSA"` has upper=2 but `"googLe"` has upper=1 yet is invalid since capital isn't first
- Using `word.size()` in comparison with `int` — may cause signed/unsigned warning; cast if needed

---

## Pattern

**"Count + Case Analysis"** — Count a property, enumerate all valid states. Cleaner than checking invalid states.
