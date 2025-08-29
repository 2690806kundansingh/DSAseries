// #include<iostream>
// using namespace std;

// class Node{
//     int data;
//     Node*left;
//     Node*right;

//     //constructor
//     Node(int data){
//         this->data = data;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// class Solution{
//     public:
//     bool isBalance(Node*&root){
//         if(root == NULL){
//             return true;
//         }
//         bool left = isBalance(root->left); 
//         bool right = isBalance(root->right);
//         bool diff = abs(height(root->left) - height(root->right)) <= 1;

//         if(left && right && diff){
//             return 1;
//         }
//         else{
//             return false;
//         }
//     }
// };   // o(n2)

//optimise version


#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node*left;
    struct Node*right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    pair<bool,int>isBalancedFast(Node*root){
        //base case
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }

        pair<int,int>left = isBalancedFast(root->left);
        pair<int,int>right = isBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;

        bool diff = abs(left.second - right.second) <= 1;

        pair<bool,int>ans;
        ans.second = max(left.second,right.second) + 1;

        if(leftAns && rightAns && diff){
            ans.first = true;
        }
        else{
            ans.first = false;
        }
        return ans;

    }
    bool isBalanced(Node*root){
    return isBalancedFast(root).first;
}
};
// O(n)