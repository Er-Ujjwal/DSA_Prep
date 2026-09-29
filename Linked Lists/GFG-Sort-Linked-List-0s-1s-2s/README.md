# Sort a Linked List of 0s, 1s and 2s

**Difficulty:** Medium  
**Topics:** Linked Lists  
**GFG:** [Link](https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1)

---

## Problem Statement

Given a linked list containing only 0s, 1s, and 2s, sort it so all 0s come first, then 1s, then 2s.

**Example:**
```
Input:  1->0->2->1->0
Output: 0->0->1->1->2
```

---

## Intuition & Approach

**Three dummy head pointers — Dutch National Flag for linked lists:**

Create three separate lists using dummy heads for 0s, 1s, and 2s. Traverse original list, append each node to its corresponding list. Connect the three lists at the end.

This avoids counting and reassigning values — works directly with node connections.

**Dry run with `1->0->2->1->0`:**
```
Traverse:
1 -> oneList
0 -> zeroList
2 -> twoList
1 -> oneList
0 -> zeroList

Connect: zeroList -> oneList -> twoList
Result: 0->0->1->1->2 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        Node* zeroHead = new Node(-1);
        Node* oneHead  = new Node(-1);
        Node* twoHead  = new Node(-1);
        Node* zero = zeroHead, *one = oneHead, *two = twoHead;
        Node* temp = head;
        while (temp) {
            if      (temp->data == 0) { zero->next = temp; zero = temp; }
            else if (temp->data == 1) { one->next  = temp; one  = temp; }
            else                      { two->next  = temp; two  = temp; }
            temp = temp->next;
        }
        zero->next = oneHead->next ? oneHead->next : twoHead->next;
        one->next  = twoHead->next;
        two->next  = nullptr;
        Node* newHead = zeroHead->next;
        delete zeroHead; delete oneHead; delete twoHead;
        return newHead;
    }
};
```

**Complexity:** O(n) time | O(1) space (no extra nodes, just pointer manipulation)

---

## Mistakes to Avoid

- Not setting `two->next = nullptr` — old connections cause cycles
- `zero->next = oneHead->next ? oneHead->next : twoHead->next` — handles case when no 1s exist

---

## Pattern

**"Partition into k buckets"** — Create k dummy heads, route nodes, connect chains. Generalizes to any fixed number of categories. Same idea as LC 86 (partition list around value).
