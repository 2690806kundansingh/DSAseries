//Minimum sideway Jump
#include<bits/stdc++.h>
using namespace std;
int solve(vector<int>& obstacles,int currlane,int currpos){
    //base case
    int n=obstacles.size()-1;
    if(currpos==n){
        return 0;
    }

    if(obstacles[currpos+1] !=currlane){
        return solve(obstacles,currlane,currpos+1);
    }
    else{
        //sideway jump
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(currlane!=i && obstacles[currpos]!=i)
               ans=min(ans,1+solve(obstacles,i,currpos));
        }
        return ans;
    }
}
int minSideJumps(vector<int>&obstacles){
    return solve(obstacles,2,0);
}





//using memoization
int solveMem(vector<int>&obstacles,int curlane,int curpose,vector<vector<int>>dp){
    //base case
    int n=obstacles.size()-1;
    if(curpose==n)
       return 0;

    if(dp[curlane][curpose]!=-1)
       return dp[curlane][curpose];

    if(obstacles[curpose+1]!=curlane){
        return solveMem(obstacles,curlane,curpose+1,dp);
    }
    else{
        //sideway jump
        int ans=INT_MAX;
        for(int i=1;i<=3;i++){
            if(curlane!=i&&obstacles[curpose]!=i)
               ans=min(ans,1+solveMem(obstacles,i,curpose,dp));
        }
        dp[curlane][curpose]=ans;
        return dp[curlane][curpose];
    }      
}
int minsideJumps(vector<int>&obstacles){
    vector<vector<int>>dp(4,vector<int>(obstacles.size(),-1));
    return solveMem(obstacles,2,0,dp);
}



//bottom up approach
int solvetab(vector<int>&obstacles){
    int n=obstacles.size()-1;
    vector<vector<int>>dp(4,vector<int>(obstacles.size(),1e9));

    dp[0][n]=0;
    dp[1][n]=0;
    dp[2][n]=0;
    dp[3][n]=0;


    for(int curpose=n-1;curpose>=0;curpose--){
        for(int currlane=1;currlane<=3;currlane++){

            if(obstacles[curpose+1] !=currlane){
               dp[currlane][curpose]= dp[currlane][curpose+1];
            }
           else{
             //sideway jump
              int ans=1e9;
              for(int i=1;i<=3;i++){
                 if(currlane!=i && obstacles[curpose]!=i)
                    ans=min(ans,1+dp[i][curpose+1]);
                }
                  dp[currlane][curpose]= ans;
            }
        }
    }
    return min(dp[2][0],min(1+dp[1][0],1+dp[3][0]));        

}
int minSideJump(vector<int>&obstacles){
    return solvetab(obstacles);
}