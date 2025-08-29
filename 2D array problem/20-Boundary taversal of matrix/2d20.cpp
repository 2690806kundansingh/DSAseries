#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int>boundaryTraversal(vector<vector<int>>matrix,int n,int m){
        vector<int>ans;
        int startingRow = 0;
        int endingRow = n-1;
        int startingCol = 0;
        int endingCol = m-1;

        //first row
        for(int i = 0; i<m ; i++){
            ans.push_back(matrix[startingRow][i]);
        }
        startingRow++;
        //last column
        for(int i = 1; i<n; i++){
            ans.push_back(matrix[i][endingCol]);
        }
        endingCol--;
        //last row;
        if(endingRow >= startingRow){
            for(int i = m-1;i>=0 ;i--){
                ans.push_back(matrix[endingRow][i]);
            }
            endingRow--;
        }
        //first col
        if(startingCol <= endingCol){
            for(int i = n-2; i>= 1; i--){
                ans.push_back(matrix[i][startingCol]);
            }
            startingCol++;
        }
        return ans;
    }
};

int main(){
    Solution sol;
    int n = 4;
    int m = 4;
    vector<vector<int>>matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
    
    vector<int>result = sol.boundaryTraversal(matrix,n,m);
    for(auto &ans :result){
        cout<<ans <<" ";
    }
    return 0;
}