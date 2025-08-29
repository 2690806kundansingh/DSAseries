#include<iostream>
#include<vector>
using namespace std;

vector<int>printWave(vector<vector<int>>&matrix,int nrow,int mcol){
    vector<int>ans;

    for(int col = 0; col <mcol;col++){
        if(col & 1){
            //odd condition ->bottom to top
            for(int row = nrow -1;row >= 0 ;row--){
                ans.push_back(matrix[row][col]);
            }
        }
        else{
            //0 or evencondition ->top to bottom
            for(int row = 0; row < nrow; row++){
                ans.push_back(matrix[row][col]);
            }
        }
    }
    return ans;
}