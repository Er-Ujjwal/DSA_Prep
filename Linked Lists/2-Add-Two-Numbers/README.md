# 2. Add Two Numbers

**Difficulty:** Medium  
**Topics:** Linked Lists, Math  
**LeetCode:** [Link](https://leetcode.com/problems/add-two-numbers/)

---

## Problem Statement

Two non-empty linked lists represent two non-negative integers in **reverse order**. Add them and return the result as a linked list.

**Example:**
```
Input:  l1=2->4->3, l2=5->6->4
Output: 7->0->8  (342 + 465 = 807)
```

---

## Intuition & Approach

**Simulate digit-by-digit addition with carry:**

Traverse both lists simultaneously. At each step:
- Sum = `l1->val + l2->val + carry`
- New digit = `sum % 10`
- New carry = `sum / 10`

Use dummy head to simplify result list construction. Continue until both lists exhausted AND carry is 0.

**Dry run with `2->4->3` and `5->6->4`:**
```
Step 1: 2+5+0=7,  carry=0, node=7
Step 2: 4+6+0=10, carry=1, node=0
Step 3: 3+4+1=8,  carry=0, node=8
Result: 7->0->8 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = 0;
            if (l1) { sum += l1->val; l1 = l1->next; }
            if (l2) { sum += l2->val; l2 = l2->next; }
            sum += carry;
            carry = sum / 10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }
};
```

**Complexity:** O(max(m,n)) time | O(max(m,n)) space

---

## Mistakes to Avoid

- Not handling carry after both lists end — `while(l1 || l2 || carry)` covers this
- Checking `l1->val` without null check — always guard with `if(l1)` before accessing

---

## Pattern

**"Dummy head + carry propagation"** — Dummy node simplifies edge cases at head. Carry after loop handles final digit (e.g., 999+1=1000).

Related: LC 445 - Add Two Numbers II (forward order, use stack)
