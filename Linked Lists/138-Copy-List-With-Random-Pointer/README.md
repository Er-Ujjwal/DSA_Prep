# 138. Copy List with Random Pointer

**Difficulty:** Medium  
**Topics:** Linked Lists, Hash Map  
**LeetCode:** [Link](https://leetcode.com/problems/copy-list-with-random-pointer/)

---

## Problem Statement

Deep copy a linked list where each node has `next` and `random` pointers. Return the head of the copied list.

**Example:**
```
Input:  [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: Deep copy of the same structure
```

---

## Intuition & Approach

**Three-pass in-place approach (O(1) space):**

**Pass 1:** Insert copy nodes between each original node:
`1->1'->2->2'->3->3'`

**Pass 2:** Set `random` pointers for copy nodes:
`copy->random = original->random->next` (since copy of X is X->next)

**Pass 3:** Separate the two lists, restore original.

**Why this works:** By interleaving copies, the copy of any node `X` is always `X->next`. So to set `copy->random`, just do `original->random->next`.

**Dry run with `1->2->3`:**
```
Pass 1: 1->1'->2->2'->3->3'
Pass 2: if 1->random=3, then 1'->random=3->next=3' ✅
Pass 3: restore 1->2->3, extract 1'->2'->3'
```

---

## My Solution

```cpp
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        // Pass 1: interleave copies
        Node* temp = head;
        while (temp) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            temp->next = copy;
            copy->next = nextElement;
            temp = nextElement;
        }
        // Pass 2: set random pointers
        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }
        // Pass 3: separate lists
        Node* dummy = new Node(0);
        Node* copyTemp = dummy;
        temp = head;
        while (temp) {
            copyTemp->next = temp->next;
            temp->next = temp->next->next;
            copyTemp = copyTemp->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
```

**Complexity:** O(n) time | O(1) space

**Simpler O(n) space alternative — HashMap:**
```cpp
Node* copyRandomList(Node* head) {
    unordered_map<Node*, Node*> mp;
    Node* temp = head;
    while (temp) { mp[temp] = new Node(temp->val); temp = temp->next; }
    temp = head;
    while (temp) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }
    return mp[head];
}
```

---

## Mistakes to Avoid

- Setting `random` before interleaving — copy nodes don't exist yet
- Not handling `temp->random == nullptr` in pass 2 — causes null dereference
- Forgetting to restore original list in pass 3

---

## Pattern

**"Interleave copies for O(1) space"** — When deep copying with cross-pointers, interleave copies to use original as a map. Classic O(1) space trick for linked list problems.

Related: LC 206 - Reverse Linked List, LC 234 - Palindrome Linked List
