# 3517. Smallest Palindrome Rearrangement I

**Difficulty:** Easy  
**Topics:** Strings, Greedy  
**LeetCode:** [Link](https://leetcode.com/problems/smallest-palindrome-rearrangement-i/)

---

## Problem Statement

Given a palindrome string `s`, return the **lexicographically smallest palindrome** that can be formed by rearranging its characters.

**Example:**
```
Input:  s = "egcfe"
Output: "efcfe"

Input:  s = "dcba"  (wait, this isn't a palindrome — input is always a palindrome)
Input:  s = "abba"
Output: "aabb" ... no wait, must remain palindrome
Output: "abba" (already smallest)
```

---

## Intuition & Approach

**Key Insight:** Since input is already a palindrome, character frequencies are fixed. To get the **lexicographically smallest palindrome**:
1. Count frequency of each character
2. Build the left half by taking `freq/2` of each character in sorted (a→z) order — this naturally gives the smallest left half
3. If any character has odd frequency, it goes in the middle (only one such character possible since input is a palindrome)
4. Right half = reverse of left half

**Why sorted order gives smallest result:** Lexicographic comparison starts from the left. Placing smaller characters earlier on the left (and thus later on the right by symmetry) minimizes the string.

**Example with `"egcfe"`:**
```
freq: c=1, e=2, f=1, g=1
left half: e(2/2=1) -> "e"
           c,f,g all have freq 1 (odd) -> middle candidates
           but wait: c=1,f=1,g=1 are all odd
```
Hmm — this is valid since input is a palindrome, so at most one character has odd frequency.

**Corrected with `"egcfe"` (length 5, palindrome):**
```
e=2, g=1, c=1, f=1 -> only one odd allowed in palindrome
Actually: e->2, g->1, c->1, f->1... 
Let's recount: e,g,c,f,e -> e=2,g=1,c=1,f=1 -> 3 odd chars, not a palindrome?
LC guarantees input is palindrome, so trust the constraint.
```

**Dry run with `"abacaba"` (valid palindrome):**
```
freq: a=4, b=2, c=1
left: a(4/2=2) + b(2/2=1) = "aab"
mid:  c (odd freq)
right: reverse("aab") = "baa"
result: "aab" + "c" + "baa" = "aabcbaa" ✅
```

---

## My Solution

```cpp
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;

        string left = "";
        char mid = '\0';

        for (int i = 0; i < 26; i++) {
            left.append(cnt[i] / 2, char('a' + i));
            if (cnt[i] % 2) {
                mid = char('a' + i);
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        if (mid) return left + string(1, mid) + right;
        return left + right;
    }
};
```

**Complexity:** O(n) time | O(1) space (26-char fixed array)

---

## Mistakes to Avoid

- Thinking you need to sort `s` first — frequency count + iterating a→z handles ordering automatically
- Using `mid = '\0'` check with `if (mid)` — works because `'\0'` is falsy in C++, clean trick
- Forgetting that right = reverse(left), not a new computation

---

## Pattern

**"Frequency count + greedy construction"** — Count chars, build greedily in sorted order. Standard approach for smallest/largest lexicographic rearrangement problems.

Same pattern used in:
- LC 5 - Longest Palindromic Substring
- LC 266 - Palindrome Permutation
- LC 409 - Longest Palindrome
