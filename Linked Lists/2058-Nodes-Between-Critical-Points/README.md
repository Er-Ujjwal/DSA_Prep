# 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

**Difficulty:** Medium  
**Topics:** Linked Lists  
**LeetCode:** [Link](https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/)

---

## Problem Statement

A **critical point** is a node that is either a local minimum or local maximum (strictly). Given a linked list, return `[minDistance, maxDistance]` between any two critical points. Return `[-1,-1]` if fewer than 2 critical points exist.

**Example:**
```
Input:  [3,1,4,1,5,9,2,6]
Output: [1,4]
Critical points at indices: 1(local min), 2(local max), 4(local min) wait...
Let me verify: 3>1<4 -> 1 is local min (idx 1)
               1<4>1 -> 4 is local max (idx 2)
               4>1<5 -> 1 is local min (idx 3)
               1<5... 5<9 -> not critical yet
               ...
```

---

## Intuition & Approach

**Key Insight:**
- **Minimum distance** → between any two adjacent critical points (track consecutive gaps)
- **Maximum distance** → always between the **first and last** critical point

Single pass: track `first` and `last` critical point indices. Update `minDist` between consecutive critical points as we go.

**Why max = last - first?**
All critical points lie between first and last. The maximum gap is always the full span — first to last. No need to track all positions.

**Dry run with `[5,3,1,2,5,1,4]`:**
```
prev=5, curr=3: 3<5 and 3<1? No (3>1) -> not critical
prev=3, curr=1: 1<3 and 1<2? Yes -> local min, first=1, last=1, idx=2
prev=1, curr=2: 2>1 and 2<5? Not critical (2<5 means not local max)

Wait: local max needs curr>prev AND curr>next
curr=2, prev=1, next=5: 2>1 but 2<5 -> not local max

prev=2, curr=5: 5>2 and 5>1? Yes -> local max, first=1(unchanged), minDist=min(INF,4-2... 

Let me track indices properly:
idx starts at 1 (for head->next position)
```

---

## My Solution

```cpp
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1, last = -1, minDist = INT_MAX, index = 1;
        ListNode* prev = head;
        ListNode* curr = head->next;
        while (curr->next != nullptr) {
            if ((curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val)) {
                if (first == -1) first = index;
                else minDist = min(minDist, index - last);
                last = index;
            }
            prev = curr;
            curr = curr->next;
            index++;
        }
        if (first == last) return {-1, -1};
        return {minDist, last - first};
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Checking `first == -1 && last == -1` for no critical points — wrong, use `first == last` which catches both zero and one critical point cases
- Updating `minDist` before setting `last` on first critical point — `minDist = index - last` would be garbage if `last` not set yet; the `if(first==-1)` guard handles this
- Forgetting `curr->next != nullptr` as while condition — need three consecutive nodes to check local min/max

---

## Pattern

**"Single pass critical point tracking"** — Track first and last occurrences, update minimum gap between consecutive occurrences on the fly. Maximum gap = last - first always.

Same pattern applicable to:
- Any "min/max distance between special elements" in a list
- LC 1019 - Next Greater Node In Linked List
