# 835. Image Overlap

**Difficulty:** Medium  
**Topics:** Arrays, Matrix, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/image-overlap/)

---

## ⚠️ REVISIT — Approach looked up, understood after explanation

---

## Problem Statement

Given two binary matrices `img1` and `img2` of size `n x n`, find the largest possible overlap after translating one image over the other.

**Example:**
```
Input:  img1=[[1,1,0],[0,1,0],[0,1,0]], img2=[[0,0,0],[0,1,1],[0,0,1]]
Output: 3
```

---

## Intuition & Approach

**Key Insight:** If we shift img2 by translation `(dx, dy)`, a 1 at `(i,j)` in img1 overlaps with a 1 at `(x,y)` in img2 when:
```
x - i = dx  and  y - j = dy
```

So for every pair of 1s (one from each image), compute the translation needed. The most frequent translation = maximum overlap.

**Steps:**
1. Collect positions of all 1s in img1 (set A) and img2 (set B)
2. For every pair `(i,j)` from A and `(x,y)` from B, compute translation `(x-i, y-j)`
3. Count frequency of each translation using hash map
4. Return max frequency

**Why `dx = x-i+n-1`?**
`x-i` can be negative (range `[-(n-1), n-1]`). Adding `n-1` shifts it to `[0, 2n-2]` — always non-negative, safe as key.

**Why `key = dx*(2*n-1) + dy`?**
Encodes 2D translation `(dx, dy)` into single integer — like row-major indexing. Width = `2*n-1` ensures unique key for every valid pair.

**Dry run with `n=2, img1=[[1,0],[0,0]], img2=[[0,0],[0,1]]`:**
```
A = [(0,0)], B = [(1,1)]
dx = 1-0+1 = 2, dy = 1-0+1 = 2
key = 2*3 + 2 = 8, freq[8]=1
ans = 1 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int,int>> A, B;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                if (img1[i][j]) A.push_back({i, j});
                if (img2[i][j]) B.push_back({i, j});
            }
        unordered_map<int,int> freq;
        int ans = 0;
        for (auto [i, j] : A)
            for (auto [x, y] : B) {
                int dx = x-i+n-1;
                int dy = y-j+n-1;
                int key = dx*(2*n-1) + dy;
                ans = max(ans, ++freq[key]);
            }
        return ans;
    }
};
```

**Complexity:** O(n⁴) time worst case | O(n²) space

---

## Mistakes to Avoid

- Using `x-i` directly as key component — can be negative, causes hash collisions
- Using `dx*n + dy` instead of `dx*(2*n-1) + dy` — wrong width, non-unique keys for some pairs
- Iterating all cells instead of only 1s — wastes time on zeros that never contribute

---

## Pattern

**"Translation frequency counting"** — When finding optimal shift between two sets of points, enumerate all point pairs, compute the translation, encode as a single key, count frequencies. Max frequency = answer.

Related:
- LC 149 - Max Points on a Line (slope frequency counting)
- LC 1803 - Count Pairs With XOR in a Range
