#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    //destructor
    ~Node(){
        int val = this->data;
        if(next != NULL){
            delete next;
            next = NULL;
        }
        cout<<"memoery freee for node eith data" <<" "<<val <<endl;
    }
};

// Print function (defined outside the class)
void print(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Get length of the linked list
int getLength(Node* head) {
    int len = 0;
    Node* temp = head;

    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

// Insert at head
void insertAtHead(Node*& tail, Node*& head, int d) {
    if (head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

// Insert at tail
void insertAtTail(Node*& tail, Node*& head, int d) {
    if (tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    } else {
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

// Insert a node at a specific position
void nodeAtPosition(Node*& tail, Node*& head, int position, int d) {
    if (position == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == NULL) {
        insertAtTail(tail, head, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
}

//deltion at any position
void deleteNode(int position,Node* &head){
    //delete first ant start node
    if(position == 1){
        Node*temp = head;
        temp->next->prev = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        //delete any middle and last node
        Node*curr = head;
        Node*prev = NULL;

        int cnt = 1;
        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        //memory free
        curr->prev = NULL;
        prev->next = NULL;
        curr->next = NULL;

        delete curr;
    }
}

int main() {
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;

    print(head);  // Call the print function

    insertAtHead(tail, head, 11);
    print(head);

    insertAtHead(tail, head, 13);
    print(head);

    insertAtHead(tail, head, 8);
    print(head);

    insertAtTail(tail, head, 25);
    print(head);

    nodeAtPosition(tail, head, 2, 100);
    print(head);

    deleteNode(6,head);
    print(head);



    return 0;
}


// #include<iostream>
// using namespace std;

// class Node{
//     public:
//     int data;
//     Node*prev;
//     Node*next;

//     //constructor
//     Node(int data){
//         this->data = data;
//         this->prev = NULL;
//         this->next = NULL;
//     }
// };

// //print function
// void print(Node*head){
//     Node*temp = head;
//     while(temp != NULL){
//         cout << temp ->data;
//         temp = temp ->next;
//     }
//     cout<<endl;
// }

// int getLength(Node*head){
//     int len = 0;
//     Node*temp = head;
//     while(temp != NULL){
//         len ++;
//         temp = temp->next;
//     }
//     return len;
// }
// void intsertAtHead(Node*&head,int data){
//     Node*temp = new Node(data);
//     temp->next = head;
//     head->prev = temp;
//     head = temp;
// }
// int main(){
//     Node*node1 = new Node(20);

//     Node*head = node1;
//     print(head);
//     cout<< getLength(head);
//     print(head);

//     // intsertAtHead(head,30);
//     // print(head);
//     return 0;
// }