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
};

class Solution {
public:
    void flattent(Node* root) {
        Node* curr = root;
        while (curr != NULL) {
            if (curr->left) {
                Node* pred = curr->left;
                while (pred->right)
                    pred = pred->right;

                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};

// Helper function to print the flattened tree
void printRightSkewed(Node* root) {
    Node* curr = root;
    while (curr) {
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

int main() {
    // Create sample binary tree:
    //        1
    //      /   \
    //     2     5
    //    / \     \
    //   3   4     6

    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right = new Node(5);
    root->right->right = new Node(6);

    Solution sol;
    sol.flattent(root);

    cout << "Flattened Tree (Right Skewed): ";
    printRightSkewed(root);

    return 0;
}
