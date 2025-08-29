//clone a linked list with randome variable
#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

class Solution {
public:
    void insertAtTail(Node*& head, Node*& tail, int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    Node* copyList(Node* head) {
        // Step 1: Create a clone list (just using next pointers)
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        // Step 2: Create a mapping from original to clone nodes
        unordered_map<Node*, Node*> oldToNew;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;

        while (originalNode != NULL && cloneNode != NULL) {
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // Step 3: Assign random pointers using the map
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL) {
            if (originalNode->random != NULL)
                cloneNode->random = oldToNew[originalNode->random];
            else
                cloneNode->random = NULL;

            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        return cloneHead;
    }
};
int main() {
    // Create original linked list manually
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    // Setting next pointers
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Setting random pointers
    head->random = third;     // 1 -> 3
    second->random = head;    // 2 -> 1
    third->random = fourth;   // 3 -> 4
    fourth->random = second;  // 4 -> 2

    // Create a solution object
    Solution s;

    // Clone the list
    Node* clonedHead = s.copyList(head);

    // Print original list
    cout << "Original List:" << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << "Node data: " << temp->data;
        if (temp->random)
            cout << ", Random points to: " << temp->random->data << endl;
        else
            cout << ", Random points to: NULL" << endl;
        temp = temp->next;
    }

    // Print cloned list
    cout << "\nCloned List:" << endl;
    temp = clonedHead;
    while (temp != NULL) {
        cout << "Node data: " << temp->data;
        if (temp->random)
            cout << ", Random points to: " << temp->random->data << endl;
        else
            cout << ", Random points to: NULL" << endl;
        temp = temp->next;
    }

    return 0;
}
