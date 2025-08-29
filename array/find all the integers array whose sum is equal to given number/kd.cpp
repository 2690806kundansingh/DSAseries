//find the pair whose sum is k
// class solution{
//     public:
//     int Countpair(int arr[],int n,int sum){
//         //complete the function
//         int i=0;
//         int j=n-1;
//         int ans=0;
//         int k=0;
//         while(i<j){
//           k=arr[i]+arr[j];
//           if(k==sum){
//             ans++;
//             i++;
//             j--;
//           }
//           else if(k>sum){
//             j--;
//           }
//           else{
//             i++;
//           }  
//         }
//         if(ans==0){
//             return -1;
//         }
//     }
// };




#include<iostream>
using namespace std;

class Solution{
  public:

  int CountPair(int arr[],int n,int sum){
    int i=0;
    int j = n-1;
    int k = 0;
    int ans = 0;

    while(i<j){
      k = arr[i] + arr[j];
      if(k == sum){
        ans++;
         i++;
         j--;
      }
      else if(k > sum){
        j--;
      }
      else{
        i++;
      }
    }
    if(k == 0){
      return -1;
    }
  }
};

int main(){
  int arr[] = {1,5,7,-1};
  int n = sizeof(arr) / sizeof(arr[0]);
  Solution obj;

  int sum = 6;
  int ans = obj.CountPair(arr,n,sum);
  cout<<"The count pair is "<<ans;
  cout<<endl;
  return 0;
}