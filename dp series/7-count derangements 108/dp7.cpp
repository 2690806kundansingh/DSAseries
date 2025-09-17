//count derangement
//using recursion
#include<bits/stdc++.h>
#define MOD 10000000007
long long int countDerangement(int n){
    //base case
    if(n==0)[
        return 0;
    ]
    if(n==1){
        return 1;
    }
    int ans= (((n-1)%MOD)*((countDerangement(n-1)%MOD)+
    (countDerangement(n-2)%MOD))%mod);
    return ans;
}

//recursion +memoization
long long int solveMem(int n,vector<long long int>&dp){
    //base case
    if(n==0)
      return 0;
    if(n==1)
      return 1;
    if(dp[n]!=-1)
       return dp[n];  

     dp[n]=   (((n-1)%MOD)*((solveMemt(n-1,dp)%MOD)+
                        (solveMem(n-2,dp)%MOD))%mod);
        return dp[n];                
}
long long int countDerangement(int n){
    vector<long long int>dp[n+1,-1];
    return solveMem(n,dp);
}

//using tabulation method

long long int solveTab(int n){

    vector<long long int>dp[n+1,0];
    dp[1]=0;
    dp[2]=1;

    for(int i=3;i<n;i++){
        long long int first=dp[i-1]%MOD;
        long long int second=dp[i-2]%MOD;
        long long int sum=(first+second)%MOD;

        long long int ans=((i-1)*sum)%MOD;
        dp[i]=ans;
    }
    return dp[n];
}
long long int countDerangement(int n){
    return solveTab(n);
}


//space optimization
long long int solve(int n){

    long long int prev2=0;
    long long int prev1=1;

    for(int i=3;i<n;i++){
        long long int first=prev2%MOD;
        long long int first=prev2%MOD;
        long long int sum= (first=prev2)%MOD;

        long long int ans=((i-1)*sum)%MOD;

        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
long long int countDerangement(int n){
    return solve(n);
}