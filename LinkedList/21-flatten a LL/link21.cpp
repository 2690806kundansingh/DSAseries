#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

// Merges two sorted linked lists
Node* merge(Node* left, Node* right) {
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;

    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    while (left != NULL) {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }

    while (right != NULL) {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }

    Node* result = ans->next;
    delete ans;
    return result;
}

// Flattens a list of linked lists into a single sorted list
Node* flattenList(Node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    Node* mergeHead = flattenList(head->next);
    head = merge(head, mergeHead);

    return head;
}

// Helper function to print linked list
void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
Node* createList(int arr[], int size) {
    if (size == 0) return NULL;

    Node* head = new Node(arr[0]);
    Node* curr = head;

    for (int i = 1; i < size; i++) {
        curr->next = new Node(arr[i]);
        curr = curr->next;
    }

    return head;
}

int main() {
    int arr1[] = {1, 4, 7};
    int arr2[] = {2, 5, 8};
    int arr3[] = {3, 6, 9};

    Node* head1 = createList(arr1, 3);
    Node* head2 = createList(arr2, 3);
    Node* head3 = createList(arr3, 3);

    // Correct way: treat as separate lists, and link them via "next"
    head1->next = head2;
    head2->next = head3;

    Node* flatHead = flattenList(head1);
    cout << "Flattened Linked List: ";
    printList(flatHead);

    return 0;
}
