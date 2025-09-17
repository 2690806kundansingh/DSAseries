//Longest common Subsquences
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(string &a,string &b,int i,int j){
        //base case
        if(i==a.length())
          return 0;

        if(j==b.length())
           return 0;

        int ans=0;
        if(a[i]==b[j]){
           ans= 1 + solve(a,b,i+1,j+1);
        }
        else{
            ans=max(solve(a,b,i+1,j),solve(a,b,i,j+1));
        }   
        return ans;

    }
    int longestCommonSubsequence(string text1,string text2){
        return solve(text1,text2,0,0);
    }
};


//using memoisation method
class Solution{
    public:
    int solve(string &a,string &b,int i,int j,vector<vector<int>>&dp){
        //base case
        if(i==a.length())
          return 0;

        if(j==b.length())
           return 0;

        if(dp[i][j]!=-1)
           return dp[i][j];   

        int ans=0;
        if(a[i]==b[j]){
           ans= 1 + solve(a,b,i+1,j+1,dp);
        }
        else{
            ans=max(solve(a,b,i+1,j,dp),solve(a,b,i,j+1,dp));
        }   
        return dp[i][j] = ans;

    }
    int longestCommonSubsequence(string text1,string text2){
        vector<vector<int>>dp(text1.lenght(),vector<int>(text2.length(),-1));
        return solve(text1,text2,0,0,dp);
    }
};

//using bottom up approach
int solveTab(String a,String b){
    vector<vector<int>>dp(a.length()+1,vector<int>(b.length()+1,0));

    for(int i=a.length();i>=0;i--){
        for(int j=b.length(); j>=0;b--  ){
            int ans=0;
        if(a[i]==b[j]){
           ans= 1 + dp[i+1][j+1];
        }
        else{
            ans=max(dp[i+1][j],dp[i][j+1]);
        }   
          dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int longestCommonSubsequences(string text1,string text2){

    return solve(text1,text2);
}


//using space ooptimisation method
int solvespace(string a,string b){

    vector<int>curr(b.length()+1,0);
    vector<int>next(b.length()+1,0);

    for(int i=a.length();i>=0;i++){
        for(int j=b.length(); j>=0;b++){
            int ans=0;
        if(a[i]==b[j]){
           ans= 1 + next[j+1];
        }
        else{
            ans=max(next[j],curr[j+1]);
        }   
          curr[j] = ans;
        }
        next=curr;
    }
    return next[0];
}
int longestCommonSubsequences(string text1,string text2){
    return solvespace(text1,text2);
}

