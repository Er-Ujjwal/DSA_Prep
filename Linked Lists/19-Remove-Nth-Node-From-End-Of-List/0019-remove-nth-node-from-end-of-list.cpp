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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head) return head;
        if (!head->next) return {};
        ListNode* temp = head;
        int count = 0;
        while (temp){
            count ++;
            temp = temp->next;
        }
        if (n==count) return head->next;
        temp = head;
        for (int i=1; i<count-n; i++){
            temp = temp->next;
        }
        ListNode* delNode = temp->next; 
        temp->next = temp->next->next;
        delete delNode;
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna