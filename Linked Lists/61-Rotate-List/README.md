# 61. Rotate List

**Difficulty:** Medium  
**Topics:** Linked Lists, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/rotate-list/)

---

## Problem Statement

Rotate a linked list to the right by k places.

**Example:**
```
Input:  1->2->3->4->5, k=2
Output: 4->5->1->2->3
```

---

## Intuition & Approach

**Make circular → find new tail → break:**

1. Find length and make list circular (tail->next = head)
2. Effective rotation = `k % len` (k can be > len)
3. New tail is at position `len - k % len - 1` from start
4. New head is `newTail->next`, break the circle

**Dry run with `1->2->3->4->5`, k=2:**
```
len=5, make circular: 5->next=1
effective k = 2%5 = 2
new tail at position 5-2-1=2 (0-indexed) = node 3
new head = node 4
Break: 3->next = null
Result: 4->5->1->2->3 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;
        int len = 1;
        ListNode* tail = head;
        while (tail->next) { tail = tail->next; len++; }
        k = k % len;
        if (k == 0) return head;
        tail->next = head;
        ListNode* newTail = head;
        for (int i = 0; i < len - k - 1; i++) newTail = newTail->next;
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Not taking `k % len` — for k=5 on list of 5, rotation is identity (no change)
- Not handling `k == 0` after mod — avoid unnecessary traversal

---

## Pattern

**"Make circular → find cut point → break"** — Rotation = moving last k nodes to front. Circular connection + cut at right point handles all edge cases cleanly.
