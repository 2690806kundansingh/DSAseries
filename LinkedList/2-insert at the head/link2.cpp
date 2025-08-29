//insert at the haed of the node

#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    //creating contructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void insertAtHead(Node*&head,int data){
    //crate a node
    Node*temp = new Node(data);
    temp->next = head;
    head = temp;
}

 //how to traverse linklist
void print(Node*&head){
    Node*temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main(){

    Node*node1 = new Node(10);
    cout<<node1->data <<endl;
    cout<<node1 ->next <<endl;

    //head poted node 1
    Node*node = node1;
    Node*head = node1;
    print(head);

    insertAtHead(head,12);
    print(head);

    insertAtHead(head,15);
    print(head);



    return 0;

}

