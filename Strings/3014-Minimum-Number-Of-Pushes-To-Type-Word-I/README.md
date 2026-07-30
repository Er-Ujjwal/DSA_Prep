# 3014. Minimum Number of Pushes to Type Word I

**Difficulty:** Easy  
**Topics:** Strings, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/)

---

## Problem Statement

A phone keypad has 8 keys (2-9), each mappable to any letters you choose. Each key can hold multiple letters — the 1st letter needs 1 push, 2nd needs 2 pushes, etc. Given a string `word` with **distinct** lowercase letters, return the **minimum total pushes** to type it.

**Example:**
```
Input:  word = "abcde"
Output: 5  (a,b,c,d,e each get 1 push on separate keys)

Input:  word = "xyzxyzxyzxyz"  <- wait, distinct chars only in Part I
Input:  word = "aabbccddeeffgghhiiiiii"  <- Part II handles frequencies
```

---

## Intuition & Approach

**Key Insight:** We have 8 keys. With distinct characters:
- First 8 characters → assign one per key → 1 push each
- Next 8 characters → assign as 2nd letter on each key → 2 pushes each
- Next 8 → 3 pushes each, and so on

Since all characters appear once (distinct), we just assign greedily in order. The formula `(i/8) + 1` gives the push count for the character at position `i` (0-indexed).

**Why no sorting needed here:** All characters have frequency 1 (distinct constraint), so any assignment order gives same total. Sorting matters in Part II where frequencies differ.

**Formula breakdown:**
```
i = 0..7   -> (i/8)+1 = 1  (8 chars, 1 push each)
i = 8..15  -> (i/8)+1 = 2  (8 chars, 2 pushes each)
i = 16..23 -> (i/8)+1 = 3  (8 chars, 3 pushes each)
i = 24..25 -> (i/8)+1 = 4  (2 chars, 4 pushes each)
Max 26 distinct lowercase letters total.
```

**Dry run with `"abcde"` (n=5):**
```
i=0: (0/8)+1 = 1 -> ans=1
i=1: (1/8)+1 = 1 -> ans=2
i=2: (2/8)+1 = 1 -> ans=3
i=3: (3/8)+1 = 1 -> ans=4
i=4: (4/8)+1 = 1 -> ans=5
return 5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        for (int i = 0; i < word.size(); i++) {
            ans += (i / 8) + 1;
        }
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space  
*(Since n ≤ 26 for distinct chars, effectively O(1))*

---

## Mistakes to Avoid

- Thinking you need to sort — unnecessary for Part I since all frequencies are 1
- Using `i/8` without `+1` — gives 0 for first 8 chars, wrong
- Confusing with Part II (LC 3016) where word has repeated chars and sorting by frequency is required

---

## Pattern

**"Greedy slot assignment with cost tiers"** — When assigning items to slots with increasing costs (1 push, 2 pushes...), assign greedily by placing highest-frequency items in lowest-cost slots. Here all frequencies are equal so formula suffices directly.

Upgrade → LC 3016 (Part II): sort by descending frequency first, then apply same `(i/8)+1` formula.
