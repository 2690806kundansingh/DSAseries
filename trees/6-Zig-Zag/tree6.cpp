#include<iostream>
#include<queue>
#include<vector>
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
    vector<int> ZigZag(Node* root) {
        vector<int> result;
        if (root == NULL) {
            return result;
        }

        queue<Node*> q;
        q.push(root);
        bool leftToRight = true;

        while (!q.empty()) {
            int size = q.size();
            vector<int> ans(size);

            for (int i = 0; i < size; i++) {
                Node* frontNode = q.front();
                q.pop();

                int index = leftToRight ? i : size - i - 1;
                ans[index] = frontNode->data;

                if (frontNode->left)
                    q.push(frontNode->left);

                if (frontNode->right)
                    q.push(frontNode->right);
            }

            // Store the current level
            for (auto i : ans) {
                result.push_back(i);
            }

            // Change direction
            leftToRight = !leftToRight;
        }

        return result;
    }
};

// Sample tree building and traversal output
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    Solution obj;
    vector<int> zigzagOrder = obj.ZigZag(root);

    cout << "ZigZag Traversal: ";
    for (int val : zigzagOrder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
