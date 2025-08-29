#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
}; // <- Semicolon was missing here

class Solution {
public:
    void inorder(Node* root, int &count) {
        // Base case
        if (root == NULL) {
            return;
        }

        inorder(root->left, count);

        // Leaf Node check
        if (root->left == NULL && root->right == NULL) {
            count++;
        }

        inorder(root->right, count);
    }

    int noOfLeafNodes(Node* root) {
        int cnt = 0;
        inorder(root, cnt);
        return cnt;
    }
};

int main() {
    // Constructing the following tree:
    //        1
    //       / \
    //      2   3
    //     /   / \
    //    4   5   6
    //           /
    //          7

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);
    root->right->right->left = new Node(7);

    Solution sol;
    int leafCount = sol.noOfLeafNodes(root);

    cout << "Number of leaf nodes: " << leafCount << endl;  // Output should be 4
    return 0;
}
