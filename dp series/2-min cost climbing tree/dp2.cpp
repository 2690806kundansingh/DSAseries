#include<bits/stdc++.h>
using namespace std;

//using recursion
class Solution{
    public:
    int solve(vector<int>&cost,int n){
        //base case
        if(n==0)
           return cost[0];

        if(n==1)
           return cost[1];

        int ans = cost[n] + min(solve(cost,n-1),solve(cost,n-2));
           return ans;      
    }
    int minCostClimbingTree(vector<int>&stair){
        int n = cost.size();
        int ans = min(solve(cost,n-1)+solve(cost,n-2));
        return ans;
    }
};

// recurson + memoisation ,ethod
class Solution{
    public:
    int solve(vector<int>&cost,int n,vector<int>&dp){
        //base case
        if(n==0)
           return cost[0];

        if(n==1)
           return cost[1];
        //step 3 check if already calculated
        if(dp[n]!=-1)
           return dp[n];   

        //step 2 dp add kardo
        int dp[n] = cost[n] + min(solve(cost,n-1,dp),solve(cost,n-2,dp));
           return ans;      
    }
    int minCostClimbingTree(vector<int>&stair){
        int n = cost.size();
        //step 1 create adp array
        vector<int>dp(n+1,-1);
        int ans = min(solve(cost,n-1,dp)+solve(cost,n-2,dp));
        return ans;
    }
};


//tabulation method
class Solution{
    public:
    int solve(vector<int>&cost,int n){
        //base case
        dp[0] = cost[0];

        dp[1] = cost[1];

        for(int i = 2;i<n;i++){
            dp[i] = cost[i] + min(dp[i-1]+dp[i-2]);
        } 
        return min(dp[i-1]+dp[i-2]);
    }
    int minCostClimbingTree(vector<int>&stair){
        int n = cost.size();
        int ans = min(solve(cost,n-1)+solve(cost,n-2));
        return ans;
    }
};


//space optimisaton method
class Solution{
    public:
    int solve(vector<int>&cost,int n){
        //base case
        int prev1 = cost[0];
        int prev2 = cost[1];

        for(int i=2;i<n;i++){
            int curr = cost[i] + min(prev1 + prev2);
            prev2 = prev1;
            prev1 = curr;
        }  
        return min(prev1,prev2);  
    }
    int minCostClimbingTree(vector<int>&stair){
        int n = cost.size();
        return solve(cost,n);
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Min cost: " << sol.minCostClimbingStairs(cost1) << endl;
    // Expected: 15

    // Example 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Min cost: " << sol.minCostClimbingStairs(cost2) << endl;
    // Expected: 6

    return 0;
}