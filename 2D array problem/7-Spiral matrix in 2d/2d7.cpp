// #include<iostream>
// #include<vector>
// using namespace std;

// class solution{
//     public:
//     vector<int>spiralorder(vector<vector<int>>&matrix){
//         vector<int>ans;
//         int row=matrix.size();
//         int col=matrix[0].size();

//         int count=0;
//         int total=row*col;
//         //index intialise
//         int startingrow=0;
//         int startingcol=0;
//         int endingrow=row-1;
//         int endingcol=col-1;
//         while(count<total){
//             //print starting row
//             for(int index=startingcol;count<total&&index<=endingcol;index++){
//                 ans.push_back(matrix[startingrow][index]);
//                 count++;
//             }
//                 startingrow++;
//             //printing ending column
//             for(int index=startingrow;count<total&&index<=endingrow;index++){
//                 ans.push_back(matrix[index][endingcol]);
//                  count++;
//             } 
//             endingcol--;
//             //print ending row
//             for(int index=endingcol;count<total&&index>=startingcol;index--){
//                 ans.push_back(matrix[endingrow][index]);
//                  count++;
//             } 
//             endingrow--;
//             //print stating col
//             for(int index=endingrow;count<total&&index>=startingrow;index--){
//                 ans.push_back(matrix[index][startingcol]);
//                  count++;
//             } 
//             startingcol++; 
//         }
//         return ans;
//     }
// };

#include<iostream>
#include<vector>
using namespace std;

class solution{
public:
    vector<int> spiralorder(vector<vector<int>>& matrix){
        vector<int> ans;                // will store elements in spiral order
        int row = matrix.size();        // total rows
        int col = matrix[0].size();     // total columns (assumes matrix is non-empty)

        int count = 0;                  // how many elements we have pushed so far
        int total = row * col;          // total number of elements

        // boundary indices
        int startingrow = 0;            // top boundary
        int startingcol = 0;            // left boundary
        int endingrow = row - 1;        // bottom boundary
        int endingcol = col - 1;        // right boundary

        while (count < total) {
            // 1) traverse the top row from left -> right
            for (int index = startingcol; count < total && index <= endingcol; index++) {
                ans.push_back(matrix[startingrow][index]);
                count++;
            }
            startingrow++; // top boundary moves down

            // 2) traverse the right column from top -> bottom
            for (int index = startingrow; count < total && index <= endingrow; index++) {
                ans.push_back(matrix[index][endingcol]);
                count++;
            }
            endingcol--; // right boundary moves left

            // 3) traverse the bottom row from right -> left
            for (int index = endingcol; count < total && index >= startingcol; index--) {
                ans.push_back(matrix[endingrow][index]);
                count++;
            }
            endingrow--; // bottom boundary moves up

            // 4) traverse the left column from bottom -> top
            for (int index = endingrow; count < total && index >= startingrow; index--) {
                ans.push_back(matrix[index][startingcol]);
                count++;
            }
            startingcol++; // left boundary moves right
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C;
    cout << "Enter rows and cols: ";
    if (!(cin >> R >> C) || R <= 0 || C <= 0) {
        cout << "Invalid size\n";
        return 0;
    }

    vector<vector<int>> matrix(R, vector<int>(C));
    cout << "Enter " << R * C << " elements:\n";
    for (int i = 0; i < R; ++i)
        for (int j = 0; j < C; ++j)
            cin >> matrix[i][j];

    solution s;
    vector<int> res = s.spiralorder(matrix);

    cout << "Spiral order: ";
    for (size_t i = 0; i < res.size(); ++i) {
        if (i) cout << ' ';
        cout << res[i];
    }
    cout << '\n';
    return 0;
}
