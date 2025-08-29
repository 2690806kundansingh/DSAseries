#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    //constrauctor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertathead(Node* &head,int data){
    //crate a node
    Node*temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertatTail(Node* &tail,int data){
    //new node create
    Node*temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
}

void print(Node* &head){
    Node*temp = head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertAtPosition( Node* &tail,Node* &head,int position,int data){
    //transe where we want to add
    //if user want to insert at 1 postion
    if(position == 1){
        insertathead(head,data);
        return;
    }

    Node*temp = head;
    int cnt = 1;

    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    //to insert at the last position
    if(temp->next == NULL){
        insertatTail(tail,data);
        return;
    }
    //creating a node
    Node*nodetoinsert = new Node(data);

    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
int main(){
    Node*node1 = new Node(10);

    Node*head = node1;
    Node*tail = node1;
    print(head);

    insertatTail(tail,12);
    print(head);

    insertatTail(tail,15);
    print(head);

    insertAtPosition(tail,head,4,22);
    print(head);

    cout<<"hrad" <<" "<<head->data << endl;
    cout<<"tail" <<" "<<tail->data << endl;
    return 0;
}


// #include<iostream>
// using namespace std;

// class Node {
//     public:
//     int data;
//     Node* next;

//     // Constructor
//     Node(int data) {
//         this->data = data;
//         this->next = NULL;
//     }
// };

// void insertathead(Node* &head, int data) {
//     // Create a new node
//     Node* temp = new Node(data);
//     temp->next = head;
//     head = temp;
// }

// void insertatTail(Node* &tail, int data) {
//     // Create a new node
//     Node* temp = new Node(data);
//     tail->next = temp;
//     tail = tail->next;
// }

// void print(Node* &head) {
//     Node* temp = head;
//     while(temp != NULL) {
//         cout << temp->data << " ";
//         temp = temp->next;
//     }
//     cout << endl;
// }

// void insertAtPosition(Node* &head, Node* &tail, int position, int data) {
//     // If user wants to insert at position 1
//     if(position == 1) {
//         insertathead(head, data);
//         return;
//     }

//     Node* temp = head;
//     int cnt = 1;

//     // Traverse to the position where we want to insert
//     while(cnt < position - 1) {
//         temp = temp->next;
//         cnt++;
//     }

//     // Insert at the last position
//     if(temp->next == NULL) {
//         insertatTail(tail, data);
//         return;
//     }

//     // Create a new node to insert
//     Node* nodetoinsert = new Node(data);
//     nodetoinsert->next = temp->next;
//     temp->next = nodetoinsert;
// }

// int main() {
//     Node* node1 = new Node(10);

//     Node* head = node1;
//     Node* tail = node1;
//     print(head);

//     insertatTail(tail, 12);
//     print(head);

//     insertatTail(tail, 15);
//     print(head);

//     insertAtPosition(head, tail, 4, 22); // pass both head and tail
//     print(head);

//     return 0;
// }
