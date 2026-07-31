# 3016. Minimum Number of Pushes to Type Word II

**Difficulty:** Medium  
**Topics:** Strings, Greedy, Sorting  
**LeetCode:** [Link](https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/)

---

## Problem Statement

Same as Part I but `word` can have **repeated characters**. Remap 8 keys (2-9) to minimize total pushes to type `word`.

**Example:**
```
Input:  word = "aabbccddeeffgghhiiiiii"
Output: 24
```

---

## Intuition & Approach

**Key Insight over Part I:** Characters now have different frequencies. To minimize pushes, assign **higher frequency characters to lower push slots** (greedy). A character at slot position `i` (0-indexed, sorted by freq desc) costs `(i/8)+1` pushes per occurrence.

**Strategy:**
1. Count frequency of each character
2. Sort frequencies in **descending order** — most frequent gets cheapest slot
3. Apply same `freq[i] * ((i/8)+1)` formula

**Why descending sort?** If char A appears 10 times and char B appears 2 times:
- A at slot 0 (1 push), B at slot 1 (1 push) → 10×1 + 2×1 = 12
- A at slot 8 (2 pushes), B at slot 0 (1 push) → 10×2 + 2×1 = 22

Always put high frequency chars in low-cost slots.

**Dry run with `"aabbccddeeffgghhiiiiii"`:**
```
freq: a=2,b=2,c=2,d=2,e=2,f=2,g=2,h=2,i=6
sorted desc: [6,2,2,2,2,2,2,2,2,0,0...]

i=0: freq=6, (0/8)+1=1 -> 6×1=6
i=1: freq=2, (1/8)+1=1 -> 2×1=2
i=2: freq=2, (2/8)+1=1 -> 2×1=2
...
i=8: freq=2, (8/8)+1=2 -> 2×2=4
Total = 6+2+2+2+2+2+2+2+4 = 24 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);
        for (char c : word) freq[c - 'a']++;
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * ((i / 8) + 1);
        }
        return ans;
    }
};
```

**Complexity:** O(n + 26log26) = O(n) time | O(1) space

---

## Difference from Part I (LC 3014)

| | Part I | Part II |
|---|---|---|
| Characters | Distinct only | Can repeat |
| Sorting needed | No (all freq=1) | Yes (by freq desc) |
| Formula | `(i/8)+1` | `freq[i] * ((i/8)+1)` |

---

## Mistakes to Avoid

- Sorting ascending instead of descending — puts high freq chars in expensive slots, maximizes cost instead of minimizing
- Not breaking on `freq[i]==0` — wastes iterations but doesn't affect correctness; still good practice
- Forgetting to multiply by `freq[i]` — each character is typed `freq[i]` times

---

## Pattern

**"Greedy slot assignment by frequency"** — Sort by frequency descending, assign to cost tiers greedily. Classic pattern whenever you're distributing items into cost-increasing buckets.

Same pattern used in:
- LC 3014 - Minimum Pushes Part I (simpler version)
- LC 1710 - Maximum Units on a Truck
- LC 451 - Sort Characters by Frequency
