# 1386. Cinema Seat Allocation

**Difficulty:** Medium  
**Topics:** Arrays, Bit Manipulation, Greedy, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/cinema-seat-allocation/)

---

## Problem Statement

A cinema has `n` rows, each with 10 seats (1-10). Seats 1 and 10 are aisles. Given reserved seats, find the **maximum number of 4-person families** that can be seated. A family of 4 must sit in consecutive seats within a row, not including aisle seats.

Three valid placements per row:
- **Left:** seats 2,3,4,5
- **Middle:** seats 4,5,6,7
- **Right:** seats 6,7,8,9

**Example:**
```
Input:  n=3, reservedSeats=[[1,2],[1,3],[1,3],[2,6],[2,7]]
Output: 4
```

---

## Intuition & Approach

**Key observations:**
1. Seats 1 and 10 (aisles) are irrelevant — no family placement uses them
2. Each unreserved row can fit **exactly 2 families** (left + right zones don't overlap)
3. For reserved rows, check which of the 3 zones are fully free using bitmask

**Bitmask per row:** Set bit `seat` for each reserved seat in that row. Only track seats 2-9 (aisles don't affect placements).

**Zone checks using bitmask:**
```
Left   (seats 2,3,4,5): mask & 0b0000111100 == 0  -> bits 2,3,4,5
Middle (seats 4,5,6,7): mask & 0b0011110000 == 0  -> bits 4,5,6,7
Right  (seats 6,7,8,9): mask & 0b1111000000 == 0  -> bits 6,7,8,9
```

**Counting:**
- Unreserved rows: `(n - mp.size()) * 2`
- Reserved rows: +2 if left AND right both free, else +1 if any zone free

**Why left+right but not left+middle or middle+right?**
Left (2-5) and right (6-9) don't overlap → both can fit simultaneously.
Middle (4-7) overlaps with both left and right → can't combine with either.

**Dry run with `n=3, [[1,2],[1,3],[2,6],[2,7]]`:**
```
Row 1: mask = (1<<2)|(1<<3) = 0b00001100
  left:   mask & 0b00111100 = 0b00001100 != 0 -> blocked
  middle: mask & 0b11110000 = 0 -> free ✅
  right:  mask & 0b111000000... wait seats 6-9
  -> left blocked, middle free -> ans += 1

Row 2: mask = (1<<6)|(1<<7) = 0b11000000
  left:   mask & 0b00111100 = 0 -> free ✅
  middle: mask & 0b11110000 != 0 -> blocked
  right:  mask & 0b1111000000... bits 6,7,8,9
  -> left free, right blocked -> ans += 1

Row 3: unreserved -> ans += 2

Base: (3-2)*2 = 2, reserved rows add 1+1 = 2 -> total = 4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> mp;
        for (auto &x : reservedSeats) {
            int row = x[0], seat = x[1];
            if (seat >= 2 && seat <= 9) mp[row] |= (1 << seat);
        }
        int ans = (n - mp.size()) * 2;
        for (auto &[row, mask] : mp) {
            bool left   = !(mask & ((1<<2)|(1<<3)|(1<<4)|(1<<5)));
            bool middle = !(mask & ((1<<4)|(1<<5)|(1<<6)|(1<<7)));
            bool right  = !(mask & ((1<<6)|(1<<7)|(1<<8)|(1<<9)));
            if (left && right) ans += 2;
            else if (left || middle || right) ans += 1;
        }
        return ans;
    }
};
```

**Complexity:** O(R) time | O(R) space — where R = number of reserved seats

---

## Mistakes to Avoid

- Including seat 1 and 10 in the bitmask — they're aisles and never part of any family placement, filtering them out keeps the mask clean
- Checking `left && middle` or `middle && right` for +2 — wrong, middle overlaps with both; only `left && right` gives 2 families
- Forgetting `mp[row] |= (1 << seat)` needs OR not assignment — multiple reserved seats per row must all be tracked

---

## Pattern

**"Bitmask per entity + zone check"** — When seats/positions in a fixed-size structure need to be tracked, use a bitmask. Zone availability = `!(mask & zone_mask)`. Efficient and clean for fixed-width problems.

Related:
- LC 3471 - Find Largest Almost Missing Integer
- LC 2527 - Find Xor-Beauty of Array
