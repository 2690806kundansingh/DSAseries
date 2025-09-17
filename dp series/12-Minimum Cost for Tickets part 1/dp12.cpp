//Minimum Cost of for Tickets
//ninja trip
#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>&days,vector<int>&cost,int index){
    //base case
    if(index>=n){
        return 0;
    }
    //1 day pass
    int option1=cost[0]+solve(n,days,cost,index+1);

    // 7 day pass
    int i;
    for(i=index; i<n && days[i]<days[index]+7;i++);

    int option2=cost[1]+solve(n,days,cost,i);

    //30 days pass
    for(i=index;i<n &&days[i] < days[index]+30;i++);

    int option3=cost[2]+solve(n,days,cost,i);

    return min(option1,min(option2,option3));
}

int minimumCoins(int n,vector<int>&days,vector<int>cost){
    return solve(n,days,cost,0);
}


//recursion +memoization
int solveMem(int n,vector<int>&days,vector<int>&cost,int index,vector<int>&dp){
    //base case
    if(index>=n)
      return 0;

    if(dp[n]!=-1)
      return dp[n];

    // 1 day pass
    int option1=cost[0]+solve(n,days,cost,index+1,dp);

    int i;
    //day 7 pass
    for(i=index; i< n&&days[i]<days[index]+7;i++);
    int option2= cost[1]+solve(n,days,cost,i,dp);

    //30 days pass
    for(i=index;i<n&& days[i]<days[index]+30;i++);
    int option3= cost[2]+solve(n,days,cost,i,dp);

    dp[index]= min(option1,option2,option3); 
    return dp[index];
}
int minimumCoins(int n,vector<int>days,vector<int>cost){
    vector<int>dp(n+1,-1);
    return solveMem(n,days,0,dp);
}


//using tabulation bootom up apprach
int solveTab(int n,vector<int>&days,vector<int>&cost){
    vector<int>dp[n+1,INT_MAX];
    dp[n]=0;

    for(int k=n-1;k>=0;k--){
        //day 1 pass
        int option1=cost[0]+dp[k+1];

        //day 7 pass
        for(int i=k; i<n&& days[i]<days[k]+7;i++);
        int option2=cost[1]+dp[k];

        //day 30 pass
        for(int i=k;k<n&& days[i]<days[k]+30;k++);
        int option3=cost[2]+dp[k];

        dp[k]=min(option1,option2,option3);
    }
     return dp[0];
}
int minimumCoins(int n,vector<int>days,vector<int>cost){
    return solveTab(n,days,cost);
}
