//creatinon /buil->binary tree
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node*left;
    Node*right;

    //constructor
    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node*buildtree(Node*root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the data for inserting left"<<endl;
    root->left = buildtree(root->left);

    cout<<"Enter the data for insserting in right"<<endl;
    root->right = buildtree(root->right);

    return root;
}

int main(){
    Node*root = NULL;
    //creating a tre
    root = buildtree(root);
    return 0;
}

