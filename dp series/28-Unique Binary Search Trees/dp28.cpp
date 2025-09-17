//Unoque Binary Search Trees
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int numTree(int n){
        if(n<=1)
           return 1;

        int ans=0;
        //think i as root node
        for(int i=1;i<=n;i++){
            ans+= numTree(i-1)* numTree(n-i);
        }
        return ans;   
    }
};

// using addition of dp
class solution{
    public:
    int solveTop(int n,vector<int>&dp){
        if(n <= 1)
           return 1;

        if(dp[n]!=-1)
            return dp[n];   

        int ans =0;
        // think i is root node

        for(int i =1; i<=n ;i++){
            ans += solveTop(i-1,dp) * solveTop(n-i,dp);
        }  
        return dp[n]=ans; 
    }
    int numTrees(int n){
        vector<int>dp(n+1,-1);
        return solveTop(n,dp);
    }
};


//using tabulatiooon method
int solveTab(int n){
    vector<int>dp(n+1,0);
    dp[0] = dp[1] = 1;

    // i number of node
    for(int i=2;i<=n;i++){
        //j is the root node
        for(int j=1; j<=i;j++){
            dp[i]+=dp[j-1]*dp[i-j];
        }
        return dp[n];
    }
    int numTrees(int n){
        return solveTab(n);
    }
}