//find the circularity of Linklist
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//function to find circularity
bool isCircularlist(Node*head){
    //emptylist
    if(head == NULL){
        return true;
    }
    Node*temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }
    //non circular
    if(temp == NULL){
        return true;
    }
    return false;
}
int main() {
    // Create a linear linked list: 1 -> 2 -> 3 -> 4 -> 5 -> NULL
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);
    head1->next->next->next = new Node(4);
    head1->next->next->next->next = new Node(5);

    // Check circularity
    if (isCircularlist(head1)) {
        cout << "List 1 is circular." << endl;
    } else {
        cout << "List 1 is not circular." << endl;
    }

    // Create a circular linked list: 10 -> 20 -> 30 -> back to 10
    Node* head2 = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    head2->next = second;
    second->next = third;
    third->next = head2; // Creates a circular link

    // Check circularity
    if (isCircularlist(head2)) {
        cout << "List 2 is circular." << endl;
    } else {
        cout << "List 2 is not circular." << endl;
    }

    return 0;
}


