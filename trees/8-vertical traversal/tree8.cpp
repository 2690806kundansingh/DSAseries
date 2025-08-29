
#include<iostream>
#include<map>
#include<vector>
#include<queue>
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
    vector<int>verticalorder(Node*root){
        vector<int>ans;
        map<int,map<int,vector<int>>>nodes;
        queue<pair<Node*,pair<int,int>>>q;

        if(root == NULL)
           return ans;
        q.push(make_pair(root,make_pair(0,0)));
        
        while(!q.empty()){
            pair<Node*,pair<int,int>>temp = q.front();
            q.pop();
            Node*frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;

            //har node ke corresponding entry bana lo
            nodes[hd][level].push_back(frontNode->data);

            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,level+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,level+1)));
            }
        }
        for(auto i: nodes){
            for(auto j:i.second){
                for(auto k:j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};

int main(){
    Node*root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution sol;
    vector<int>result = sol.verticalorder(root);

    //printing result
    for(int val:result){
        cout<<val <<" ";
    }
    cout<<endl;
    return 0;
}