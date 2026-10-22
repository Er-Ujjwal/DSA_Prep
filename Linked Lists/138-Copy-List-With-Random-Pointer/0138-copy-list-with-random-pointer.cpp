/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Inserting copy nodes in-between :-
        Node* temp = head;
        while (temp){
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->val);
            copy->next = nextElement;
            temp->next = copy;
            temp = nextElement;
        }
        //Connecting Random pointers :-
        temp = head;
        while (temp){
            Node* copyNode = temp->next;
            if (temp->random) copyNode->random = temp->random->next;
            else copyNode->random = nullptr;
            temp = temp->next->next;
        }
        //Connecting Next pointers :-
        temp = head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;
        while (temp){
            // Connecting new list :-
            res->next = temp->next;
            res = res->next;
            // Disconnecting & going back to initial state of L.L. :-
            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummyNode->next;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna