// //rate in maje problem
// #include<stdlib.h>
// #include<vector>
// #include<string>
// using namespace std;

// bool isSafe(int newx,int newy,vector<vector<bool>>&vis,vector<vector<int>>&arr,int n){
//     if((newx >=0 && newx <n)&&(newy>=0 && newy<n)&& vis[newx][newy]!=1&& arr[newx][newy]==1){
//         return true;
//     }
//     else{
//         return false;
//     }
// }

// void solve(int x,int y,vector<vector<int>>&arr,int n,vector<string>&ans,vector<vector<bool>>&vis,string path){
//     //base case
//     if(x==n-1&& y==n-1){
//         ans.push_back(path);
//         return;
//     }
//     //4 movement
//     //D L R U

//     //down
//      vis[x][y]=1;
//     if(isSafe(x+1,y,vis,arr,n)){
//         solve(x+1,y,arr,n,ans,vis,path + "D");
//         //after returning make visit 0
//     }
//     //left
//     if(isSafe(x,y-1,vis,arr,n)){
//         solve(x,y-1,arr,n,ans,vis,path + "L");
//         //after returning make visit 0
//     }
//     //right
//     if(isSafe(x,y+1,vis,arr,n)){
//         solve(x,y+1,arr,n,ans,vis,path + "R");
//         //after returning make visit 0
//     }
//     //upper
//     if(isSafe(x-1,y,vis,arr,n)){
//         solve(x-1,y,arr,n,ans,vis,path + "U");
//         //after returning make visit 0
//     }
//     vis[x][y]=0;
// }

// int main(){
//     vector<string>Search_maje(vector<vector<int>>&arr,int n){
//         vector<string>ans;
//         vector<vector<bool>> visited(n,vector<bool>(n,0));
//         string path="";
        
//         if(arr[0][0]==0){
//             return;
//         }

//         solve(0,0,arr,n,visited,ans,path);
//         return ans;
//     }
// }


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(int newx, int newy, vector<vector<int>>& vis, vector<vector<int>>& maze, int n) {
        return (newx >= 0 && newx < n && newy >= 0 && newy < n &&
                !vis[newx][newy] && maze[newx][newy] == 1);
    }

    void solve(int x, int y, vector<vector<int>>& maze, int n,
               vector<string>& ans, vector<vector<int>>& vis, string path) {
        // base case
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // mark visited
        vis[x][y] = 1;

        // Down
        if (isSafe(x + 1, y, vis, maze, n)) {
            solve(x + 1, y, maze, n, ans, vis, path + "D");
        }
        // Left
        if (isSafe(x, y - 1, vis, maze, n)) {
            solve(x, y - 1, maze, n, ans, vis, path + "L");
        }
        // Right
        if (isSafe(x, y + 1, vis, maze, n)) {
            solve(x, y + 1, maze, n, ans, vis, path + "R");
        }
        // Up
        if (isSafe(x - 1, y, vis, maze, n)) {
            solve(x - 1, y, maze, n, ans, vis, path + "U");
        }

        // backtrack
        vis[x][y] = 0;
    }

    vector<string> ratInMaze(vector<vector<int>>& maze) {
        int n = maze.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        string path = "";

        // if start or destination is blocked
        if (maze[0][0] == 0 || maze[n - 1][n - 1] == 0)
            return ans;

        solve(0, 0, maze, n, ans, vis, path);

        sort(ans.begin(), ans.end()); // ensure lexicographic order
        return ans;
    }
};

int main() {
    Solution obj;
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };

    vector<string> result = obj.ratInMaze(maze);

    if (result.empty())
        cout << "[]";
    else {
        cout << "[";
        for (int i = 0; i < result.size(); i++) {
            cout << "\"" << result[i] << "\"";
            if (i != result.size() - 1) cout << ", ";
        }
        cout << "]";
    }
    return 0;
}
