/*You are given a 0-indexed 2D integer array nums. Initially, your score is 0. Perform the following operations until the matrix becomes empty:

From each row in the matrix, select the largest number and remove it. In the case of a tie, it does not matter which number is chosen.
Identify the highest number amongst all those removed in step 1. Add that number to your score.
Return the final score.*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    int matrixSum(vector<vector<int>>& nums){
        int n = nums.size();
        int m = nums[0].size();

        // Sort each row in descending order
        for(int i = 0; i < n; i++){
            sort(nums[i].begin(), nums[i].end(), greater<int>());
        }

        int score = 0;
        // For each column, take the maximum element
        for(int j = 0; j < m; j++){   // ✅ use m (columns), not n
            int maxi = 0;
            for(int i = 0; i < n; i++){
                maxi = max(maxi, nums[i][j]);
            }
            score += maxi;
        }
        return score;
    }
};

int main(){
    Solution obj;
    vector<vector<int>> nums = {{3,4,11},{2,12,1},{7,8,7}};
    int result = obj.matrixSum(nums);
    cout << "The final score is: " << result;
    return 0;
}
