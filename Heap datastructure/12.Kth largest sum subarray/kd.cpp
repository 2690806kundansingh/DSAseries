#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    int getLargestSumSubarrray(vector<int>&arr,int k){
        priority_queue<int,vector<int>,greater<int>>min;

        int n = arr.size();

        for(int i = 0; i< n ;i ++){
            int sum = 0;
            for(int j = i; j<n ; j++){
                sum += arr[j];

                if(min.size() < k ){
                    min.push(sum);
                }
                else{
                    if(sum > min.top()){
                        min.pop();
                        min.push();
                    }
                }
            }
        }
        return min.top();
    }
}