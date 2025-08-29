#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            vector<int> oddIndices = {-1};  // Store indices of odd numbers, start with -1
        int count = 0;
        
        // Store the indices of all odd numbers
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 1) {
                oddIndices.push_back(i);
            }
        }
        oddIndices.push_back(nums.size());  // Append the size of the array

        // Count subarrays using odd indices
        for (int i = 1; i + k < oddIndices.size(); i++) {
            int leftChoices = oddIndices[i] - oddIndices[i - 1];  // Ways to pick left part
            int rightChoices = oddIndices[i + k] - oddIndices[i + k - 1];  // Ways to pick right part
            count += leftChoices * rightChoices;
        }

        return count;
    }
};