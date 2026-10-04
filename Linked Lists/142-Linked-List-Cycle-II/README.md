# 142. Linked List Cycle II

**Difficulty:** Medium  
**Topics:** Linked Lists, Two Pointers, Math  
**LeetCode:** [Link](https://leetcode.com/problems/linked-list-cycle-ii/)

---

## Problem Statement

Given a linked list, return the node where the cycle begins. Return `null` if no cycle.

**Example:**
```
Input:  3->2->0->-4 (tail connects to node at index 1)
Output: node with value 2
```

---

## Intuition & Approach

**Floyd's + Math to find cycle entry:**

**Phase 1:** Detect cycle using slow/fast pointers (same as LC 141).

**Phase 2:** Reset `slow` to head. Move both `slow` and `fast` one step at a time. They meet at the cycle entry point.

**Why this works (math):**
Let:
- `F` = distance from head to cycle entry
- `C` = cycle length
- `h` = distance from entry to meeting point

When they meet: `slow` traveled `F + h`, `fast` traveled `F + h + C` (one full loop more).
Since fast = 2 × slow: `2(F+h) = F+h+C` → `F = C - h`

So distance from head to entry = distance from meeting point to entry (going forward in cycle). Moving one pointer from head and one from meeting point at same speed → they meet at entry! ✅

**Dry run with `3->2->0->-4` (cycle at node 2, C=3):**
```
Phase 1: slow and fast meet at -4 (h=2 from entry)
Phase 2: slow=head(3), fast=-4
  slow=2, fast=2 -> MEET at cycle entry ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Moving fast two steps in phase 2 — must move one step each in phase 2
- Returning fast instead of slow — both point to same node at meeting point, either works

---

## Pattern

**"Floyd's + entry detection"** — After meeting point found, reset one pointer to head, advance both one step — they meet at cycle entry. Mathematical proof based on `F = C - h`.

Related: LC 141 - Linked List Cycle, LC 287 - Find Duplicate Number
