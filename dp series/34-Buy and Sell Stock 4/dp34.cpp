//buy and sell stck 4
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(vector<int>&prices,int k){
        int n = prices.size();

        vector<vector<int> >curr(2,vector<int>(k+1,0));
        vector<vector<int> >next(2,vector<int>(k+1,0));

        for(int index = n-1 ; index>=0;index--){
            for(int buy =0;buy<=1;buy++){
                for(int limit =1;limit<=k;limit++){
                    int profit = 0;
                    if(buy){
                        int buykaro = -prices[index] + next[0][limit];
                        int skipkaro = 0 + next[1][limit];
                        profit = max(buykaro,skipkaro);
                    }
                    else{
                        int sellkaro = prices[index] + next[1][limit-1];
                        int skipkaro = 0 + next[0][limit];
                        profit = max(sellkaro,skipkaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next=curr;
        }
        return next[1][k];
    }

    int maxProfit(int k,vector<int>&prices){
        return solve(prices,k);
    }
};

// transaction method
int solveTr(int index,int operation int k vector<int>&prices){
    if(index==prices,size())
       return 0;
    if(operation==2*k)
       return 0;
    int profit = 0;   
    if(operation % 2==0){
        //buy allowed ahi
        int buykaro = -prices[index] + solve(index+1,operation+1,k,prices);
        int skipkaro = 0 + solve(index+1,operation,k,prices);
        profit=max(buykaro,skipkaro);
    }  
    else{
        int selkaro = -prices[index] + solve(index+1,operation+1,k,prices);
        int skipkaro = 0 + solve(index+1,operation,k,prices);
        profit=max(buykaro,skipkaro);
    } 
    return profit;
}
int maxProfit(int k,vector<int>&prices){
    return solveTr(0,0,k,pricex);
}


//using memoization method

int solveTr(int index,int operation int k vector<int>&prices,vector<vector<int>>&dp){
    if(index==prices,size())
       return 0;
    if(operation==2*k)
       return 0;

    if(dp[index][operation]!=-1)
        return dp[index][operation];

    int profit = 0;   
    if(operation % 2==0){
        //buy allowed ahi
        int buykaro = -prices[index] + solve(index+1,operation+1,k,prices,dp);
        int skipkaro = 0 + solve(index+1,operation,k,prices,dp);
        profit=max(buykaro,skipkaro);
    }  
    else{
        int selkaro = -prices[index] + solve(index+1,operation+1,k,prices,dp);
        int skipkaro = 0 + solve(index+1,operation,k,prices,dp);
        profit=max(buykaro,skipkaro);
    } 
    return dp[index][operation] = profit;
}
int maxProfit(int k,vector<int>&prices){
    int n=prices.size();
    vector<vector<int>>dp(n,vector<int>(2*k,-1));
    return solveTr(0,0,k,pricex);
}


//using tabulation method
int solve(int k,vector<int>&prices){
    int n=prices.size();

    vecot<vector<int>>do(n+1,vector<int>(2*k+1,0));

    for(int index=n-1;index>=0;index--){
        for(int operation=0;operation < 2*k;operation++){
            int profit = 0;   
            if(operation % 2==0){
                //buy allowed ahi
                int buykaro = -prices[index] + dp[index+1][operation+1];
                int skipkaro = 0 + dp[index+1][operation];
                profit=max(buykaro,skipkaro);
            }  
            else{
                int selkaro = -prices[index] + dp[index+1][operation+1];
                int skipkaro = 0 + dp[index+1][operation];
                profit=max(buykaro,skipkaro);
            } 
             dp[index][operation] = profit;
        }
    }
    return dp[0][0];
}
int maxProfit(int k,vector<int>&prices){
    return solve(k,prices);
}


//using space optimisation;

int solve(int k,vector<int>&prices){
    int n=prices.size();

    vecot<vector<int>>do(n+1,vector<int>(2*k+1,0));
    vector<int>curr(2*K+1,0);
    vector<int>next(2*k+1,0);

    for(int index=n-1;index>=0;index--){
        for(int operation=0;operation < 2*k;operation++){
            int profit = 0;   
            if(operation % 2==0){
                //buy allowed ahi
                int buykaro = -prices[index] + next[operation+1];
                int skipkaro = 0 + next[operation];
                profit=max(buykaro,skipkaro);
            }  
            else{
                int selkaro = -prices[index] + next[operation+1];
                int skipkaro = 0 + next[operation];
                profit=max(buykaro,skipkaro);
            } 
            curr[operation] = profit;
        }
        next=curr;
    }
    return next[0];
}
int maxProfit(int k,vector<int>&prices){
    return solve(k,prices);
}


