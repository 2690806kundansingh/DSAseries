// #include<iostream>
// #include<limits.h>
// using namespace std;

// class Solution{
//     public:
//     int solve(Node*root,int &k,int node){
//         //base case
//         if(root == NULL)
//            return NULL;
//         if(root->data == node)
//            return root;

//         Node*leftAns = solve(root->left,k,node);
//         Node*rightAns = solve(root->right,k,node);

//         //wapas ate samay
//         if(leftAns != NULL && rightAns == NULL){
//             k--;
//             if(k <= 0){
//                 k = INT_MAX;
//                 return root;
//             }
//             return leftAns;
//         }  
//         if(leftAns == NULL && rightAns != NULL){
//             k--;
//             if(k<=0){
//                 k = INT_MAX;
//                 return root;
//             }
//             return rightAns;
//         } 
//         return NULL;   
//     }

//     int kthAncestor(Node*root,int k,int node){
//         Node*ans = solve(root,k,node);
//         if(ans == NULL || ans->data == node)
//            return -1;
//         else 
//            return ans->data;   
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
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution{
    public:
    Node*solve(Node*root,int &k,int node){
        //base case
        if(root == NULL)
           return NULL;
        if(root->data == node) 
           return root;
           
        Node*leftAns = solve(root->left,k,node); 
        Node*rightAns = solve(root->right,k,node);
        
        //wapas
        if(leftAns != NULL && rightAns == NULL){
            k--;
            if(k <= 0){
                k = INT_MAX;
                return root;
            }
            return leftAns;
        }
        if(leftAns == NULL && rightAns != NULL){
            k--;
            if(k <= 0){
                k = INT_MAX;
                return root;
            }
            return rightAns;
        }
        return NULL;
    }

    int KthAnceshter(Node*root,int k,int node){
        Node*ans = solve(root,k,node);
        if(ans == NULL || ans->data == node)
          return -1;
        else
          return ans->data;  
    }
};