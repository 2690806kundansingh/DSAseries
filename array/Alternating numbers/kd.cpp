//alternating numbers
//rearrenge Array element by sign
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int>rearrenge(vector<int>nums){
        int n = nums.size();
        vector<int>ans(n,0);

        int posIndex = 0;
        int negIndex = 1;
        

        for(int i =0; i< n ;i++){
            if(nums[i] < 0 ){
                ans[negIndex] = nums[i];
                negIndex +=2;
            }
            else{
                ans[posIndex]= nums[i];
                posIndex +=2;
            }
        }
        return ans;
    }
};

int main(){
    vector<int>nums ={1,4,-3,6,-3,5,3,5,-7,-7};
    Solution obj;

    vector<int> result = obj.rearrenge(nums);

    cout<<" arranging int the alternating order ";

    for(int num:result){
        cout << num <<" ";
    }
    cout<<endl;
    return 0;

}
// TC (n)