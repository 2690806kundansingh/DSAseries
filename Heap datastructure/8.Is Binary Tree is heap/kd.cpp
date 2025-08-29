#include<iostream>
using namespace std;

class Solution {
    public:
    
        // Function to count the total number of nodes in the binary tree
        int CountNode(struct Node* tree) {
            // Base case
            if (tree == NULL) {
                return 0;
            }
            int ans = 1 + CountNode(tree->left) + CountNode(tree->right);
            return ans;
        }
    
        // Function to check if the tree is a complete binary tree
        bool isCbt(struct Node* tree, int index, int cnt) {
            // Base case
            if (tree == NULL) {
                return true;
            }
            if (index >= cnt) {
                return false;
            }
            bool left = isCbt(tree->left, 2 * index + 1, cnt);
            bool right = isCbt(tree->right, 2 * index + 2, cnt);
    
            return (left && right);
        }
    
        // Function to check if the tree satisfies the Max-Heap property
        bool isMaxOrder(struct Node* tree) {
            // Leaf node
            if (tree->left == NULL && tree->right == NULL) {
                return true;
            }
    
            // Node with only left child
            if (tree->right == NULL) {
                return (tree->data >= tree->left->data) && isMaxOrder(tree->left);
            }
    
            // Node with two children
            bool left = isMaxOrder(tree->left);
            bool right = isMaxOrder(tree->right);
    
            return (left && right &&
                    (tree->data >= tree->left->data) &&
                    (tree->data >= tree->right->data));
        }
    
        // Main function to check if the binary tree is a Max-Heap
        bool isHeap(struct Node* tree) {
            int totalCount = CountNode(tree);
            return isCbt(tree, 0, totalCount) && isMaxOrder(tree);
        }
    };
    