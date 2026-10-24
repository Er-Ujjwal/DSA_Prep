# Pair Sum in Sorted Doubly Linked List

**Difficulty:** Medium  
**Topics:** Linked Lists, Two Pointers  
**GFG:** [Link](https://www.geeksforgeeks.org/problems/find-pairs-with-given-sum-in-doubly-linked-list/1)

---

## Problem Statement

Given a sorted doubly linked list, find all pairs with sum equal to target.

**Example:**
```
Input:  1<->2<->4<->5<->6<->8<->9, target=7
Output: [[1,6],[2,5]]
```

---

## Intuition & Approach

**Two pointer — left from head, right from tail:**

Since DLL is sorted, use classic two-pointer approach:
- If `left->data + right->data == target` → add pair, move both
- If sum < target → move left forward
- If sum > target → move right backward

Stop when left and right cross.

**Dry run with `1<->2<->4<->5<->6<->8<->9`, target=7:**
```
left=1, right=9: 1+9=10>7 → right=8
left=1, right=8: 1+8=9>7  → right=6
left=1, right=6: 1+6=7==7 → add [1,6], left=2, right=5
left=2, right=5: 2+5=7==7 → add [2,5], left=4, right=4
left==right → stop
return [[1,6],[2,5]] ✅
```

---

## My Solution

```cpp
class Solution {
public:
    Node* findTail(Node* head) {
        Node* tail = head;
        while (tail->next) tail = tail->next;
        return tail;
    }
    vector<vector<int>> givenSumPairs(Node* head, int target) {
        vector<vector<int>> ans;
        if (!head) return ans;
        Node* left = head;
        Node* right = findTail(head);
        while (left != right && right->next != left) {
            int sum = left->data + right->data;
            if (sum == target) {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            } else if (sum < target) {
                left = left->next;
            } else {
                right = right->prev;
            }
        }
        return ans;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Stop condition: `left != right && right->next != left` — handles both odd and even length lists
- Finding tail first — DLL gives access to `prev` but not direct tail pointer

---

## Pattern

**"Two pointer on sorted DLL"** — Same as two-pointer on sorted array, but use `prev/next` instead of indices. Classic pair sum pattern.

Related: LC 167 - Two Sum II (sorted array), LC 160 - Intersection of Two Linked Lists
