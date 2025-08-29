// right view

#include<iostream>
#include<vector>
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

class Solution{
    public:
    void solve(Node*root,vector<int>&ans,int level){
        //base case
        if(root == NULL)
           return;
        //we enter into new level
        if(level == ans.size()){
            ans.push_back(root->data);
        } 
        solve(root->right,ans,level+1);  
        solve(root->left,ans,level+1);
    }
    vector<int>rightView(Node*root){
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int>result = sol.rightView(root);

    //printing result
    for(int val:result){
        cout<<val <<" ";
    }
    cout<<endl;
    return 0;

}

// We use preorder traversal (root → left → right).

// We keep track of the level we are currently at.

// If level == ans.size(), it means this is the first node of this level — so it belongs to the left view.

// We recursively visit left subtree first, then the right subtree, ensuring the leftmost node at each level is chosen.