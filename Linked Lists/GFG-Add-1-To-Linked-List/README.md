# Add 1 to a Linked List Number

**Difficulty:** Medium  
**Topics:** Linked Lists, Recursion  
**GFG:** [Link](https://www.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1)

---

## Problem Statement

Given a linked list where each node contains a single digit (most significant first), add 1 to the number and return the modified list.

**Example:**
```
Input:  4->5->9
Output: 4->6->0  (459 + 1 = 460)

Input:  9->9->9
Output: 1->0->0->0  (999 + 1 = 1000)
```

---

## Intuition & Approach

**Reverse → Add → Reverse back:**
1. Reverse the list (LSB first)
2. Add 1 with carry propagation
3. If carry remains after all nodes, add new node
4. Reverse back

**OR Recursive approach:**
Recurse to end, add 1 at last node, propagate carry back.

**Dry run with `9->9->9`:**
```
Reverse: 9->9->9
Add 1: 9+1=10, carry=1, node=0 -> 0->9->9
       9+1=10, carry=1, node=0 -> 0->0->9
       9+1=10, carry=1, node=0 -> 0->0->0
carry=1 -> add node 1 -> 1->0->0->0
Reverse: 1->0->0->0 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    Node* addOne(Node* head) {
        // Reverse
        Node* prev = nullptr, *curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
        // Add 1
        Node* temp = head;
        int carry = 1;
        while (temp && carry) {
            int sum = temp->data + carry;
            temp->data = sum % 10;
            carry = sum / 10;
            if (!temp->next && carry) {
                temp->next = new Node(1);
                carry = 0;
            }
            temp = temp->next;
        }
        // Reverse back
        prev = nullptr; curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Not handling all-9s case — need to add new head node when carry persists after last node
- Forgetting to reverse back — result must be MSB first

---

## Pattern

**"Reverse → operate → reverse"** — When operating from the end of a linked list is easier (like addition with carry), reverse first, operate forward, reverse back. Same approach for LC 445 (Add Two Numbers II).
