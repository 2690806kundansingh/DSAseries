#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
    bool searchMatrix(vector<vector<int>>&matrix,int target){
        int row = matrix.size();
        int col = matrix[0].size();

        int rowIndex = 0;
        int colIndex = col-1; // start from top-right corner

        while(rowIndex < row && colIndex >= 0){
            int element = matrix[rowIndex][colIndex];

            if(element == target){
                return 1; // found
            }
            if(element < target){
                rowIndex++; // move down
            }
            else{
                colIndex--; // move left
            }
        }
        return 0; // not found
    }
};

int main() {
    Solution s;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10,13,14,17}
    };

    int target;
    cout << "Enter target value: ";
    cin >> target;

    if(s.searchMatrix(matrix, target)){
        cout << "Target " << target << " found in matrix!" << endl;
    }
    else{
        cout << "Target " << target << " NOT found in matrix." << endl;
    }

    return 0;
}
