//find the contiguous subarray using kaidens algorith
// #include<iostream>
// #include<algorithm>
// #include<vector>
// using namespace std;
// int main(){
//     class solution{
//         public:
//         int maxsubarray(vector<int>&num){
//           int sum=0;
//           int maxi=num[0];
//           for(int i=0;i<num.size();i++){
//             sum=sum+num[i];
//             maxi=max(maxi,sum);
//           }
//           if(sum<0){
//             sum=0;
//           }
//             return maxi;

//         }
//    };
// }





#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  long long maxSubarray(vector<int>&nums){
      int sum = 0;
      int maxi = nums[0];

      for(int i =0; i < nums.size() ; i++){
        sum = sum + nums[i];
        maxi = max(maxi,sum);
      }
      if(sum<0){
        sum = 0;
      }
      return maxi;  
  }
};

int main(){
  vector<int>nums = {5,4,2,4};
  Solution obj;

  int reult = obj.maxSubarray(nums);

  cout<<"This is the maximum contiguous :"<<reult;
  return 0;
}