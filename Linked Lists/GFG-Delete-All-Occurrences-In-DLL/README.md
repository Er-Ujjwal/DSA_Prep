# Delete All Occurrences of a Given Key in a Doubly Linked List

**Difficulty:** Medium  
**Topics:** Linked Lists (Doubly)  
**GFG:** [Link](https://www.geeksforgeeks.org/problems/delete-all-occurrences-of-a-given-key-in-a-doubly-linked-list/1)

---

## Problem Statement

Given a doubly linked list and integer `x`, delete all nodes with value `x`.

**Example:**
```
Input:  2<->2<->10<->8<->4<->2<->5<->2, x=2
Output: 10<->8<->4<->5
```

---

## Intuition & Approach

**Traverse and unlink matching nodes:**

For each node with `data == x`:
- If it's head: move head forward
- Update `prev` of next node
- Update `next` of prev node
- Delete the node

Handle both prev and next pointer updates carefully for doubly linked list.

**Dry run with `2<->2<->10`, x=2:**
```
temp=2(head): match, head=2(second), head->prev=null
temp=2(second): match, head=10, head->prev=null
temp=10: no match, advance
Result: 10 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while (temp) {
            if (temp->data == x) {
                if (temp == head) head = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                if (temp->prev) temp->prev->next = temp->next;
                Node* del = temp;
                temp = temp->next;
                delete del;
            } else {
                temp = temp->next;
            }
        }
        return head;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Not updating `head` when head node matches — head becomes dangling
- Not checking null before accessing `temp->next->prev` or `temp->prev->next`
- Advancing `temp` before deleting — use a `del` pointer, advance `temp` first

---

## Pattern

**"Doubly linked list deletion"** — Update both `prev->next` and `next->prev` on deletion. Always handle head separately. Same pattern for all DLL node removal problems.

Related: LC 203 - Remove Linked List Elements (singly LL version)
