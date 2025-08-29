// #include<iostream>
// #include<vector>
// using namespace std;

// class Solution{
//     public:

//     void solve(Node*root,int k,int &count,vector<int>&path){
//         //base case
//         if(root == NULL)
//            return;

//         path.push_back(root);

//         //left
//         solve(root->left,k,count,path);
//         //right
//         solve(root->right,k,count,path);

//         //check for k sum
//         int size = path.size();
//         int sum = 0;

//         for(int i = size-1; i>=0 ; i--){
//             sum = sum + path[i];
//             if(sum == 0)
//               count++;
//         }
//         path.pop_back();   
//     }

//     int sum(Node*root,int k){
//         vector<int>path;
//         int count =0;
//         solve(root,k,count,path);
//         return count;
//     }
// };

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

void solve(Node*root,int k,int &count,vector<int>&path){
    //base case
    if(root == NULL)
       return;
    path.push_back(root->data);  
    
    //left
    solve(root->left,k , count,path);
    //right
    solve(root->right,k,count,path);

    //check fro sum
    int size = path.size();
    int sum = 0;
    for(int i = size-1; i>=0; i--){
        sum += path[i];

        if(sum == k)
          count++;
    }
    path.pop_back();
}

int sum(Node*root,int k){
    vector<int>path;
    int count = 0;
    solve(root,k,count,path);
    return count;
}