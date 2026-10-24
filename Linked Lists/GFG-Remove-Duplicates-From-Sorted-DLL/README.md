# Remove Duplicates from a Sorted Doubly Linked List

**Difficulty:** Medium  
**Topics:** Linked Lists (Doubly)  
**GFG:** [Link](https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1)

---

## Problem Statement

Given a sorted doubly linked list, remove all duplicate nodes (keep one occurrence of each).

**Example:**
```
Input:  1<->1<->1<->2<->3<->3
Output: 1<->2<->3
```

---

## Intuition & Approach

**Traverse, skip duplicates, update both prev/next pointers:**

For each node, check if next node has same value. If yes, skip all duplicates and update `temp->next` and the new next node's `prev`.

**Dry run with `1<->1<->1<->2<->3<->3`:**
```
temp=1: next=1, same → skip while: nextNode goes to 2
  temp->next=2, 2->prev=temp(1)
temp=2: next=3, diff → advance
temp=3: next=3, same → skip: nextNode=null
  temp->next=null
return 1<->2<->3 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    Node* removeDuplicates(Node* headRef) {
        Node* temp = headRef;
        while (temp && temp->next) {
            Node* nextNode = temp->next;
            while (nextNode && nextNode->data == temp->data) {
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                delete duplicate;
            }
            temp->next = nextNode;
            if (nextNode) nextNode->prev = temp;
            temp = temp->next;
        }
        return headRef;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Not updating `nextNode->prev = temp` — DLL must maintain backward pointers
- Not deleting skipped nodes — memory leak in C++

---

## Pattern

**"Skip duplicates in sorted DLL"** — Same as singly linked list but update both `next` and `prev`. Inner while skips all copies, outer while advances to next unique value.

Related: LC 82 - Remove Duplicates from Sorted List II, LC 83 - Remove Duplicates from Sorted List I
