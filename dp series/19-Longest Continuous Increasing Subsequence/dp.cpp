#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxLen = 1;  
        int currLen = 1;  

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) {
                currLen++;  // extend the streak
            } else {
                currLen = 1; // reset streak
            }
            maxLen = max(maxLen, currLen);
        }
        return maxLen;
    }
};

int main() {
    Solution s;
    vector<int> nums1 = {1, 3, 5, 4, 7};
    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << s.findLengthOfLCIS(nums1) << endl; // Output: 3
    cout << s.findLengthOfLCIS(nums2) << endl; // Output: 1
}
