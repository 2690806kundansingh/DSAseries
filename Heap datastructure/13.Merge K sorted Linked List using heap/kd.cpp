#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution{
    public:

    class Compare{
        public:
        bool operator()(Node*a, Node*b){
            return a->data > b->data;
            // a and b ka order sahi hai
            //heap me reverse ki tarah kam karta hai
        }
    };
    //function to merge k sorted linked list
    Node*mergeKList(Node*arr[],int k){
        //creating min priority queue
        priority_queue<Node*,vector<Node*>,Compare >p(arr,arr+k);

        Node*root = new Node();
        Node*tail = root;

        Node*temp;
        while(!p.empty()){
            temp = p.top();
            p.pop();
            tail->next = temp;
            tail = tail->next;

            //check karenge jo bahar nikla hai uska next hai ki nahi
            if(temp -> next)
                p.push(temp->next);
        }

        return root->next;
    }
};