#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int longestOnes(vector<int>& nums, int k) {
            int n = nums.size();
            int l = 0, r = 0, zero = 0, maxlen = 0;
    
            while (r < n) {
                if (nums[r] == 0) {
                    zero++;
                }
    
                // If zero count exceeds k, shrink the window from the left
                while (zero > k) {
                    if (nums[l] == 0) {
                        zero--;
                    }
                    l++;  // Move left pointer to balance the window
                }
    
                // Calculate the maximum length
                maxlen = max(maxlen, r - l + 1);
                
                r++;  // Move right pointer
            }
    
            return maxlen;  // Return the longest length found
        }
    };
    

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 0, 1, 1};  
    int k = 2;
    cout << "Maximum consecutive 1s (with at most " << k << " zeroes flipped): " << sol.longestOnes(nums, k) << endl;
    return 0;
}
