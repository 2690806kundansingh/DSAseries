#include<iostream>
using namespace std;

class Solution {
public:
    int findPosition(int in[], int element, int n) {
        for (int i = 0; i < n; i++) {
            if (in[i] == element)
                return i;
        }
        return -1;
    }

    Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int n) {
        // Base case
        if (index >= n || inorderStart > inorderEnd) {
            return NULL;
        }
        // Take current element from preorder and create a new node
        int element = pre[index++];
        Node* root = new Node(element);

        // Find position of this element in inorder array
        int position = findPosition(in, element, n);

        // Recursive calls for left and right subtrees
        root->left = solve(in, pre, index, inorderStart, position - 1, n);
        root->right = solve(in, pre, index, position + 1, inorderEnd, n);

        return root;
    }

    Node* buildTree(int in[], int pre[], int n) {
        int preOrderIndex = 0;
        return solve(in, pre, preOrderIndex, 0, n - 1, n);
    }
};