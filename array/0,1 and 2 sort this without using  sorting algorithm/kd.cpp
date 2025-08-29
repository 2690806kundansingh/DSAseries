//sort 0,1,2 without using soring algorithm
//using dutch algorithm
//using vector

#include<iostream>
#include<vector>
using namespace std;

class Solution{
  public:
  void sortArray(vector<int>&nums){
    int left = 0;
    int mid = 0;
    int right = nums.size()-1;

    while(mid <= right){
      if(nums[mid] == 0){
        swap(nums[mid],nums[left]);
        left++;
        mid++;
      }
      else if(nums[mid] == 1){
          mid++;
        }
        else if(nums[mid] == 2){
            swap(nums[mid],nums[right]);
            right--;
        }
      }
  }
};

int main(){
vector<int>nums = {0,0,1,1,1,2,2,0,1,0,2};
Solution obj;
obj.sortArray(nums);

cout<<"Sorted Array";
for(int num: nums){
  cout << num<<" ";
}
cout<<endl;

return 0;
}
