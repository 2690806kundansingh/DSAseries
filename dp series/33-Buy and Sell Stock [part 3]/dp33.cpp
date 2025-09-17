//buy and sell stock part 3
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solve(int index,int buy,vector<int>&prices,int limit){
        //base case
        if(index==prices.size())
            return 0;

        if(limit==0)
            return 0;    

        int profit = 0;

        if(buy){
            int buykaro = -prices[index]+solve(index+1,0,prices,limit);
            int skipkaro = 0 + solve(index+1,1,prices,limit);
            profit = max(buykaro,skipkaro);
        }    
        else{
            int selkaro = prices[index] + solve(index+1,1,prices,limit-1);
            int skipkaro = 0 + solve(index+1 , 0,prices,limit);
            profit = max(selkaro,skipkaro);
        }
        return profit;
    }
    int maxProfit(vector<int>prices){
        return solve(0,1,prices,2);
    }
};


//using memoisation
class Solution{
    public:
    int solve(int index,int buy,vector<int>&prices,int limit ,vector<vector<vector<int>>>&dp){
        //base case
        if(index==prices.size())
            return 0;

        if(limit==0)
            return 0; 

        if(dp[index][buy][limit]!=-1)
             return dp[index][buy][limit];      

        int profit = 0;

        if(buy){
            int buykaro = -prices[index]+solve(index+1,0,prices,limit,dp);
            int skipkaro = 0 + solve(index+1,1,prices,limit,dp);
            profit = max(buykaro,skipkaro);
        }    
        else{
            int selkaro = prices[index] + solve(index+1,1,prices,limit-1,dp);
            int skipkaro = 0 + solve(index+1 , 0,prices,limit,dp);
            profit = max(selkaro,skipkaro);
        }
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int>prices){
        int n =prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));

        return solve(0,1,prices,2,dp);
    }
};


//using tabulaaiton mathod
int solveTab(int index,int buy,vector<int>&prices){
    int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,0)));

    for(int index=n-1;index>=0;index++){
        for(int buy=0;buy<=1;buy++){
            for(int limit=0;limit<=2;limit++){

            int profit = 0;

            if(buy){
                int buykaro = -prices[index]+dp[index+1][0][limit];
                int skipkaro = 0 + dp[index+1][1][limit];
                profit = max(buykaro,skipkaro);
            }    
            else{
                int selkaro = prices[index] + dp[index+1][1][limit-1];
                int skipkaro = 0 + dp[index+1][0][limit];
                profit = max(selkaro,skipkaro);
            }
            dp[index][buy][limit] = profit;
        }
    }
}
    return dp[0][1][2];
}
int maxProfit(vector<int>prices){
    return solveTab(prices);
}



