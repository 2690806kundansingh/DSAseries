// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// class Solution {
// public:
//     int SubarrayWithDifferentInte(vector<int>& nums, int k) {
//         unordered_map<int, int> mp;
//         int l = 0;
//         int r = 0;
//         int cnt = 0;

//         while (r < nums.size()) {
//             mp[nums[r]]++;

//             while (mp.size() > k) {  // Fixed condition (was <=)
//                 mp[nums[l]]--;

//                 if (mp[nums[l]] == 0) {
//                     mp.erase(nums[l]);
//                 }
//                 l = l + 1;  // Fixed increment (was l - 1)
//             }
//             cnt = cnt + (r - l + 1);
//             r++;
//         }
//         return cnt;
//     }
// };

// int main() {
//     Solution obj;
//     vector<int> nums = {2, 1, 1, 1, 3, 4, 3, 2};
//     int k = 3;
//     cout << "Subarray with different integer: " << obj.SubarrayWithDifferentInte(nums, k) << endl;
//     return 0;
// }


#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // This function remains unchanged
    int subarraysWithAtMostKDistinct(vector<int>& nums, int k) {
        if (k == 0) return 0;
        unordered_map<int, int> mp;
        int l = 0, r = 0, cnt = 0;

        while (r < nums.size()) {
            mp[nums[r]]++;

            while (mp.size() > k) {  // Shrink the window if distinct elements exceed k
                mp[nums[l]]--;
                if (mp[nums[l]] == 0) {
                    mp.erase(nums[l]);
                }
                l++;
            }
            cnt += (r - l + 1);
            r++;
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarraysWithAtMostKDistinct(nums, k) - subarraysWithAtMostKDistinct(nums, k - 1);
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 1, 2, 3};
    int k = 2;
    cout << "Subarrays with exactly " << k << " different integers: " 
         << obj.subarraysWithKDistinct(nums, k) << endl;
    return 0;
}
