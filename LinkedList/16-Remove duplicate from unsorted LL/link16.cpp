#include<iostream>
#include<unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Function to remove duplicates from an unsorted linked list
Node* removeDuplicate(Node* head) {
    if (head == NULL) {
        return NULL;
    }

    unordered_set<int> st;
    Node* curr = head;
    st.insert(curr->data); // Insert head data

    while (curr != NULL && curr->next != NULL) {
        if (st.find(curr->next->data) != st.end()) {
            // Duplicate found, remove node
            Node* nodeToDelete = curr->next;
            curr->next = curr->next->next;
            delete nodeToDelete;
        } else {
            // Not a duplicate
            st.insert(curr->next->data);
            curr = curr->next;
        }
    }

    return head;
}

// Utility function to print the list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 20 -> 10 -> 40 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(20); // duplicate
    head->next->next->next->next = new Node(10); // duplicate
    head->next->next->next->next->next = new Node(40);

    cout << "Original List: ";
    printList(head);

    head = removeDuplicate(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}
