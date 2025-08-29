#include <iostream>
#include <vector>
#include <algorithm>  // for reverse
using namespace std;

void rotatematrix(vector<vector<int>>& mat) {
    int n = mat.size();

    // Step 1: Transpose
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            swap(mat[i][j], mat[j][i]);
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < n; i++) {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    cout << "Original Matrix:\n";
    for (auto &row : mat) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    rotatematrix(mat);

    cout << "\nRotated Matrix (90 degrees clockwise):\n";
    for (auto &row : mat) {
        for (auto &val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}

