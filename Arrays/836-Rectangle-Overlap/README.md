# 836. Rectangle Overlap

**Difficulty:** Easy  
**Topics:** Arrays, Math, Geometry  
**LeetCode:** [Link](https://leetcode.com/problems/rectangle-overlap/)

---

## Problem Statement

Given two rectangles represented as `[x1, y1, x2, y2]` (bottom-left and top-right corners), return `true` if they overlap. Rectangles that only touch at edges/corners don't count.

**Example:**
```
Input:  rec1=[0,0,2,2], rec2=[1,1,3,3]
Output: true

Input:  rec1=[0,0,1,1], rec2=[1,0,2,1]
Output: false  (touching edge only)
```

---

## Intuition & Approach

Two rectangles overlap if and only if their intersection has **positive width AND positive height**.

**Intersection width:** `min(rec1[2], rec2[2]) - max(rec1[0], rec2[0])`
**Intersection height:** `min(rec1[3], rec2[3]) - max(rec1[1], rec2[1])`

If both > 0 → overlap exists. If either ≤ 0 → no overlap (touching or separated).

**Dry run with `rec1=[0,0,2,2], rec2=[1,1,3,3]`:**
```
width  = min(2,3) - max(0,1) = 2-1 = 1 > 0 ✅
height = min(2,3) - max(0,1) = 2-1 = 1 > 0 ✅
return true ✅
```

**Dry run with `rec1=[0,0,1,1], rec2=[1,0,2,1]`:**
```
width  = min(1,2) - max(0,1) = 1-1 = 0, not > 0
return false ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int width  = min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]);
        int height = min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]);
        return width > 0 && height > 0;
    }
};
```

**Complexity:** O(1) time | O(1) space

---

## Mistakes to Avoid

- Using `>= 0` instead of `> 0` — touching edges don't count as overlap per problem definition
- Checking non-overlap condition instead — `rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]` and negating — works but less clean

---

## Pattern

**"Intersection of intervals in 2D"** — Overlap in 2D = overlap in both X and Y axes independently. Intersection of `[a,b]` and `[c,d]` = `[max(a,c), min(b,d)]`, positive length means overlap.

Same logic extends to 3D (add Z axis check).

Related:
- LC 56 - Merge Intervals
- LC 57 - Insert Interval
