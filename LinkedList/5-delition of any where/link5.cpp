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
    //destructor
    ~Node(){
        int value = this->data;
        //memory free
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for node with data"<<value<<endl;
    }
};

//deletion of node
void deleteNode(int position,Node* &head){
    //delete first node and start  node
    if(position == 1){
        Node*temp = head;
        head = head->next;

        //memory free start node
        temp->next = NULL;
        delete temp;
    }
    else{
        //delete any middle and last node
        Node*curr = head;
        Node* prev = NULL;

        int cnt = 1;

        while(cnt < position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

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

    deleteNode(1,head);
    print(head);
    return 0;
}


