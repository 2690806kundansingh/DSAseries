// //sum of nodes on the longest path from root to leaf
// #include<iostream>
// using namespace std;

// class Solution{
//     public:

//     void solve(Node*root,int sum,int &maxsum,int len,int &maxlen){
//     //base case
//     if(root == NULL){
//         if(len > maxlen){
//             maxlen = len;
//             maxsum = sum;
//         }
//         else if(len == maxlen){
//             maxsum = max(sum,maxsum)
//         }
//         return;
//     }
//     sum = sum + root->data;
//     solve(root->left,sum,maxsum,len+1 maxlen);
//     solve(root->right,sum,maxsum,len,maxlen);
    
// }

// int sumOflongetleafNode(Node*root){
//     int len = 0;
//     int maxlen = 0;
//     int sum = 0;
//     int maxsum = INT_MAX;

//     solve(root,sum,maxsum,len,maxlen);
//     return maxsum;
// }

// };


#include<iostream>
#include<Maths>
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

    void solve(Node*root,int sum,int &maxSum,int len,int &maxlen){
        //base cacse
        if(root == NULL){
            if(len > maxlen){
               maxlen = len;
               maxSum = sum;
            } 
            else if(len == maxlen){
                maxSum = max(sum,maxSum);
            }
            return;

        }
        sum  = sum + root->data;

        solve(root->left,sum,maxSum,len+1,maxlen);
        solve(root->right,sum,maxSum,len+1, maxlen);
    }

    int SumOfLongestRootToLeaf(Node*roo){
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxSum = INT_MIN;
    solve(root,sum,maxSum,len,maxlen);
    return maxSum;
   }

};  // TC -> O(n)
    // SC -> O(H)