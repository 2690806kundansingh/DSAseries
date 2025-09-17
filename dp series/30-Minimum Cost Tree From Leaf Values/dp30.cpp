//minimum cost tree from leaf value
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right){
        //base case
        if(left==right)
           return 0;

        int ans = INT_MAX;

        for(int i=left;i<right;i++){
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solve(arr,maxi,left,i) + solve(arr,maxi,i+1,right));
        }  
        return ans; 
    }
    int mctFromLeafValues(vector<int>&arr){
        map<pair<int,int>,int> maxi;

        for(int i=0;i<arr.size();i++){
            //when both are same value
            maxi[{i,i}] = arr[i];

            for(int j=i;j<arr.size();j++){
                maxi[{i,j}]= max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solve(arr,maxi,0,arr.size()-1);
    }
    
};


//using dp
//minimum cost tree from leaf value

class solution{
    public:
    int solve(vector<int>&arr,map<pair<int,int>,int>&maxi,int left,int right,vector<vector<int>>&dp){
        //base case
        if(left==right)
           return 0;

        if(dp[left][right]!=-1)
        return dp[left][right];   

        int ans = INT_MAX;

        for(int i=left;i<right;i++){
            ans = min(ans,maxi[{left,i}]*maxi[{i+1,right}] + solve(arr,maxi,left,i,dp) + solve(arr,maxi,i+1,right,dp));
        }  
        return dp[left][right] = ans; 
    }
    int mctFromLeafValues(vector<int>&arr){
        map<pair<int,int>,int> maxi;

        int n=arr.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));

        for(int i=0;i<arr.size();i++){
            //when both are same value
            maxi[{i,i}] = arr[i];

            for(int j=i;j<arr.size();j++){
                maxi[{i,j}]= max(arr[j],maxi[{i,j-1}]);
            }
        }
        return solve(arr,maxi,0,arr.size()-1,dp);
    }
    
};


