#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Helper function to merge two sorted lists
Node* solve(Node* first, Node* second) {
    Node* curr1 = first;
    Node* next1 = curr1->next;
    Node* curr2 = second;
    Node* next2;

    while (next1 != NULL && curr2 != NULL) {
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;

            // update pointers
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            // move curr1 and next1 forward
            curr1 = next1;
            next1 = next1->next;

            if (next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }
    return first;
}

// Main merge function
Node* sortTwoList(Node* first, Node* second) {
    if (first == NULL)
        return second;
    if (second == NULL)
        return first;

    if (first->data <= second->data)
        return solve(first, second);
    else
        return solve(second, first);
}

// Utility function to insert node at the end
void insertAtTail(Node* &head, int data) {
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Utility function to print the linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// MAIN FUNCTION
int main() {
    Node* first = NULL;
    Node* second = NULL;

    // First sorted list: 1 -> 3 -> 5
    insertAtTail(first, 1);
    insertAtTail(first, 3);
    insertAtTail(first, 5);

    // Second sorted list: 2 -> 4 -> 6
    insertAtTail(second, 2);
    insertAtTail(second, 4);
    insertAtTail(second, 6);

    cout << "First List: ";
    printList(first);
    cout << "Second List: ";
    printList(second);

    Node* merged = sortTwoList(first, second);

    cout << "Merged Sorted List: ";
    printList(merged);

    return 0;
}
