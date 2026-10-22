/*Structure of the doubly linked list  Node 
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = nullptr;
        prev = nullptr;
    }
};*/

class Solution {
  public:
    Node* deleteAllOccurOfX(Node* head, int x) {
        Node* temp = head;
        while (temp){
            if (temp->data == x){
                if (temp == head) head = head->next;
                Node* nextNode = temp->next;
                Node* prevNode = temp->prev;
                if (nextNode) nextNode->prev = prevNode;
                if (prevNode) prevNode->next = nextNode;
                free(temp);
                temp = nextNode;
            }
            else temp = temp->next;
        }
        return head;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna