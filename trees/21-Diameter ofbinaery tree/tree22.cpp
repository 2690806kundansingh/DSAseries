// class Solution{
//     private:
//     int height(struct Node*node){
//         //base case
//         if(node== NULL){
//             return 0;
//         }
//         int left = height(node->left);
//         int right = height(node->right);

//         int ans = max(left,right) + 1;
//         return ans;
//     }
//     public:
//     int diameter(Node*root){
//         //base case
//         if(root == NULL){
//             return 0;
//         }

//         int op1 = diameter(root->left);
//         int op2 = diameter(root->right);
//         int op3 = height(root->left) + height + height(root->right);
//         int ans = max(op1 , max(op2,op3));
//         return ans;

//     }
// };   O(n2)

class Solution{
    public:
    //function to return the diameter of a binary tree
    pair<int,int>diameterfast(Node*root){
        //base case
        if(root == NULL){
            pair<int,int>p = makePair(0,0);
            return p;
        }
        pair<int,int>left = diameterfast(root->left);
        pair<int,int>right = diameterfast(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;

        pair<int,int>ans;
        ans.first = max(op1,max(op2,op3));
        ans.second =max(left.second,right.second) + 1;
        return ans;
    }
    int daiameter(Node*root){
        return diameterfast(root).first;
    }
};