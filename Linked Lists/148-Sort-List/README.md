# 148. Sort List

**Difficulty:** Medium  
**Topics:** Linked Lists, Sorting, Divide & Conquer  
**LeetCode:** [Link](https://leetcode.com/problems/sort-list/)

---

## Problem Statement

Sort a linked list in O(n log n) time and O(1) space.

**Example:**
```
Input:  4->2->1->3
Output: 1->2->3->4
```

---

## Intuition & Approach

**Approach used — Extract, sort, reassign (O(n log n) time, O(n) space):**
1. Extract all values to a vector
2. Sort the vector
3. Reassign values back to list nodes in order

Simple and effective, though uses O(n) extra space.

**Optimal — Merge Sort on linked list (O(n log n), O(log n) space):**
1. Find middle using slow/fast pointers
2. Split into two halves
3. Recursively sort each half
4. Merge the two sorted halves

**Dry run with `4->2->1->3`:**
```
Extract: [4,2,1,3]
Sort:    [1,2,3,4]
Reassign: 1->2->3->4 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        vector<int> list;
        ListNode* temp = head;
        while (temp) { list.push_back(temp->val); temp = temp->next; }
        sort(list.begin(), list.end());
        temp = head;
        for (int i = 0; i < list.size() && temp; i++) {
            temp->val = list[i];
            temp = temp->next;
        }
        return head;
    }
};
```

**Complexity:** O(n log n) time | O(n) space

---

## Mistakes to Avoid

- Modifying `next` pointers instead of values — easiest approach reassigns values only
- Not handling empty or single node — return early

---

## Pattern

**"Extract → sort → reassign"** — When in-place linked list sorting is complex, extract to array, sort, put back. Trade space for simplicity.

For O(1) space: use bottom-up merge sort on the list itself.
