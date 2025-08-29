#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// also showing inorder preorder and post order
void inorder(Node*root){
    //base case
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node*root){
    //base case
    if(root == NULL){
        return ;
    }
    cout<<root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(Node*root){
    //base case
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
// for print bst use level order traversal
void levelorderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();

        if(temp == NULL){
            //pura level complete traverse ho gya hai
            cout<<endl;
            if(!q.empty()){
                //queue has some still child node
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }

}

Node*insertIntoBst(Node*root, int d){
    //base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if(d > root->data){
        //right part me insert karo
        root->right = insertIntoBst(root->right,d);
    }
    else{
        //left part me dal do
        root->left = insertIntoBst(root->left,d);
    }
    return root;
}

void takeInput(Node*&root){
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBst(root,data);
        cin >> data;
    }
}

int main(){
    //crating a node
    Node*root = NULL;

    cout<<"Enter the data to create bst "<<endl;
    takeInput(root);

    cout<<"Printing the BST"<<endl;
    levelorderTraversal(root);  
    
    cout<<"Printing inorder"<<endl;
    inorder(root);

    cout<< endl <<"Printing preorder" <<endl;
    preorder(root);

    cout<< endl <<"Printing postorder "<<endl;
    postorder(root);


    return 0;
}

