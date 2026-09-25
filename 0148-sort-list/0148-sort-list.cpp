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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        vector<int> list;
        ListNode* temp = head; 
        while (temp){
            list.push_back(temp->val);
            temp = temp->next;
        }
        sort(list.begin(), list.end());
        temp = head;
        for (int i=0; i<list.size(), temp != NULL; i++){
            temp->val = list[i];
            temp = temp->next;
        } 
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna