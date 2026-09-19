# 1401. Circle and Rectangle Overlapping

**Difficulty:** Medium  
**Topics:** Arrays, Math, Geometry  
**LeetCode:** [Link](https://leetcode.com/problems/circle-and-rectangle-overlapping/)

---

## Problem Statement

Given a circle (center `(xCenter, yCenter)`, radius `radius`) and axis-aligned rectangle `(x1,y1)` to `(x2,y2)`, return `true` if they overlap.

**Example:**
```
Input:  radius=1, xCenter=0, yCenter=0, x1=1, y1=-1, x2=3, y2=1
Output: true
```

---

## Intuition & Approach

**Key Insight:** Find the **closest point on the rectangle** to the circle center. If the distance from center to that point ≤ radius → overlap.

**Closest point formula:**
- `closestX = clamp(xCenter, x1, x2)` = `max(x1, min(xCenter, x2))`
- `closestY = clamp(yCenter, y1, y2)` = `max(y1, min(yCenter, y2))`

If center is inside rectangle → closest point IS the center → distance = 0 → always overlaps.
If center is outside → closest point is on the nearest edge/corner.

**Distance check:** `dx² + dy² <= radius²` (avoid sqrt for precision)

**Dry run with `radius=1, center=(0,0), rect=(1,-1)to(3,1)`:**
```
closestX = max(1, min(0,3)) = max(1,0) = 1
closestY = max(-1, min(0,1)) = max(-1,0) = 0
dx=0-1=-1, dy=0-0=0
1+0=1 <= 1 -> true ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter,
                      int x1, int y1, int x2, int y2) {
        int closestX = max(x1, min(xCenter, x2));
        int closestY = max(y1, min(yCenter, y2));
        int x = xCenter - closestX;
        int y = yCenter - closestY;
        return x*x + y*y <= radius*radius;
    }
};
```

**Complexity:** O(1) time | O(1) space

---

## Mistakes to Avoid

- Using `sqrt(x*x + y*y) <= radius` — floating point precision issues; compare squares instead
- Getting clamp formula wrong — `max(x1, min(xCenter, x2))` is the standard clamp to `[x1,x2]`

---

## Pattern

**"Closest point on AABB to circle center"** — Clamp center coordinates to rectangle bounds → closest point. Check squared distance vs radius². Extends to 3D (add Z clamp).

Related:
- LC 836 - Rectangle Overlap
- LC 593 - Valid Square
