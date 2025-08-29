#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> TwoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> indexedNums;  // Store {value, index}

        // Store elements with their original indices
        for (int i = 0; i < n; i++) {
            indexedNums.push_back({nums[i], i});
        }

        // Sort based on values
        sort(indexedNums.begin(), indexedNums.end());

        int left = 0, right = n - 1;
        
        while (left < right) {
            int sum = indexedNums[left].first + indexedNums[right].first;
            
            if (sum == target) {
                return {indexedNums[left].second, indexedNums[right].second}; // Return original indices
            }
            else if (sum < target) left++;
            else right--;
        }

        return {}; // Return empty vector if no solution is found
    }
};

int main() {
    vector<int> nums = {2, 5, 6, 8, 11};
    Solution obj;
    
    vector<int> ans = obj.TwoSum(nums, 14);
    
    if (!ans.empty()) {
        cout << "Indices: " << ans[0] << ", " << ans[1] << endl;
    } else {
        cout << "No solution found!" << endl;
    }

    return 0;
}
