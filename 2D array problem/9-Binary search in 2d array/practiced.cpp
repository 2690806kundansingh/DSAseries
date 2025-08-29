#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    bool searchMatrix(vector<vector<int>>&matrix,int target){
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = row * col -1;
        int mid = start + (end-start)/2;

        while(start < end){
            int element = matrix[mid/col][mid%col];

            if(element == target){
                return 1;
            }
            if(element < target){
                start = mid + 1;
            }
            else{
                end = mid-1;
            }
            mid = start +(end-start)/2;
        }
        return 0;
    }
};
int main(){
    Solution obj;
    vector<vector<int>>nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int ans = obj.searchMatrix(nums,35);
    if(ans){
        cout<<"Target is found :"<<endl;
    }
    else{
        cout<<"Target is not found :"<<endl;
    }
    return 0;
}