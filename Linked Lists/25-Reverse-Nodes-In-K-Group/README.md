# 25. Reverse Nodes in k-Group

**Difficulty:** Hard  
**Topics:** Linked Lists, Recursion  
**LeetCode:** [Link](https://leetcode.com/problems/reverse-nodes-in-k-group/)

---

## Problem Statement

Reverse every k nodes of a linked list. If remaining nodes < k, leave them as is.

**Example:**
```
Input:  1->2->3->4->5, k=2
Output: 2->1->4->3->5

Input:  1->2->3->4->5, k=3
Output: 3->2->1->4->5
```

---

## Intuition & Approach

**Check k nodes exist → reverse them → recurse on rest:**

1. Check if at least k nodes remain — if not, return head as is
2. Reverse first k nodes using standard reversal
3. Connect reversed group's tail to recursive result of remaining list
4. Return new head (was kth node)

**Dry run with `1->2->3->4->5`, k=2:**
```
Check: 2 nodes exist ✅
Reverse [1->2]: 2->1, tail=1
1->next = reverse([3->4->5], k=2)
  Check: 2 nodes exist ✅
  Reverse [3->4]: 4->3, tail=3
  3->next = reverse([5], k=2)
    Check: only 1 node < k → return 5
  3->next = 5
  return 4
1->next = 4->3->5
return 2->1->4->3->5 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        int count = 0;
        while (temp && count < k) { temp = temp->next; count++; }
        if (count < k) return head;
        ListNode* prev = NULL, *curr = head;
        for (int i = 0; i < k; i++) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};
```

**Complexity:** O(n) time | O(n/k) recursive stack space

---

## Mistakes to Avoid

- Not checking k nodes exist before reversing — partial reversal gives wrong result
- `head->next = reverseKGroup(curr, k)` — `head` is now the tail of reversed group, `curr` is start of remaining

---

## Pattern

**"Reverse in groups + recursion"** — Reverse fixed-size chunks, connect via recursion. Extension of LC 206 (reverse full list).
