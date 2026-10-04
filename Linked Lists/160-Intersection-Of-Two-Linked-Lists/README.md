# 160. Intersection of Two Linked Lists

**Difficulty:** Easy  
**Topics:** Linked Lists, Two Pointers  
**LeetCode:** [Link](https://leetcode.com/problems/intersection-of-two-linked-lists/)

---

## Problem Statement

Find the node where two linked lists intersect. Return `null` if no intersection.

**Example:**
```
A: 4->1->8->4->5
B: 5->6->1->8->4->5
Output: node with value 8
```

---

## Intuition & Approach

**Two pointer — path equalization trick:**

Move `temp1` through list A then list B. Move `temp2` through list B then list A. Both travel equal total distance `(lenA + lenB)`. If they intersect, they meet at the intersection node. If not, both reach null simultaneously.

**Why it works:**
- `temp1` travels: `lenA + lenB`
- `temp2` travels: `lenB + lenA`
- Same total distance → if intersection exists at distance `d` from end, both arrive there at the same step

**Dry run with A=4->1->8->4->5, B=5->6->1->8->4->5:**
```
temp1: 4,1,8,4,5,null->5,6,1,[8]
temp2: 5,6,1,8,4,5,null->4,1,[8]
Both meet at node 8 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while (temp1 != temp2) {
            temp1 = (temp1 == NULL) ? headB : temp1->next;
            temp2 = (temp2 == NULL) ? headA : temp2->next;
        }
        return temp1;
    }
};
```

**Complexity:** O(m+n) time | O(1) space

---

## Mistakes to Avoid

- Switching on `temp1->next == NULL` instead of `temp1 == NULL` — switches one step too early, misses last node
- Infinite loop if no intersection — if no intersection, both become null simultaneously (`temp1 == temp2 == null`) → loop exits, returns null ✅

---

## Pattern

**"Path equalization with two pointers"** — When two lists differ in length, traverse both fully by switching to the other list at end. Equal total path guarantees meeting at intersection or null. Elegant O(1) space solution.

Related: LC 141 - Linked List Cycle, LC 234 - Palindrome Linked List
