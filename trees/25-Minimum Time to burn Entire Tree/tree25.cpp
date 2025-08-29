#include<iostream>
#include<map>
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
    //create mapping
    //return targetnode
    Node*createParentMapping(Node*root,int target,map<Node*,Node*>&nodeToParent){
        Node*res = NULL;

        queue<Node*>q;
        q.push(root);
        nodeToParent[root] = NULL;
        //level order traversal

        while(!q.empty()){
            Node*front = q.front();
            q.pop();

            if(front->data == target){
                res = front;
            }
            if(front->left){
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return res;
    }
    int burnTree(Node*root,map<Node*,Node*>&nodeToParent){

        //algo:
        //step1 = create nodeToParent mapping
        // step2 = find Target node
        // step3 = burn the tree in min time
        map<Node*,bool>visited;
        queue<Node*>q;

        q.push(root);
        visited[root]  = true;


        int ans = 0;
        while(!q.empty()){
            bool  flag = 0;
            int size = q.size();
            for(int i =0; i<size;i++){
                //proceess neighouring nodes
                Node*front = q.front();
                q.pop();

                if(front->left && !visited[front->left]){
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                if(front->right && !visited[front->right]){
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }
                if(nodeToParent[front] && !visited[nodeToParent[front]]){
                    flag = 1;
                    q.push(nodeToParent[front]);
                    visited[nodeToParent[front]] = 1;
                }
            }
            if(flag == 1){
                ans++;
            }
        }
        return ans;
    }
    int minTime(Node*root,int target){
        
        map<Node*,Node*>nodeToParent;
        Node*targetNode = createParentMapping(root,target,nodeToParent);

        int ans = burnTree(targetNode, nodeToParent);

        return ans;

    }
};

// TC => O(n) + O(n) = O(n)
// SC => O(n) + O(n) = O(n)

