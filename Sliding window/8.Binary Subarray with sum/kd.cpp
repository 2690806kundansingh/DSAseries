#include <iostream>
#include <list>

using namespace std;

class Solution {
public:
    int binarySubarrayWithSum(list<int>& nums, int goal) {
        int sum = 0, cnt = 0;
        auto left = nums.begin();  // Iterator for left pointer
        auto right = nums.begin(); // Iterator for right pointer

        while (right != nums.end()) {
            sum += *right;

            while (sum > goal && left != right) {  
                sum -= *left;
                left++;
            }

            if (sum == goal) cnt++;

            right++;
        }

        return cnt;
    }
};

int main() {
    list<int> nums = {1, 0, 1, 0, 1};
    int goal = 2;
    
    Solution sol;
    cout << "Number of subarrays with sum " << goal << ": " << sol.binarySubarrayWithSum(nums, goal) << endl;

    return 0;
}



// class Solution {
//     public:
//         int numSubarraysWithSum(vector<int>& nums, int goal) {
//             unordered_map<int, int> prefixSumCount;
//             prefixSumCount[0] = 1;  // Base case: sum 0 exists once
    
//             int sum = 0, count = 0;
//             for (int num : nums) {
//                 sum += num;  // Update current prefix sum
                
//                 if (prefixSumCount.find(sum - goal) != prefixSumCount.end()) {
//                     count += prefixSumCount[sum - goal];  // Count valid subarrays
//                 }
    
//                 prefixSumCount[sum]++;  // Store current prefix sum occurrence
//             }
//             return count;
//         }
//     };
    