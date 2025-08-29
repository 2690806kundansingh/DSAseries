class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        // 1) handle empty input
        if (matrix.empty() || matrix[0].empty()) 
            return {};

        // 2) dimensions
        int m = matrix.size();
        int n = matrix[0].size();

        // 3) answer vector and pointer
        vector<int> result(m * n);
        int idx = 0;   // index where we write next

        // 4) starting position and direction
        int row = 0, col = 0;
        bool up = true;  // true = moving up-right, false = moving down-left

        // 5) traverse until we've written all elements
        while (idx < m * n) {
            result[idx++] = matrix[row][col];   // put current element

            if (up) { // moving up-right
                if (col == n - 1) {      // hit last column → move down
                    row++;
                    up = false;
                } else if (row == 0) {   // hit top row → move right
                    col++;
                    up = false;
                } else {                 // normal up-right step
                    row--;
                    col++;
                }
            } else {   // moving down-left
                if (row == m - 1) {      // hit last row → move right
                    col++;
                    up = true;
                } else if (col == 0) {   // hit first column → move down
                    row++;
                    up = true;
                } else {                 // normal down-left step
                    row++;
                    col--;
                }
            }
        }

        return result;
    }
};

/*
};
ChatGPT said:
Thought for 31s

Nice — below is a clear, line-by-line explanation of your C++ solution, plus a short example and a few final notes (complexity and a small optimization suggestion).

Line-by-line explanation
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> result;
        if (mat.empty()) return result;


vector<int> result; — create the vector that will hold the final traversal order.

if (mat.empty()) return result; — quick guard: if matrix has 0 rows, return an empty result immediately.

        int m = mat.size();
        int n = mat[0].size();


int m = mat.size(); — number of rows.

int n = mat[0].size(); — number of columns (safe here because we already checked mat is non-empty).

        map<int, vector<int>> diagonals;


map<int, vector<int>> diagonals; — a std::map keyed by i + j (the diagonal index).

std::map is ordered by key, so when we iterate the map later, diagonals will come out in increasing diagonal index order (0, 1, 2, ...).

Each vector<int> stores the elements that lie on that diagonal.

        // Populate the map with diagonal entries
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                diagonals[i + j].push_back(mat[i][j]);
            }
        }


Outer loop for (int i = 0; i < m; ++i) iterates rows.

Inner loop for (int j = 0; j < n; ++j) iterates columns.

diagonals[i + j].push_back(mat[i][j]);

i + j is the diagonal index: all cells with equal i + j lie on the same diagonal.

For each cell (i,j) we append mat[i][j] to the vector for that diagonal.

Because we loop i outer then j inner, every diagonal's vector ends up ordered by increasing i (top → bottom along that diagonal).

        // Collect the diagonals in order
        for (auto& pair : diagonals) {
            vector<int>& diagonal = pair.second;
            if ((pair.first % 2) == 0) {
                // Even diagonal index: reverse the elements to match zigzag order
                reverse(diagonal.begin(), diagonal.end());
            }
            result.insert(result.end(), diagonal.begin(), diagonal.end());
        }


for (auto& pair : diagonals) — iterate map entries in ascending key order. Each pair has pair.first = diagonal index and pair.second = vector of elements on that diagonal.

vector<int>& diagonal = pair.second; — create a reference to the current diagonal vector for readability.

if ((pair.first % 2) == 0) — check if the diagonal index is even.

In the standard diagonal zigzag order used by the problem, even-numbered diagonals are traversed in the opposite direction to how we appended elements. Since we appended top→bottom, we must reverse even diagonals to get the correct zigzag order.

reverse(diagonal.begin(), diagonal.end()); — reverse the vector in place when needed.

result.insert(result.end(), diagonal.begin(), diagonal.end()); — append all elements from this diagonal to the final result vector.

        return result;
    }
};


After processing every diagonal in order, return the result vector containing the matrix elements in diagonal zigzag order.
*/