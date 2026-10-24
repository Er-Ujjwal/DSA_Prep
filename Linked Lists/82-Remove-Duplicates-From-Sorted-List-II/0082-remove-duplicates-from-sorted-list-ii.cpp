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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1);
        dummyNode->next = head;
        ListNode* prev = dummyNode;
        ListNode* temp = head;
        while (temp){
            if (temp->next && temp->val == temp->next->val){
                int duplicate = temp->val;
                while (temp && temp->val == duplicate){
                    temp = temp->next;
                }
                prev->next = temp;
            }
            else {
                prev = temp;
                temp = temp->next;
            }
        }
        return dummyNode->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna