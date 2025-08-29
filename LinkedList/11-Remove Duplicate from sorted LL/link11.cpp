#include<iostream>
using namespace std;

// Node class definition
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

// Function to remove duplicates from a sorted linked list
Node* removeDuplicate(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    Node* curr = head;
    while (curr->next != NULL) {
        if (curr->data == curr->next->data) {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete nodeToDelete;
            curr->next = next_next;
        } else {
            curr = curr->next;
        }
    }

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Creating a sorted linked list with duplicates
    Node* head = new Node(23);
    head->next = new Node(24);
    head->next->next = new Node(45);
    head->next->next->next = new Node(45); // duplicate
    head->next->next->next->next = new Node(46);
    head->next->next->next->next->next = new Node(46); // duplicate

    cout << "Original list: ";
    printList(head);

    head = removeDuplicate(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
