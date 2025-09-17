//BUy and Sell Stock
#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int solveTab(vector<int>&prices,int fee){
        int n=(prices.size());

        vector<int>curr(2,0);
        vector<int>next(2,0);

        for(int index= n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){

                int  profit = 0;
                if(buy){
                    int buykaro = -prices[index]+next[0];
                    int skipkaro = 0 + next[1];
                    profit = max(buykaro,selkaro);
                }
                else{
                    int selkaro = prices[index] + next[1] -fee;
                    int skipkaro = 0 + next[0];
                    profit = max(selkaro,skipkaro);
                }
                cur[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int>&prices,int fee){
        return solveTab(prices,fee);
    }
};