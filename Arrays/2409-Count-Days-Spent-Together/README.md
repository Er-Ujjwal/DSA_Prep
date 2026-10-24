# 2409. Count Days Spent Together

**Difficulty:** Easy  
**Topics:** Arrays, Math, Strings  
**LeetCode:** [Link](https://leetcode.com/problems/count-days-spent-together/)

---

## Problem Statement

Alice arrives on `arriveAlice` and leaves on `leaveAlice`. Bob arrives on `arriveBob` and leaves on `leaveBob`. Find overlapping days (both in the city). Assume non-leap year.

**Example:**
```
Input:  arriveAlice="08-15", leaveAlice="08-18", arriveBob="08-16", leaveBob="08-19"
Output: 3  (Aug 16, 17, 18)
```

---

## Intuition & Approach

**Convert dates to day numbers, find overlap:**

Convert each date to total days from Jan 1. Overlap = `max(0, min(leaveA, leaveB) - max(arriveA, arriveB) + 1)`.

**Date to days:** Sum days of all months before current month + day of current month.

**Dry run:**
```
arriveAlice="08-15" → days in Jan-Jul + 15 = 31+28+31+30+31+30+31+15 = 227
leaveAlice="08-18"  → 230
arriveBob="08-16"   → 228
leaveBob="08-19"    → 231

overlap = min(230,231) - max(227,228) + 1 = 230-228+1 = 3 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int dateToDays(string dateStr) {
        int month = stoi(dateStr.substr(0,2));
        int day = stoi(dateStr.substr(3,2));
        vector<int> daysPerMonth = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        return accumulate(daysPerMonth.begin(), daysPerMonth.begin()+month, 0) + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int arriveA = dateToDays(arriveAlice);
        int leaveA  = dateToDays(leaveAlice);
        int arriveB = dateToDays(arriveBob);
        int leaveB  = dateToDays(leaveBob);
        return max(0, min(leaveA, leaveB) - max(arriveA, arriveB) + 1);
    }
};
```

**Complexity:** O(1) time | O(1) space

---

## Mistakes to Avoid

- Forgetting `max(0, ...)` — when no overlap, formula gives negative; clamp to 0
- Off by one: `min(leave) - max(arrive) + 1` — the +1 includes both endpoints

---

## Pattern

**"Interval overlap"** — Overlap length = `max(0, min(end1,end2) - max(start1,start2) + 1)`. Same formula as LC 836 (Rectangle Overlap) generalized to 1D.

Related: LC 836 - Rectangle Overlap, LC 56 - Merge Intervals
