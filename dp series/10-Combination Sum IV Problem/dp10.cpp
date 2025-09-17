//Combination Sum of IV Problem
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&nums,int tar){
    //base case
    if(tar<0)
      return 0;

    if(tar==0)
       return 1;


    int ans=0;
    for(int i=0;i<nums.size();i++){
        ans += solve(nums,tar-nums[i]); 
    }  
    return ans;   
}
int findWays(vector<int>&nums,int tar){
    return solve(nums,tar);
}
// int main(){
//     vector<int>nums={1,2,3};
//     int tar=4;
//     cout<<"number of ways to achieve the target sm:"<<Findway(nums,tar)<<endl;
//     return 0;
// }


//recursion + memoization
int solveMem(vector<int>&nums,int tar,vector<int>&dp){
    //base case
    if(tar<0)
      return 0;

    if(tar==0)
      return 1;

    if(dp[tar]!=-1)
       return dp[tar];

     int ans=0;
     for(int i=0;i<nums.size();i++){
        ans+= solveMem(nums,tar-nums[i],dp);
     } 
     dp[tar]=ans;
     return dp[tar];

}
int findWay(vector<int>&nums,int tar){
    vector<int>dp(tar+1,-1);
    return solveMem(nums,tar,dp);
}


//tabulation method
int solveTab(vector<int>&nums,int tar){

    vector<long long>dp(tar+1,0);
    dp[0]=1;

    //traversing on target
    for(int i=1;i<=tar;i++){

        //traversing on number
        for(int j=0;j<nums.size();j++){
            if(i-nums[j]>=0)
               dp[i]+=dp[i-nums[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int>&nums,int tar){
    return solveTab(nums,tar);
}

