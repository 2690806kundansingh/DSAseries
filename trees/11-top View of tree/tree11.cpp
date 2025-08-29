
#include<iostream>
#include<map>
#include<queue>
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
    vector<int>TopView(Node*root){
        vector<int>ans;
        if(root == NULL)
           return ans;

        map<int,int>topNode; 
        queue<pair<Node*,int>>q; 

        q.push(make_pair(root,0));
        
        while(!q.empty()){
            pair<Node*,int>temp = q.front();
            q.pop();
            Node*frontNode = temp.first;
            int hd = temp.second;

            // if one value is present for hd then do nothing
            if(topNode.find(hd) == topNode.end())
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
    vector<int>result = sol.TopView(root);

    //printing result
    for(int val:result){
        cout<<val <<" ";
    }
    cout<<endl;
    return 0;
}


// Q: How does the approach work?

// Use level-order traversal (BFS) with a queue.

// Each node has a horizontal distance (hd) from the root:

// Root → hd = 0

// Left child → hd - 1

// Right child → hd + 1

// We store the first node we see at each hd in a map.

// At the end, we extract the map in order of hd (which is sorted in std::map) to get the top view.