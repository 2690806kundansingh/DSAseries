#include<iostream>
#include<vector>
using namespace std;
 
class Solution {
public:
    int solve(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = 0, prev1 = nums[0]; 
        for (int i = 1; i < n; i++) {
            int incl = prev2 + nums[i]; // rob this house
            int excl = prev1;           // skip this house
            int curr = max(incl, excl);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> first, second;
        for (int i = 0; i < n; i++) {
            if (i != n - 1) first.push_back(nums[i]);  // exclude last house
            if (i != 0) second.push_back(nums[i]);     // exclude first house
        }

        return max(solve(first), solve(second));
    }
};
