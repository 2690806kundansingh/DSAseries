
//  //accepted on leetcode
//  class Solution {
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         if (root == nullptr)
//             return nullptr;
//         if (root == p || root == q)
//             return root;
        
//         TreeNode* leftAns = lowestCommonAncestor(root->left, p, q);
//         TreeNode* rightAns = lowestCommonAncestor(root->right, p, q);

//         if (leftAns != nullptr && rightAns != nullptr)
//             return root;
//         else if (leftAns != nullptr)
//             return leftAns;
//         else
//             return rightAns;
//     }
// };


#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int data){
        this->data = data;
        this->left= NULL;
        this->right = NULL;
    }
};

class Solution{
    public:
    //function to return the lowest common ancester
    Node*LCA(Node*root,int n1,int n2){
        //base case
        if(root == NULL){
            return NULL;
        }
        if(root->data == n1 || root->data == n2){
            return root;
        }
        Node*leftAns = LCA(root->left,n1,n2);
        Node*rightAns = LCA(root->right,n1,n2);

        if(leftAns != NULL && rightAns != NULL){
            return root;
        }
        else if(leftAns != NULL && rightAns == NULL){
            return leftAns;
        }
        else if(leftAns == NULL && rightAns != NULL){
            return rightAns;
        }
        else{
            return NULL;
        }
    }
};
