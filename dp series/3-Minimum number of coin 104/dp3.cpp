//simple using recursion 

int solveRec(vector<int>&nums,int x){
    //base case
    if(x==0)
      return 0;

    if(x<0)
      return INT_MAX;

    int mini=INT_MAX;
    for(int i=0;i<nums.size();i++){
        int ans=solve(num,x-nums[i]);
        if(ans!=INT_MAX)
          mini=min(mini,1+ans);
    } 
    return mini;   
}
int minelement(vector<int>&nums,int x){
    int ans=solveRec(nums,x);
    if(ans==INT_MAX)
      return -1;
      return ans;
}


//using dp +memoization
int solveMem(vector<int>&nums,int x,vector<int>&dp){
  //base case
  if(x==0)
    return 0;

  if(x<0)
    return INT_MAX;

  if(dp[x]!=-1)
    return dp[x];  

  int mini=INT_MAX;
  for(int i=0;i<nums.size();i++){
    int ans=solveRec(nums,x)
    if(ans==INT_MAX)
      return -1;
     
  }  
  dp[x]=mini; 
  return mini;  
}

int miniElements(vector<int>&nums,int x){
  vector<int>dp(x+1,-1);
  int ans=solveMem(nums,x,dp);

  if(ans==INT_MAX)
     return -1;
  else
     return ans;   
}


// using tabulation
int solveTab(vector<int>&nums,int x){
  vector<int>dp(x+1,INT_MAX);
  dp[0]=0;

  for(int i=1;i<=x;i++){
    // iam try to solve for every amount figure from 1 to x
    for(int j=0;j<nums.size();j++){
      if(i-nums[j]>=0&& dp[i-nums]!=INT_MAX){
        dp[i]=min(dp[i],1+dp[i-nums[j]]);
      }
    }
  }
   if(dp[x]==INT_MAX)
     return -1;

    return dp[x]; 
}
int miniElements(vector<int> &nums,int x){
  return solveTab(nums,x);
}



//using space optimization
