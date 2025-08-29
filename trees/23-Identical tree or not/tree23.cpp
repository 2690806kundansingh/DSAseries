#include<iostream>
using namespace

struct Node{
    int data;
    struct*left;
    struct*right;

    Node(int x){
        data = x;
        left = right = NULL
    }
};

class Solution{
    public:
    //function to check if two tree is balanced or not
    bool isIdentical(Node*ri,Node*r2){
        if(r1 == NULL && r2 == NULL){
            return true;
        }
        if(r1 == NULL && r2 != NULL){
            return false;
        }
        if(r1 != NULL && r2 == NULL){
            return false;
        }

        bool left = isIdentical(r1->left,r2->left);
        bool right = isIdentical(r1->right,r2->right);

        bool value = r1->data == r2->data;

        if(r1 && r2 && value){
            return true;
        }
        else{
            return false;
        }
    }
};