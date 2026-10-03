/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int countSize(ListNode* head){
        int count = 0;
        ListNode* temp = head;
        while (temp){
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* collidePoint(ListNode* t1, ListNode* t2, int d){
        while (d){
            d--;
            t2 = t2->next;
        }
        while (t1 != t2){
            t1 = t1->next;
            t2 = t2->next;
        }
        return t1;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int countA = countSize(headA);
        int countB = countSize(headB);
        if (countA > countB) return collidePoint(headB, headA, countA-countB);
        else return collidePoint(headA, headB, countB-countA);
        return NULL;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna