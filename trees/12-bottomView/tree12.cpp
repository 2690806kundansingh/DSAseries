// #include<iostream>
// #include<vector>
// #include<map>
// #include<queue>
// using namespace std;

// class solution{
//     public:
//     //function to return of list of node visisble from the top view from left to right
//     vector<int>topView(Node*root){
//         vector<int>ans;
//         if(root == NULL)
//            return ans;

//         map<int,int>topNode;
//         queue<pair<Node*,int> > q;

//         while(!q.empty()){
//             pair<Node*,int>temp = q.front();
//             q.pop();
//             Node*frontNode = temp.first;
//             int hd = temp.second;

//             //if on evalue is present for a hd then do nothing
//             //if(topNode.find(hd) == topNode.end())
//                 topNode[hd] = frontNode->data;

//             if(frontNode->left)
//                q.push(make_pair(frontNode->left,hd-1));

//             if(frontNode->right)
//                q.push(make_pair(frontNode->right,hd+1));       
//         }
//         for(auto i: topNode){
//             ans.push_back(i.second);
//         }
//         return ans;
//     }
// };


#include<iostream>
#include<queue>
#include<map>
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
    vector<int>bottomView(Node*root){
        vector<int>ans;
        if(root == NULL){
            return ans;
        }
        map<int,int>topNode;
        queue<pair<Node*,int>>q;

        q.push(make_pair(root,0));

        while(!q.empty()){
            pair<Node*,int>temp = q.front();
            q.pop();
            Node*frontNode = temp.first;
            int hd = temp.second;

            topNode[hd] = frontNode->data;

            if(frontNode->left)
               q.push(make_pair(frontNode->left,hd-1));
            
            if(frontNode->right)
               q.push(make_pair(frontNode->right,hd+1));   
        }
        for(auto i:topNode){
            ans.push_back(i.second);
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
    vector<int>result = sol.bottomView(root);

    //printing result
    for(int val:result){
        cout<<val <<" ";
    }
    cout<<endl;
    return 0;
}