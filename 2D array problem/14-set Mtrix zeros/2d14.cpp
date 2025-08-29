#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector<vector<int>>&matrix){
    int m = matrix.size();
    int n = matrix[0].size();

    vector<int>row(m,0); // row marks
    vector<int>col(n,0); // col marks

    //step1 find all zeros and marks row and coll
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(matrix[i][j] == 0){
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    //step2 set cells to zero if row or coll marked
    for(int  i =0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(row[i] == 1 || col[j] == 1){
                matrix[i][j] = 0;
            }
        }
    }

}

int main(){
    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    setZeroes(matrix);

    for(auto &row : matrix){
        for(int val : row)
          cout<<val<<"";
        cout<<endl;  
    }
    return 0;
}
/*
Step 1: Initialize

Let m = number of rows in matrix.

Let n = number of columns in matrix.

Create two helper arrays:

row[m] initialized to 0.

col[n] initialized to 0.
These will mark which rows and columns need to be set to zero.

Step 2: Find zeros and mark rows & columns

Traverse each cell (i, j) of the matrix:

If matrix[i][j] == 0, then:

Mark row[i] = 1.

Mark col[j] = 1.

Step 3: Update the matrix

Traverse the matrix again:

For each cell (i, j):

If row[i] == 1 or col[j] == 1:

Set matrix[i][j] = 0.

Step 4: Output

The matrix is now updated as per the rule.

Print or return the modified matrix
*/