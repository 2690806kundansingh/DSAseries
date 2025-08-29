#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* floydDetectionLoop(Node* head){
    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;

        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

// To find the starting node of loop
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = floydDetectionLoop(head);
    if(intersection == NULL)
        return NULL;

    Node* slow = head;

    while(slow != intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// To remove loop
Node* removeLoop(Node* head){
    if(head == NULL){
        return NULL;
    }

    Node* startOfLoop = getStartingNode(head);
    if(startOfLoop == NULL)
        return head;

    Node* temp = startOfLoop;
    while(temp->next != startOfLoop){
        temp = temp->next;
    }
    temp->next = NULL;

    return head;
}

// Utility function to print the linked list
void printList(Node* head){
    while(head != NULL){
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Utility function to create a loop in the list for testing
void createLoop(Node* head, int pos){
    if(pos == 0) return;

    Node* loopNode = head;
    for(int i = 1; i < pos && loopNode != NULL; i++){
        loopNode = loopNode->next;
    }

    Node* tail = head;
    while(tail->next != NULL){
        tail = tail->next;
    }

    tail->next = loopNode;
}

int main(){
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create loop: connect node 5 to node 2 (position = 2)
    createLoop(head, 2);

    // Detect loop
    if(floydDetectionLoop(head) != NULL){
        cout << "Loop detected!" << endl;
    } else {
        cout << "No loop detected." << endl;
    }

    // Remove loop
    head = removeLoop(head);

    // Check again
    if(floydDetectionLoop(head) == NULL){
        cout << "Loop removed successfully!" << endl;
    } else {
        cout << "Loop still exists!" << endl;
    }

    // Print the list after removing loop
    cout << "Linked List after removing loop: ";
    printList(head);

    return 0;
}
