#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int median(vector<vector<int>>& matrix, int R, int C) {
        int low = 1, high = 2000;   // possible value range
        int target = (R * C) / 2;   // median index (0-based)

        while (low <= high) {
            int mid = (low + high) / 2;

            // count numbers <= mid
            int count = 0;
            for (auto &row : matrix)
                count += upper_bound(row.begin(), row.end(), mid) - row.begin();

            if (count <= target) 
                low = mid + 1;   // need bigger value
            else 
                high = mid - 1;  // too many small values
        }
        return low;  // median
    }
};

int main() {
    Solution sol;

    vector<vector<int>> matrix = {
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}
    };

    int R = matrix.size();
    int C = matrix[0].size();

    cout << "The median is: " << sol.median(matrix, R, C) << endl;

    return 0;
}
