//Find starting node of loop
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    //constructor
    Node(int data){
        this->data = data;
        this->Next = NULL;

    }
};
//find loop present or not
Node*floydDetectionLoop(Node*head){
    if(head == NULL){
        return NULL;
    }
    Node*slow = head;
    Node*fast  = head;

    while(slow != NULL && fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast)
           return slow;
    }
    return NULL;
}

//to find the starting node of Loop
Node*getStartingNode(Node*head){
    if(head == NULL){
        return NULL;
    }
    Node*instersection = floydDetectionLoop(head);
    if(instersection == NULL)
       return NULL;

    Node*slow = head;

    while(slow != instersection){
        slow = slow->next;
        instersection = instersection->next;
    } 
    return slow;  
}
