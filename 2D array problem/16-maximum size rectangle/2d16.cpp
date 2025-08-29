#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> nextSmaller(vector<int>& arr) {
        stack<int> s;
        s.push(-1);

        int n = arr.size();
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int item = arr[i];

            while (s.top() != -1 && arr[s.top()] >= item) {
                s.pop();
            }
            // Push in ans
            if (s.top() == -1)
                ans[i] = n;
            else
                ans[i] = s.top();

            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmaller(vector<int>& arr) {
        stack<int> s;
        s.push(-1);

        int n = arr.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // Ans is stack's top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestArea(vector<int>& arr) {
        vector<int> prevSmallerArr = prevSmaller(arr);
        vector<int> nextSmallerArr = nextSmaller(arr);

        int maxArea = INT_MIN;

        for (int i = 0; i < arr.size(); i++) {
            int length = arr[i];
            int breadth = nextSmallerArr[i] - prevSmallerArr[i] - 1;
            int newArea = length * breadth;
            maxArea = max(maxArea, newArea);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;

        int maxRect = 0;
        vector<int> histogram(matrix[0].size(), 0);

        // to create histogram array
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < histogram.size(); j++) {
                if (matrix[i][j] == '1')
                    histogram[j]++;
                else
                    histogram[j] = 0;
            }
            maxRect = max(maxRect, largestArea(histogram));
        }
        return maxRect;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    cout << sol.maximalRectangle(matrix) << endl;

    return 0;
}
