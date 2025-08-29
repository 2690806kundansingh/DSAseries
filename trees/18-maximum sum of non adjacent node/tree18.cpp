
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

    //function to return the maximum sum of non adjacent node
    pair<int,int>solve(Node*root){
        //base case
        if(root == nullptr){
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        pair<int,int>left = solve(root->left);
        pair<int,int>right = solve(root->right);

        pair<int,int>res;
        //include
        res.first = root->data + left.second + right.second;
        //exclude
        res.second = max(left.first,left.second)+max(right.first,right.second);

        return res;
    }
    
    int getMaxSum(Node*root){
        pair<int,int>ans = solve(root);
        return max(ans.first,ans.second);
    }
};