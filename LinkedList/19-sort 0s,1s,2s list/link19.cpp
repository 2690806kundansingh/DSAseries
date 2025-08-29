#include<iostream>
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

Node* sortList(Node* head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;

    // Count number of 0s, 1s and 2s
    while (temp != NULL) {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else if (temp->data == 2)
            twoCount++;
        temp = temp->next;
    }

    // Update the linked list with sorted values
    temp = head;
    while (temp != NULL) {
        if (zeroCount > 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if (oneCount > 0) {
            temp->data = 1;
            oneCount--;
        }
        else if (twoCount > 0) {
            temp->data = 2;
            twoCount--;
        }
        temp = temp->next;
    }

    return head;
}
void printList(Node*head){
    while(head != NULL){
        cout<<head->data<<" ->";
        head = head->next;
    }
    cout<<endl;
}

int main(){
    Node*head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(2);
    

    cout<<"Original List:";
    printList(head);

    head = sortList(head);
    cout<<"Sorted List: ";
    printList(head);

    return 0;
}