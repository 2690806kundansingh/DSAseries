//using preorder traversa

#include<iostream>
#include<vector>
#include<map>
using namespace std;

void solve(Node*root,int dia,map<int,vector<int>>&mp){
    if(root == NULL)
       return;
    mp[dia].push_back(root->data);

    solve(root->left,dia+1,mp);
    solve(root->right ,dia,mp);   
}

vector<int>diagonal(Node*root){
    map<int,vector<int> >mp;
    solve(root,1,map);
    vector<int>ans;

    //to print the vector value
    for(auto it = map.begin(); it != map.end(); it++){
        vector<int>temp = it->second;
        for(int i=0;i<temp.size();i++){
            ans.push_back(temp[i]);
        }
    }
    return ans;
}