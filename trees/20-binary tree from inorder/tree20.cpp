// #include<bits/stdc++.h>
// using namespace std;

// void creatmapping(int in[],map<int,int>&NodeToIndex,int n){
//     for(int i =0; i<n ;i++){
//         NodeToIndex[in[i]] = i;
//     }
// }
// Node*solve(int in[],int post[],int &index,int inoderStart,int iorderEnd,int n,map<int,int>&nodeToIndex){
//     //base case
//     if(index<0 || inoderStart > iorderEnd){
//         return NULL;
//     }
//     //create a root node for element
//     int element = post[index--];
//     Node*root = new Node(element);

//     //find element index in oreder
//     int position = nodeToIndex[element];

//     //recursive call
//     root->right = solve(in,post,index,inoderStart,position -1,n,nodeToIndex);
//     root->left = solve(in,post,index,inoderStart,position -1,n,nodeToIndex);

//     return root;
// }
// class Solution{
//     public:
//     Node*buildTree(int in[],int post[],int n){
//         int postorderIndex = n-1;
//         map<int,int>nodeToIndex;
//         //createmapping
//         createmapping(in,nodeToIndex,n);
//         Node*ans = solve(in,post,postorderIndex,0,n-1,n,nodeToIndex);
//         return ans;
//     }
// };



#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Definition of a Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
public:
    // Function to create a mapping of node values to their indices in the inorder traversal.
    void createMapping(vector<int>& inorder, map<int, int>& nodeToIndex) {
        for (int i = 0; i < inorder.size(); i++) {
            nodeToIndex[inorder[i]] = i;
        }
    }

    // Helper function to build the tree recursively.
    Node* solve(vector<int>& inorder, vector<int>& postorder, int& index, 
                int inorderStart, int inorderEnd, map<int, int>& nodeToIndex) {
        // Base case: If no elements are left to construct the tree.
        if (index < 0 || inorderStart > inorderEnd) {
            return nullptr;
        }

        // Create a root node with the current postorder element.
        int element = postorder[index--];
        Node* root = new Node(element);

        // Find the index of the element in the inorder traversal.
        int position = nodeToIndex[element];

        // Recursive calls to build the right and left subtrees.
        root->right = solve(inorder, postorder, index, position + 1, inorderEnd, nodeToIndex);
        root->left = solve(inorder, postorder, index, inorderStart, position - 1, nodeToIndex);

        return root;
    }

    // Function to build the binary tree from inorder and postorder traversals.
    Node* buildTree(vector<int>& inorder, vector<int>& postorder, int n) {
        int postorderIndex = n - 1; // Start from the last element of postorder traversal
        map<int, int> nodeToIndex;  // Map to store the indices of elements in inorder traversal

        // Create the mapping of node values to indices.
        createMapping(inorder, nodeToIndex);

        // Build the tree and return the root node.
        return solve(inorder, postorder, postorderIndex, 0, n - 1, nodeToIndex);
    }
};

// Function to print the preorder traversal of the tree.
void preorderTraversal(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Driver code
int main() {
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    vector<int> inorder(n), postorder(n);
    cout << "Enter inorder traversal: ";
    for (int i = 0; i < n; i++) cin >> inorder[i];

    cout << "Enter postorder traversal: ";
    for (int i = 0; i < n; i++) cin >> postorder[i];

    Solution obj;
    // Pass the correct number of arguments
    Node* root = obj.buildTree(inorder, postorder, n);

    cout << "Preorder traversal of the constructed tree: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
