# 328. Odd Even Linked List

**Difficulty:** Medium  
**Topics:** Linked Lists  
**LeetCode:** [Link](https://leetcode.com/problems/odd-even-linked-list/)

---

## Problem Statement

Regroup a linked list so all odd-indexed nodes come first, followed by all even-indexed nodes. Must be O(1) space.

**Example:**
```
Input:  1->2->3->4->5
Output: 1->3->5->2->4
```

---

## Intuition & Approach

**Two pointer weaving:**
Maintain two pointers — `odd` and `even`. Weave them by skipping alternate nodes. Save `firstEven` to connect at end.

```
odd=1, even=2, firstEven=2

Step 1: odd->next = 3, even->next = 4
        odd=3, even=4
Step 2: odd->next = 5, even->next = null
        odd=5, even=null
Connect: odd->next = firstEven(2)
Result: 1->3->5->2->4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* firstEven = head->next;
        while (even && even->next) {
            odd->next = odd->next->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = firstEven;
        return head;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Not saving `firstEven` before the loop — needed to connect odd tail to even head
- While condition `even && even->next` — both needed to safely access `even->next->next`

---

## Pattern

**"Two-list weaving"** — Split into two sublists by alternating, then connect. Same idea as LC 86 (partition list) and LC 143 (reorder list).
