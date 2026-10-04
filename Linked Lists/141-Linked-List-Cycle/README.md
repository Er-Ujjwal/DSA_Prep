# 141. Linked List Cycle

**Difficulty:** Easy  
**Topics:** Linked Lists, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/linked-list-cycle/)

---

## Problem Statement

Given head of a linked list, determine if it has a cycle. Return `true` if cycle exists.

**Example:**
```
Input:  3->2->0->-4 (tail connects to node 1)
Output: true
```

---

## Intuition & Approach

**Floyd's Cycle Detection (Tortoise & Hare):**

Move `slow` one step, `fast` two steps. If a cycle exists, fast will eventually lap slow and they'll meet. If no cycle, fast reaches null.

**Why they must meet inside cycle:**
Once both are in the cycle, the distance between them decreases by 1 each step (fast gains 1 on slow). They will always meet within `cycle_length` steps.

**Dry run with `3->2->0->-4->2` (cycle at node 2):**
```
slow=3, fast=3
slow=2, fast=0
slow=0, fast=2  (fast loops back)
slow=-4, fast=-4 -> MEET -> return true ✅
```

---

## My Solution

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Checking `slow == fast` before moving — both start at head, would return true immediately
- Not checking `fast->next` — `fast->next->next` crashes if `fast->next` is null

---

## Pattern

**"Floyd's Cycle Detection"** — Two pointers at different speeds. If cycle exists, they meet. Foundation for LC 142 (find cycle start) and GFG cycle length.

Related: LC 142, LC 287 - Find Duplicate Number, GFG Cycle Length
