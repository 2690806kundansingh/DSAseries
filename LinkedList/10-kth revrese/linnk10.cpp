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

// Function to reverse in k groups
Node* kReverse(Node* head, int k) {
    // Base case
    if (head == NULL) {
        return NULL;
    }

    // Step 1: Reverse first k nodes
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;
    int cnt = 0;

    while (curr != NULL && cnt < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    // Step 2: Recursively reverse the remaining list
    if (next != NULL) {
        head->next = kReverse(next, k);
    }

    // Step 3: Return new head of reversed list
    return prev;
}

// Function to insert at tail
void insertAtTail(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL;

    // Creating linked list: 10 -> 20 -> 30 -> 40 -> 50 -> 60
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);

    cout << "Original List: ";
    printList(head);

    int k = 3;
    head = kReverse(head, k);

    cout << "Reversed in groups of " << k << ": ";
    printList(head);

    return 0;
}
