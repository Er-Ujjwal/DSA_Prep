# 234. Palindrome Linked List

**Difficulty:** Easy  
**Topics:** Linked Lists, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/palindrome-linked-list/)

---

## Problem Statement

Given the head of a linked list, return `true` if it is a palindrome.

**Example:**
```
Input:  1->2->2->1  -> true
Input:  1->2        -> false
```

---

## Intuition & Approach

**Find middle → Reverse second half → Compare:**

1. Use slow/fast pointers to find the middle
2. Reverse the second half of the list
3. Compare first half and reversed second half node by node

**Why this is O(1) space:**
No extra array — reverse in place and compare directly.

**Dry run with `1->2->2->1`:**
```
slow/fast to find middle:
  slow=1, fast=1
  slow=2, fast=2->1(end)
  slow=2 (middle)

Reverse from slow->next: 1->2 becomes 2->1

Compare:
  head=1 vs newHead=1 ✅
  head=2 vs newHead=2 ✅
return true ✅
```

**Dry run with `1->2->3->2->1` (odd length):**
```
slow stops at 3 (middle)
Reverse 2->1 to 1->2
Compare: 1==1 ✅, 2==2 ✅
return true ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = nullptr, *temp = head;
        while (temp) {
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        ListNode* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* newHead = reverseLL(slow->next);
        slow = head;
        while (newHead) {
            if (slow->val != newHead->val) return false;
            slow = slow->next;
            newHead = newHead->next;
        }
        return true;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Using `fast = head->next` offset for middle — works too but need to verify odd/even length behavior
- Not handling single node — return `true` immediately
- Comparing second half length to first — second half may be shorter for odd length; loop on `newHead` (second half) handles this correctly

---

## Pattern

**"Find middle + reverse second half + compare"** — Classic O(1) space palindrome check for linked lists. Combines slow/fast pointer technique with in-place reversal.

Related:
- LC 206 - Reverse Linked List (used as subroutine)
- LC 876 - Middle of Linked List
- LC 2095 - Delete Middle Node
