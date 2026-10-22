# 203. Remove Linked List Elements

**Difficulty:** Easy  
**Topics:** Linked Lists  
**LeetCode:** [Link](https://leetcode.com/problems/remove-linked-list-elements/)

---

## Problem Statement

Remove all nodes with value equal to `val` from a linked list.

**Example:**
```
Input:  head=1->2->6->3->4->5->6, val=6
Output: 1->2->3->4->5
```

---

## Intuition & Approach

**Dummy head + single pass:**
Use a dummy node before head to handle edge case of removing head node. Traverse, skip nodes with matching value.

**Dry run with `1->2->6->3->6`, val=6:**
```
dummy->1->2->6->3->6
temp=dummy
temp->next=1 (1≠6, advance)
temp->next=2 (2≠6, advance)
temp->next=6 (6==6, skip: temp->next=3)
temp->next=3 (3≠6, advance)
temp->next=6 (6==6, skip: temp->next=null)
Result: 1->2->3 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* temp = dummy;
        while (temp->next) {
            if (temp->next->val == val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return dummy->next;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Advancing `temp` after deletion — may skip next node which could also match val
- Not using dummy head — removing actual head requires special case handling

---

## Pattern

**"Dummy head for deletion"** — Simplifies head removal edge case. Check `temp->next->val` and update `temp->next` to skip. Don't advance `temp` on deletion.

Related: LC 82 - Remove Duplicates from Sorted List II, LC 237 - Delete Node in a Linked List
