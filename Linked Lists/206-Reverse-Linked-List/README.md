# 206. Reverse Linked List

**Difficulty:** Easy  
**Topics:** Linked Lists  
**LeetCode:** [Link](https://leetcode.com/problems/reverse-linked-list/)

---

## Problem Statement

Reverse a singly linked list and return the new head.

**Example:**
```
Input:  1->2->3->4->5
Output: 5->4->3->2->1
```

---

## Intuition & Approach

**Iterative — Three pointer technique:**
Maintain `prev`, `curr`, and `next`. At each step, reverse the `curr->next` pointer to point to `prev`, then advance all three pointers forward.

```
prev=null, curr=1->2->3->4->5

Step 1: next=2, 1->null, prev=1, curr=2
Step 2: next=3, 2->1, prev=2, curr=3
Step 3: next=4, 3->2, prev=3, curr=4
Step 4: next=5, 4->3, prev=4, curr=5
Step 5: next=null, 5->4, prev=5, curr=null
return prev=5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr != NULL) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```

**Complexity:** O(n) time | O(1) space

**Recursive alternative:**
```cpp
ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* newHead = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
}
```

---

## Mistakes to Avoid

- Losing reference to `next` before reversing — always save `next = curr->next` first
- Returning `curr` instead of `prev` — at loop end, `curr` is null; `prev` is the new head

---

## Pattern

**"Three pointer reversal"** — Foundation for many linked list problems. Used in LC 92 (reverse sublist), LC 25 (reverse k-group), LC 234 (palindrome linked list).
