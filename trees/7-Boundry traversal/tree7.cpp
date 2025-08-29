
#include<iostream>
#include<vector>
using namespace std;

class Node{
   public:
   int data;
   Node*left;
   Node*right;

   Node(int data){
      this->data= data;
      this->left = NULL;
      this->right = NULL;
   }
};

class Solution{
   public:
   void leftTraverse(Node*root,vector<int>&ans){
   //base case
   if((root == NULL) || (root->left == NULL && root->right == NULL))
      return;
   ans.push_back(root->data);
   if(root->left){
      leftTraverse(root->left,ans);
   }   
   else{
      leftTraverse(root->right,ans);
   }

}
void leafTraverse(Node*root,vector<int>&ans){
   //base case
   if(root == NULL)
      return;
   if(root->left == NULL && root->right == NULL){
      ans.push_back(root->data);
      return;
   }
   leftTraverse(root->left,ans);
   leafTraverse(root->right,ans);
      

}
void rightTraverse(Node*root,vector<int>&ans){
   //base case
   if((root == NULL) || (root->left == NULL && root->right == NULL))
       return;
   if(root->right){
      rightTraverse(root->right,ans);
   }
   else{
      rightTraverse(root->left,ans);
   }       
}
vector<int>boundaryTraveral(Node*root){
   vector<int>ans;
   if(root == NULL){
      return ans;
   }
   ans.push_back(root->data);

   //left part traverse karo
   leftTraverse(root->left,ans);
   //traverse leaf node
   leafTraverse(root->left,ans);

   leafTraverse(root->right,ans);
   //traverse rightpart
   rightTraverse(root->right,ans);
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
    vector<int>result = sol.boundaryTraveral(root);

    //printing result
    for(int val:result){
        cout<<val <<" ";
    }
    cout<<endl;
    return 0;
}

