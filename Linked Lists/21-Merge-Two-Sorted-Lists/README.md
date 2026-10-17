# 21. Merge Two Sorted Lists

**Difficulty:** Easy  
**Topics:** Linked Lists, Recursion  
**LeetCode:** [Link](https://leetcode.com/problems/merge-two-sorted-lists/)

---

## Problem Statement

Merge two sorted linked lists and return the merged list (sorted).

**Example:**
```
Input:  l1=1->2->4, l2=1->3->4
Output: 1->1->2->3->4->4
```

---

## Intuition & Approach

**Iterative with dummy head:**
Compare heads of both lists, attach the smaller one to result, advance that pointer. Use dummy head to simplify edge cases.

**Dry run with `1->2->4` and `1->3->4`:**
```
dummy->
1<=1: attach l1=1, l1=2
1<3:  attach l1=2... wait l2=1 first
Actually: 1==1 attach l1=1, l1=2
2>1: attach l2=1, l2=3
2<3: attach l1=2, l1=4
4>3: attach l2=3, l2=4
4==4: attach l1=4, l1=null
attach remaining l2=4
Result: 1->1->2->3->4->4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) { temp->next = l1; l1 = l1->next; }
            else { temp->next = l2; l2 = l2->next; }
            temp = temp->next;
        }
        temp->next = l1 ? l1 : l2;
        return dummy->next;
    }
};
```

**Complexity:** O(m+n) time | O(1) space

---

## Mistakes to Avoid

- Not attaching remaining list at end — `temp->next = l1 ? l1 : l2` handles leftover nodes in one line
- Forgetting dummy head — without it, handling empty list edge case requires extra code

---

## Pattern

**"Dummy head + merge"** — Foundation for merge sort on linked lists (LC 148), merging k sorted lists (LC 23).
