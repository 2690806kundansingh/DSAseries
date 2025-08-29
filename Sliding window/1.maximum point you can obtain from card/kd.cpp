#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int maximumSum(vector<int>&nums,int n ,int k){
        int lsum = 0;
        int rsum = 0;
        int maxSum = 0;

        for(int i = 0 ; i<k ; i++){
            lsum = lsum + nums[i];
        }
        maxSum = lsum;
        //shrinking phage removing element from left and adding from the right
        
        for(int i = 0 ; i <k ; i++){
            lsum = lsum - nums[k-1-i];//removing the left element
            rsum = rsum + nums[n-1-i];//adding the right ele,emnt
            maxSum = max(maxSum,lsum + rsum);
        }
        return maxSum;
    }
};

int main(){
    Solution obj;
    vector<int>nums = {6,2,3,4,7,2,1,7,1};
    int k = 4;
    int n = nums.size();

    cout<<"maximum sum : "<<obj.maximumSum(nums,n,k);
    return 0;
}