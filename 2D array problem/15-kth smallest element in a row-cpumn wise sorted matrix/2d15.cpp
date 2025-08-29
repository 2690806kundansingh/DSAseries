//kth smallest element in a row-cpumn wise sorted matrix
#include <iostream>      // for input/output (cout)
#include <vector>        // for std::vector (matrix storage)
#include <queue>         // for std::priority_queue (heap)
using namespace std;     // avoid std:: prefix for brevity

// We will find the kth smallest element in a row- and column-wise sorted matrix
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();  // n = number of rows (and columns, since matrix is n x n)
        
        // Min-heap that stores triples as a vector<int> = {value, row, col}
        // Using 'greater<>' turns priority_queue into a min-heap (smallest value at top)
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;
        
        // Step 1: push the first element of every row into the heap.
        // Because each row is sorted, the first element is the smallest in its row.
        for (int i = 0; i < n; i++) {
            // push {value at (i,0), row index i, column index 0}
            minHeap.push({matrix[i][0], i, 0});
        }

        int ans = -1;  // will hold the kth popped (i.e., kth smallest) value

        // Step 2: pop the smallest element k times
        while (k--) {                           // repeat k times
            auto top = minHeap.top();           // get the smallest item (value, row, col)
            minHeap.pop();                      // remove it from the heap
            ans = top[0];                       // record its value as the latest candidate
            int row = top[1], col = top[2];     // unpack row and column where it came from

            // Step 3: push the next element from the same row (if it exists)
            // Since rows are sorted, the next column holds the next bigger candidate from this row.
            if (col + 1 < n) {
                minHeap.push({matrix[row][col + 1], row, col + 1});
            }
        }

        // After k pops, 'ans' is the kth smallest element
        return ans;
    }
};

int main() {
    // Example input
    vector<vector<int>> matrix = {
        {1, 5, 9},
        {10, 11, 13},
        {12, 13, 15}
    };
    int k = 8;  // we want the 8th smallest element

    Solution s;                                       // create Solution object
    cout << "Kth Smallest = " << s.kthSmallest(matrix, k) << endl; // print result
    return 0;                                         // success
}

// #include<iostream>
// #include<vector>
// #include<queue>
// using namespace std;

// class Solution{
//     public:
//     int kthSmallest(vector<vector<int>>&matrix,int k){
//         int n = matrix.size();
//         //step 1 crete a proiority queue
//         priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>minheap;

//         //step2 push all the first element of every row in heap
//         for(int i= 0;i<matrix.size();i++){
//             minheap.push({matrix[i][0],i,0});
//         }
//         int ans = -1;
//         //step 3 pop k size element from the heap
//         while(k--){
//             auto top = minheap.top();
//             minheap.pop();
//             ans = top[0];

//             int row = top[1];
//             int col = top[2];

//             //step push the next element from the same row
//             if(col +1 < n)
//                 minheap.push({matrix[row][col+1],row,col+1});
//         }
//         return ans;
//     }
// }