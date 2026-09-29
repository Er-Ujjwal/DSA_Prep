# 2095. Delete the Middle Node of a Linked List

**Difficulty:** Medium  
**Topics:** Linked Lists, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/)

---

## Problem Statement

Delete the middle node of a linked list. If even number of nodes, delete the second middle.

**Example:**
```
Input:  1->3->4->7->1->2->6
Output: 1->3->4->1->2->6  (deleted node 7 at index 3)
```

---

## Intuition & Approach

**Fast & Slow pointer with offset:**
Move `fast` two steps ahead initially (`fast = head->next->next`), then advance both until `fast` hits end. `slow` ends up just before the middle node.

Why offset? Standard slow/fast gives middle node itself. We need the node BEFORE middle to delete it.

**Dry run with `1->3->4->7->1->2->6`:**
```
slow=1, fast=4 (skipped 2 steps)
Step 1: slow=3, fast=1
Step 2: slow=4, fast=6
Step 3: fast->next=null, stop
slow=4, delete slow->next=7
Result: 1->3->4->1->2->6 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode* slow = head;
        ListNode* fast = head->next->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Using standard `fast=head` start — puts slow AT middle, not before it
- Not handling single node — return NULL (no middle exists or list becomes empty)

---

## Pattern

**"Slow/fast with offset"** — Adjust starting position of fast pointer to control where slow stops. Offset by 1 or 2 nodes changes whether slow ends at, before, or after middle.
