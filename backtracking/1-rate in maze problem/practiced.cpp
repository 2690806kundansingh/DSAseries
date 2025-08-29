#include<iostream>
#include<vector>
using namespace std;

bool isSafe(int newx,int newy,vector<vector<bool>>&vis,vector<vector<int>>&arr,int n){
    if((newx>=0 && newx<n) && (newy>=0 && newy<n) && vis[newx][newy] !=1 && vis[newx][newy] == 1){
        return true;
    }
    else{
        return false;
    }
}

void solve(int x,int y,vector<vector<int>>&arr,int n,vector<string>&ans,vector<vector<bool>>&vis,string path){
    //base case
    if(x == n-1 && y == n-1){
        ans.push_back(path);
        return;
    }
    // 4 movement
    //down
    vis[x][y] == 1;
    if(isSafe(x+1,y,vis,arr,n));
    solve(x+1,y,arr,n,ans,vis,path +"D");
}

int main(){
    vector<string>ratMaze(vector<vector<int>>&arr,int n){
        vector<string>ans;
        vector<vector<bool>>vis(n,vector<int>(n,0));
        string path = "";

        solve(0,0,arr,n,vis,ans,path);
        return ans;
    }
}