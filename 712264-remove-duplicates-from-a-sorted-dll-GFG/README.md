# [Remove duplicates from a sorted DLL](https://www.geeksforgeeks.org/problems/remove-duplicates-from-a-sorted-doubly-linked-list/1)
## Easy
Given a doubly&nbsp;linked list of n nodes sorted by values, remove duplicate nodes present in the linked list.
Examples:
Input: head: 1&lt;-&gt;1&lt;-&gt;1&lt;-&gt;2&lt;-&gt;3&lt;-&gt;4
Output: 1&lt;-&gt;2&lt;-&gt;3&lt;-&gt;4
Explanation: Only the first occurance of node with value 1 is retained along with other distinct values. 
Input: head: 1&lt;-&gt;2&lt;-&gt;2&lt;-&gt;3&lt;-&gt;3&lt;-&gt;4&lt;-&gt;4
Output: 1&lt;-&gt;2&lt;-&gt;3&lt;-&gt;4
Explanation:
Only the first occurance of nodes with values 2, 3 and 4 are retained, rest repeating nodes are deleted.
Constraint:1 ≤ n ≤ 105