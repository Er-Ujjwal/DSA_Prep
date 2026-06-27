# 237. Delete Node in a Linked List

**Difficulty:** Medium  
**Topics:** Linked Lists  
**LeetCode:** [Link](https://leetcode.com/problems/delete-node-in-a-linked-list/)

---

## Problem Statement

Delete a given node from a singly linked list. You are **not given access to the head** — only the node to be deleted is provided. The node is guaranteed to not be the tail.

**Example:**
```
Input:  head = [4,5,1,9], node = 5
Output: [4,1,9]
```

---

## Intuition & Approach

**The twist:** Normally to delete a node you need the previous node to update its `next` pointer. But here you only have the node itself — no access to previous node, no access to head.

**Key Insight:** You don't need to delete *this* node — just make it look like it's gone.

Copy the next node's value into current node, then skip the next node. Effectively the current node *becomes* the next node and the next node gets deleted.

```
Before: ... -> [5] -> [1] -> [9]
Step 1: copy next val  -> [1] -> [1] -> [9]
Step 2: skip next node -> [1] -> [9]
After:  ... -> [1] -> [9]   (5 is gone)
```

---

## My Solution

```cpp
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
```

**Complexity:** O(1) time | O(1) space

---

## Mistakes to Avoid

- Trying to find previous node — impossible without head, wrong approach entirely
- Worrying about memory leak of the skipped node — not expected in LC context
- Forgetting this only works because node is guaranteed not to be tail — `node->next` is always valid

---

## Pattern

**"Copy and skip"** — When you can't reach a node from behind, overwrite it with successor's data and delete the successor instead.

This is a one-off trick, not broadly reusable — but it's a classic interview gotcha that tests whether you think outside the standard deletion approach.
