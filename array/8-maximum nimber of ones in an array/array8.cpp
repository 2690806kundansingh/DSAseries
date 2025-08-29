#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findMaxConsecutiveOnce(vector<int>&nums){
    int count = 0;
    int maxCount = 0;

    for(int num : nums){
        if(num == 1){
            count++;
            maxCount = max(maxCount,count);
        }
        else{
            count = 0;
        }
    }
    return maxCount;
}
int main(){
    vector<int>nums = {1,1,0,1,1,1,1};
    cout<<"Max consecutive ones "<< findMaxConsecutiveOnce(nums) <<endl;
    return 0;
}