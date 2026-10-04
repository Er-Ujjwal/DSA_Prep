# Cycle Length in Linked List

**Difficulty:** Medium  
**Topics:** Linked Lists, Two Pointers  
**GFG:** [Link](https://www.geeksforgeeks.org/problems/find-length-of-loop/1)

---

## Problem Statement

Given a linked list, find the length of the cycle if it exists. Return 0 if no cycle.

**Example:**
```
Input:  1->2->3->4->5->2 (cycle at node 2)
Output: 4  (cycle: 2->3->4->5->2, length=4)
```

---

## Intuition & Approach

**Floyd's detection + count cycle length:**

**Phase 1:** Find meeting point using slow/fast pointers (LC 141 approach).

**Phase 2:** Once meeting point found, keep `slow` fixed and move `fast` around the cycle counting steps until it returns to `slow`.

**Dry run with `1->2->3->4->5->2` (cycle at 2):**
```
Phase 1: slow and fast meet somewhere in cycle (say at node 4)
Phase 2: count=1, fast=fast->next
  fast=5, count=2
  fast=2, count=3
  fast=3, count=4
  fast=4==slow -> return 4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int lengthOfLoop(Node *head) {
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int count = 1;
                fast = fast->next;
                while (slow != fast) {
                    count++;
                    fast = fast->next;
                }
                return count;
            }
        }
        return 0;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Starting `count = 0` — first step already taken (`fast = fast->next`), so start at 1
- Moving both slow and fast in phase 2 — only move fast, keep slow fixed as reference

---

## Pattern

**"Floyd's + cycle measurement"** — After detecting meeting point, traverse the cycle once with one pointer to count its length. Natural extension of LC 141 and LC 142.

Related: LC 141 - Linked List Cycle, LC 142 - Linked List Cycle II
