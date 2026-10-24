# 82. Remove Duplicates from Sorted List II

**Difficulty:** Medium  
**Topics:** Linked Lists, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

---

## Problem Statement

Given sorted linked list, delete all nodes with duplicate values (keep only nodes that appear exactly once).

**Example:**
```
Input:  1->2->3->3->4->4->5
Output: 1->2->5

Input:  1->1->1->2->3
Output: 2->3
```

---

## Intuition & Approach

**Dummy head + skip all duplicates:**

Use `prev` pointer before a group of duplicates. When duplicates detected, skip entire group. If no duplicate, advance `prev`.

**Dry run with `1->2->3->3->4->4->5`:**
```
dummy->1->2->3->3->4->4->5
prev=dummy, temp=1

temp=1: next=2, 1≠2 → prev=1, temp=2
temp=2: next=3, 2≠3 → prev=2, temp=3
temp=3: next=3, 3==3 → skip all 3s
  while temp->next && temp->next->val==3: temp=temp->next(second 3)
  prev->next=temp->next=4, temp=4
temp=4: next=4, 4==4 → skip all 4s
  prev->next=5, temp=5
temp=5: next=null → prev=5, temp=null
Result: 1->2->5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* prev = dummyNode;
        ListNode* temp = head;
        while (temp) {
            if (temp->next && temp->val == temp->next->val) {
                while (temp->next && temp->val == temp->next->val)
                    temp = temp->next;
                prev->next = temp->next;
            } else {
                prev = temp;
            }
            temp = temp->next;
        }
        return dummyNode->next;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Advancing `prev` after skipping duplicates — `prev` must stay before the skipped group
- Confusing with LC 83 (Remove Duplicates I) — LC 83 keeps one copy, LC 82 removes ALL copies

---

## Pattern

**"Dummy head + skip group"** — When entire groups need removal, use `prev` to bypass groups. Don't advance `prev` during group skip.

Related: LC 83 - Remove Duplicates from Sorted List I, LC 203 - Remove Linked List Elements
