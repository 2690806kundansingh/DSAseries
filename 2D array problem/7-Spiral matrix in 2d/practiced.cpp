#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int>spiralMatrix(vector<vector<int>>&matrix){
        vector<int>ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row * col;

        //index initialize
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row-1;
        int endingCol = col-1;

        while(count < total){
            //print starting row
            for(int index = startingCol; index <= endingCol; index++){
                ans.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;

            //printing ending column
            for(int index = startingRow; index <= endingCol;index++){
                ans.push_back(matrix[index][endingCol]);
                 count++;
            }
            endingCol--;

            //printing ending row
            for(int index = endingCol; index <= startingCol;index++){
                ans.push_back(matrix[endingRow][index]);
                 count++;
            }
            endingRow--;

            //print starting column
            for(int index = endingRow;index<= startingRow;index++){
                ans.push_back(matrix[index][startingCol]);
                 count++;
            }
            startingCol++;
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<vector<int>>matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int>result = obj.spiralMatrix(matrix);
    return 0;
}