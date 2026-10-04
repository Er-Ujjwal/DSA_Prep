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
    ListNode* getKthNode(ListNode* temp, int k){
        k--;
        while (temp && k > 0){
            k--;
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseLinkedList(ListNode* head){
        ListNode* prev = NULL;
        ListNode* temp = head;
        while (temp){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* prevLast = NULL;
        while (temp){
            ListNode* KthNode = getKthNode(temp, k);
            if (KthNode == NULL){
                if (prevLast) prevLast->next = temp;
                break;
            }
            ListNode* nextNode = KthNode->next;
            KthNode->next = NULL;
            reverseLinkedList(temp);
            if (temp == head) head = KthNode;
            else prevLast->next = KthNode;
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna