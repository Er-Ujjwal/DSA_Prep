/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || !k) return head;
        ListNode* tail = head;
        int length = 1;
        while (tail->next){
            length++;
            tail = tail->next;
        }
        k = k % length;
        if (k == 0) return head;
        tail->next = head;
        ListNode* temp = head;
        for (int i=1; i<length-k; i++){
            temp = temp->next;
        }
        ListNode* newHead = temp->next;
        temp->next = NULL;
        return newHead;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna