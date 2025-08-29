//Print matrix like snake
#include <iostream>
#include <vector>
using namespace std;

void printMatrixLikeSnake(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    if (rows == 0) return;
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        if (i % 2 == 0) {
            // left to right
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
        } else {
            // right to left
            for (int j = cols - 1; j >= 0; j--) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printMatrixLikeSnake(matrix);

    return 0;
}
