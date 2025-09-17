//maximum sum of non adjacent elements
//using recursion

int solve(vector<int>&nums,int n){
    //base case
    if(n<0)
      return 0;

    if(n==0)
      return nums[0];

    int incl=solve(nums,n-2) +nums[n];
    int excl=solve(nums,n-1) + 0;

    return max(incl,excl);    
}

int maximumAdjacentSum(vector<int>&nums){
    int n=nums.size();
    int ans=solve(nums,n-1);
    return ans;
}



//recusion + memoization

int solveMem(vector<int>&nums,int n,vector<int>&dp){
    //base case
    if(n<0)
      return 0;

    if(n==0)
      return nums[0];

    //step 3
    if(dp[n]!=-1)
       return dp[n];

   dp[n]=max(incl,excl);
   return dp[n]; 
}
int maximunAdjacenetSum(vector<int>&nums){
    int n=nums.size();
    vector<int>dp(n,-1);
    return solveMem(nums,n-1,dp);
}



//using tabulation method
int solve(vector<int>&nums){
    int n=nums.size();
    //step 1 creation
    vector<int>dp(n,0);

    dp[0]=nums[0];

    for(int i=1;i<n;i++){
        int incl=dp[i-2]+nums[i];
        int excl=dp[i-1]+0;
        dp[i]=max(incl,excl);
    }
    return dp[n-1];
}
int maximunAdjacenetSum(vector<int>&nums){
    int solve(nums);
}




//space optimization
int solve(vector<int>&nums){
    int n=nums.size();

    int prev1=0;
    int prev2=nums[0];

    for(int i=1;i<n;i++){
        int incl=prev2+nums[i];
        int excl=prev1+0;

        int ans=max(incl,excl);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
}
int maximunAdjacenetSum(vector<int>&nums){
    return solve(nums); 
}
