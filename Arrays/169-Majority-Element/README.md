# 169. Majority Element

**Difficulty:** Easy  
**Topics:** Arrays  
**LeetCode:** [Link](https://leetcode.com/problems/majority-element/)

---

## Problem Statement

Find the element appearing more than `n/2` times. Guaranteed to exist.

**Example:**
```
Input:  nums = [2,2,1,1,1,2,2]
Output: 2
```

---

## Intuition & Approach

**Boyer-Moore Voting Algorithm:**
Maintain a `candidate` and `count`. When count hits 0, switch candidate. When element matches candidate, increment; else decrement.

The majority element (> n/2 occurrences) always survives as the final candidate — it can never be fully cancelled out by minorities.

**Dry run with `[2,2,1,1,1,2,2]`:**
```
x=2: count=0 -> candidate=2, count=1
x=2: match  -> count=2
x=1: no match -> count=1
x=1: no match -> count=0
x=1: count=0 -> candidate=1, count=1
x=2: no match -> count=0
x=2: count=0 -> candidate=2, count=1
return 2 ✅
```

---

## My Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = 0, count = 0;
        for (int x : nums) {
            if (count == 0) candidate = x;
            if (x == candidate) count++;
            else count--;
        }
        return candidate;
    }
};
```

**Complexity:** O(n) time | O(1) space

---

## Mistakes to Avoid

- Thinking candidate needs verification — problem guarantees majority exists, so final candidate is always correct
- Using `count == 0` check after updating — must check BEFORE processing current element

---

## Pattern

**"Boyer-Moore Voting"** — Find majority element in O(n) O(1). Only works when majority is guaranteed (> n/2). For n/3 majority → LC 229.
