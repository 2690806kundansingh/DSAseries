//level order traversal BFS

#include<iostream>
#include<queue>
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
void Levelordertraversal(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);//separation

    while(!q.empty()){
        Node*temp = q.front();
        
        q.pop();

        if(temp == NULL){//pura level traverse ho chuka hai
            cout<<endl;
            if(!q.empty()){//queue still has some child node
                q.push(NULL);//separation
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
//function inorder LNR
void inorder(Node*root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//function preordered NLR
void preordered(Node*root){
    if(root == NULL){
         return;
    }
    cout<<root->data <<" ";
    preordered(root->left);
    preordered(root->right);
}

//function postordred LRN
void postordered(Node*root){
    if(root == NULL){
        return;
    }
    postordered(root->left);
    postordered(root->right);
    cout<<root->data <<" ";
    
}

int main(){
    Node*root = NULL;
    //creating a tre
    root = buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"printing the level"<<endl;
    Levelordertraversal(root);//1 3 7 -1 5 17 -1 -1 -1 -1 -1

    cout<<"inordered traversal is :" <<endl;
    inorder(root);

    cout<<"preoredered traversal is :"<<endl;
    preordered(root);

    cout<<"postordere traversal is"<<endl;
    postordered(root);

    return 0;
}


//leetcode
// class Solution {
//     private:
//     void inorder(TreeNode*root,vector<int>&result){
//         //base case
//         if(root == nullptr)
//            return ;
//         inorder(root->left,result);
//         result.push_back(root->val);
//         inorder(root->right,result);   
//     }
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         vector<int>result;
//         inorder(root,result);
//         return result;
//     }
// };

