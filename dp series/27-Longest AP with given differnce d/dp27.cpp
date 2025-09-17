//longest Ap with given difference "d"
#include<bits/stdc++.h>
using namespace std;

class solution{
    public:
    int longestSubsequence(vector<int>& arr,int difference){

        unordered_map<int,int> dp;
        //ans means lenght to return
        int ans = 0;

        for(int i=0;i<arr.size();i++){
            int temp = arr[i] - difference;
            int tempAns = 0;

            //check answer exits for temp already or not
            if(dp.count(temp))
               tempAns = dp[temp];

            //current answer update
            dp[arr[i]] = 1+ tempAns;

            //ans update
            ans = max(ans,dp[arr[i]]);   
        }
        return ans;
    }
};