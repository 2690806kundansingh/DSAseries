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
int main(){
    Node*node1 = new Node(10);

    Node*head = node1;
    Node*tail = node1;
    print(head);

    insertatTail(tail,12);
    print(head);

    insertatTail(tail,15);
    print(head);
    return 0;
}