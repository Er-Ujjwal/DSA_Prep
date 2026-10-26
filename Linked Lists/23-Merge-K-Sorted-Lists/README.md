# 23. Merge K Sorted Lists

**Difficulty:** Hard  
**Topics:** Linked Lists, Heaps, Divide & Conquer  
**LeetCode:** [Link](https://leetcode.com/problems/merge-k-sorted-lists/)

---

## Problem Statement

Merge k sorted linked lists into one sorted linked list.

**Example:**
```
Input:  [[1->4->5],[1->3->4],[2->6]]
Output: 1->1->2->3->4->4->5->6
```

---

## Intuition & Approach

**Min-Heap (Priority Queue) approach:**

Push the head of each list into a min-heap. Always extract the smallest node, add to result, and push that node's next into the heap.

**Why min-heap?** At any point we need the global minimum across k list heads — heap gives this in O(log k).

**Dry run with `[[1->4->5],[1->3->4],[2->6]]`:**
```
Initial heap: {(1,list1),(1,list2),(2,list3)}

Pop (1,list1): result->1, push (4,list1->next)
Heap: {(1,list2),(2,list3),(4,list1)}

Pop (1,list2): result->1->1, push (3,list2->next)
Heap: {(2,list3),(3,list2),(4,list1)}

Pop (2,list3): result->1->1->2, push (6,list3->next)
...continues until heap empty

Final: 1->1->2->3->4->4->5->6 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,ListNode*>,
                       vector<pair<int,ListNode*>>,
                       greater<pair<int,ListNode*>>> pq;
        for (int i = 0; i < lists.size(); i++)
            if (lists[i]) pq.push({lists[i]->val, lists[i]});
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        while (!pq.empty()) {
            auto it = pq.top(); pq.pop();
            if (it.second->next)
                pq.push({it.second->next->val, it.second->next});
            temp->next = it.second;
            temp = temp->next;
        }
        ListNode* ans = dummy->next;
        delete dummy;
        return ans;
    }
};
```

**Complexity:** O(n log k) time | O(k) space — n = total nodes, k = number of lists

---

## Mistakes to Avoid

- Pushing null pointers into heap — check `if(lists[i])` before pushing
- Using `greater<>` without pair — need `pair<int,ListNode*>` so heap orders by value, not pointer
- Not deleting dummy node — minor memory leak

---

## Pattern

**"Min-heap for k-way merge"** — When merging k sorted sequences, use a min-heap of size k. Always extract global minimum, push successor. O(n log k) instead of O(nk).

Same pattern: external sort, merge k sorted files, LC 378 - Kth Smallest in Sorted Matrix.
