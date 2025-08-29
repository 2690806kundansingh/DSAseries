#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to detect loop using Floyd’s Cycle Detection Algorithm
Node* floydDetectionLoop(Node* head) {
    if (head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while (slow != NULL && fast != NULL) {
        fast = fast->next;
        if (fast != NULL)
            fast = fast->next;

        slow = slow->next;

        if (slow == fast) {
            // Loop detected
            return slow;
        }
    }

    return NULL; // No loop
}

// Utility function to create a loop in the list for testing
void createLoop(Node* head, int position) {
    if (head == NULL || position == 0) return;

    Node* loopNode = head;
    for (int i = 1; i < position && loopNode != NULL; i++) {
        loopNode = loopNode->next;
    }

    Node* tail = head;
    while (tail->next != NULL) {
        tail = tail->next;
    }

    tail->next = loopNode; // Create loop
}

// Main function
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create a loop for testing: connect last node to node 2
    createLoop(head, 2);

    Node* intersection = floydDetectionLoop(head);

    if (intersection != NULL) {
        cout << "Loop detected at node with value: " << intersection->data << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    return 0;
}
