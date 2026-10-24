/* Structure of a link list node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};
*/
class Solution {
  public:
    Node* removeDuplicates(Node* headRef) {
        Node* temp = headRef;
        while (temp && temp->next){
            Node* nextNode = temp->next;
            while (nextNode && nextNode->data == temp->data){
                Node* duplicate = nextNode;
                nextNode = nextNode->next;
                free(duplicate);
            }
            temp->next = nextNode;
            if (nextNode) nextNode->prev = temp;
            temp = temp->next;
        }
        return headRef;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna