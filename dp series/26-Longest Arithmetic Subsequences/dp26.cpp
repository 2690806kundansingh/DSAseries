//longest arithmetic Subsequences/progression
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:

    int solve(int index,int diff,int A[]){
        //backtward check
        if(index < 0)
           return 0;

        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(A[index]-A[j]==diff){
                ans=max(ans,1+solve(j,diff,A));
            }
        }  
        return ans; 
    }
    int lengthOfLongestAP(int A[],int n){
        // agar n less than or eqal to 2 hai to return kar do
        if(n<=2)
           return n;
        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,A[j]-A[i],A));
            }
        }
        return ans;
    }
};

//using top down approach

class solution{
    public:

    int solve(int index,int diff,int A[],unordered_map<int,int>&dp){
        //backtward check
        if(index < 0)
           return 0;

        if(dp[index].count(diff))
            return dp[index][diff];   

        int ans=0;
        for(int j=index-1;j>=0;j--){
            if(A[index]-A[j]==diff){
                ans=max(ans,1+solve(j,diff,A,dp));
            }
        }  
        return dp[index][diff] = ans; 
    }
    int lengthOfLongestAP(int A[],int n){
        if(n<=2)
           return n;
        int ans=0;

        //important
        //int int (diff ,length)
        unordered_map<int,int> dp(n+1);

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans=max(ans,2+solve(i,A[j]-A[i],A,dp));
            }
        }
        return ans;
    }
};


//using bottom up approach
class solution{
    public:
    int lengthOfLongestAP(int A[],int n){
        if(n<=2)
          return n;
        int ans=0;

        unordered_map<int,int>dp(n+1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=A[i]-A[j];
                int cnt=1;

                //check if amswer already present
                if(dp[j].count(diff))
                   cnt=dp[j][diff];

                dp[i][diff]=1+cnt; 
                ans=max(ans,dp[i][diff]);  
            }
        }
        return ans;
    }
}