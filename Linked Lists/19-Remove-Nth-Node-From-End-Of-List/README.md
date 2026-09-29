# 19. Remove Nth Node From End of List

**Difficulty:** Medium  
**Topics:** Linked Lists, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

---

## Problem Statement

Remove the nth node from the end of a linked list and return the head.

**Example:**
```
Input:  1->2->3->4->5, n=2
Output: 1->2->3->5
```

---

## Intuition & Approach

**Two-pass approach (used here):**
1. Count total length
2. Navigate to `(length - n)`th node from start
3. Delete next node

**One-pass optimal — Two pointers:**
Move `fast` n steps ahead, then move both `slow` and `fast` until `fast` reaches end. `slow` is now just before the node to delete.

**Dry run with `1->2->3->4->5`, n=2:**
```
count=5, target=(5-2)=3rd node from start
Navigate to node 3 (val=3)
Delete node 4 (val=4)
Result: 1->2->3->5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        if (!head->next) return {};
        ListNode* temp = head;
        int count = 0;
        while (temp) { count++; temp = temp->next; }
        if (n == count) return head->next;
        temp = head;
        for (int i = 1; i < count-n; i++) temp = temp->next;
        ListNode* delNode = temp->next;
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};
```

**Complexity:** O(n) time | O(1) space

**Optimal One-Pass:**
```cpp
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* dummy = new ListNode(0, head);
    ListNode* fast = dummy, *slow = dummy;
    for (int i = 0; i <= n; i++) fast = fast->next;
    while (fast) { slow = slow->next; fast = fast->next; }
    slow->next = slow->next->next;
    return dummy->next;
}
```

---

## Mistakes to Avoid

- Not handling `n == count` (remove head) — return `head->next`
- Off by one in loop — `i < count-n` not `i <= count-n`

---

## Pattern

**"Two pointer gap technique"** — Maintain n-gap between fast and slow pointers. When fast hits end, slow is at target. Classic for kth-from-end problems.
