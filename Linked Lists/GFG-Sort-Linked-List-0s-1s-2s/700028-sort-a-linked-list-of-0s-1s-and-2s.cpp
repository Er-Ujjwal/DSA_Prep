/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        if (!head || !head->next) return head;
        Node* zeroHead = new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);
        
        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        Node* temp = head;
        while (temp){
            if (temp->data == 0){
                zero->next = temp;
                zero = temp;
            }
            else if (temp->data == 1){
                one->next = temp;
                one = temp;
            }
            else{
                two->next = temp;
                two = temp;
            }
            temp = temp->next;
        }
        zero->next = oneHead->next ? oneHead->next : twoHead->next;
        one->next = twoHead->next;
        two->next = nullptr;
        Node* newHead = zeroHead->next;
        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna