//Pizza with 3n slices
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int solve(int index,int endindex,vector<int>&slices,int n){
        //base case
        if(n==0 || index>=endindex){
            return 0;
        }

        int take=slices[index]+solve(index+2,endindex,slices, n-1);
        int notTake=0+solve(index+1,endindex,slices, n);

        return max(take,notTake);
    }
    int maxSizeSlices(vector<int>& slices){
        int k=slices.size();
        //jab m pahle wale slice ko kha raha honga 
        int case1=solve(0,k-2,slices,k/3);
        int case2=solve(1,k-1,slices,k/3);
        return max(case1,case2);
    }
};


//using memoization method

int solveMem(int index,int endindex,vector<int>&slices,int n,vector<vector<int>>&dp){
    //base case
    if(n==0|| index>endindex)
       return 0;

    if(dp[index][n]!=-1)
       return dp[index][n];

    int take=slices[index]+solveMem(index+2,endindex,slices,n-2,dp);  
    int notTake=0+solveMem(index+1,endindex,slices,n,dp); 

    return dp[index][n]=max(take,notTake);
}
int maxSizeSlices(vector<int>& slices){
    int k=slices.size();
    vector<vector<int>>dp1(k,vector<int>(k,-1));
    int case1=solveMem(0,k-2,slices,k/3,dp1);

     vector<vector<int>>dp2(k,vector<int>(k,-1));
    int case2=solveMem(1,k-1,slices,k/3,dp2);
    return max(case1,case2);
}


//using tabulation method
int solveTab(vector<int>&slices){
    int k=slices.size();

    vector<vector<int>>dp1(k+2,vector<int>(k+2,0));
    vector<vector<int>>dp2(k+2,vector<int>(k+2,0));

    for(int index=k-1;index>=0;index--){
        for(int n=1;n<=k/3;n++){

            int take=slices[index]+dp1[index+2][n-2];  
            int notTake=0+dp1[index+1][n];

            dp1[index][n]=max(take,notTake);
        }
    }
    int case1=dp1[0][k/3];


    for(int index=k-1;index>=1;index--){
        for(int n=1;n<=k/3;n++){

            int take=slices[index]+dp2[index+2][n-2];  
            int notTake=0+dp2[index+1][n];

            dp2[index][n]=max(take,notTake);
        }
    }
    int case2=dp2[1][k/3];
    return max(case1,case2)
    
}

int maxSizeSlices(vector<int>& slices){
    return solveTab(slices);
}