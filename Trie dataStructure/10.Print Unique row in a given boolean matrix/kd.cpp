#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<vector<int>> uniqueRow(int M[][100], int row, int col) {
        unordered_map<string, bool> map;
        vector<vector<int>> ans;

        for (int i = 0; i < row; i++) {
            string s = "";
            vector<int> temp;

            for (int j = 0; j < col; j++) {
                s += to_string(M[i][j]) + ","; // use comma to avoid confusion
                temp.push_back(M[i][j]);
            }

            if (!map[s]) {
                map[s] = true;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};
