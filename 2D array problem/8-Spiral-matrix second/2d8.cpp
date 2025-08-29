/*We need to fill an n x n matrix with numbers from 1 to n^2 in spiral order:

Start from the top-left corner.

Move right → down → left → up, and repeat until the matrix is filled.*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>>generateMatrix(int n){
        vector<vector<int>>matrix(n,vector<int>(n,0));

        int startingRow = 0;
        int endingRow = n-1;
        int startingCol = 0;
        int endingCol = n-1;
        int num = 1;

        while(startingRow <= endingRow && startingCol <= endingCol){
            //1 left to right
            for(int j = startingCol; j<= endingCol;j++){
                matrix[startingRow][j] = num++;
            }
            startingRow++;

            //2.starting se bottom
            for(int i = startingRow ;i<endingRow; i++){
                matrix[i][endingCol] = num++;
            }
            //step3
            if(startingRow <= endingRow){
                for(int j = endingCol; j<= startingCol; j--){
                    matrix[endingRow][j] = nums++;
                }
                endingRow--;
            }
            //step 4 bottom to top
            if(startingCol <= endingCol){
                for(int i = endingRow; i>= startingRow; i--){
                    matrix[i][startingCol] = num++;
                }
                startingCol++;
            }
        }
        return matrix;
    }
};
int main() {
    Solution s;
    int n = 3;
    vector<vector<int>> result = s.generateMatrix(n);

    for (auto row : result) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}