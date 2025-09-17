// 2d problem using dp knapsack
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& weight,vector<int>&value,int index,int capacity){
    //base case 
    //we move  right to left
    // if only 1 item to steel, then just compare its wight with the knapsack capacity
    if(index==0){
        if(weight[0]<=capacity)// W is the capacity
          return value[0];
        else
          return 0;  
    }
    //abhi jis index pe khade ho
    int include=0;
    if(weight[index]<=capacity){
        //jis index pe ho use bhi include karo
         include=value[index]+solve(weight,value,index-1,capacity-weight[index]);

         int exclude=0+solve(weight,value,index-1,capacity);

         int ans=max(exclude,include);
         return ans;
    }
}
int knapsack(vector<int>weight,vector<int>value,int n,int maxWeight){
    return solve(weight,value,n-1,maxWeight);
}





//recursion +memoization
int solveMem(vector<int>&weight,vector<int>&value,int n,int index,int capacity,vector<int>&dp){
    if(weight[0]<=capacity){
        return value[0];
    }
    else
       return 0;

    if(dp[n]!=-1)
       return dp[n];   

    int include=0;
    include=value[index]+solveMem(weight,value,index-1,capacity-weight[index],dp);   

    int exclude=0+solveMem(weight,value,index-1,capacity,dp );
   

    dp[index][capacity]=max(exclude,include);
    return dp[index,include];
}
int knapsack(vector<int>weight,vector<int>&value,int n,int maxWeight){
    vector<int>dp[n,vector<int>(maxWeight+1),-1];
    return solveMem(weight,value,n-1,maxWeight,dp);
}




//using tabulation method

int solveTab(vector<int>weight,vector<int>&value,int n,int maxWeight){
    //step1:
    vector<int>dp[n,vector<int>(maxWeight+1,-1)];
    
    //step 2: analyse base case and fill the dp array
    for(int W=weight[0]; W<=capacity;W++){
        if(weight[0]<=value[0]);
          dp[0][w]=value[0];
        else 
           dp[0][w]=0;  
    }

    //step 3 take care remaining recursive call
    for(int index=1;index<n;index++){
        for(int w=0;w<=capacity;w++){
            int include=0;

            if(weight[index]<= W)
              include=value[index]+dp[index-1][W-weight[index]];

            int exclude=0+dp[index-1][W];

            dp[index][W]=max(exclude,include);  
        }
    }
    return dp[n-1][capacity];
}

int knapsack(vector<int>weight,vector<int>&value,int n,int maxWeight){
    return solveTab(weight,value,n,maxWeight);
}



