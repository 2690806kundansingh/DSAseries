// #include<iostream>
// #include<unordered_map>
// #include<vector>
// using namespace std;

// class Solution{
//     public:
//     int longestSubarrayWithKDistinct(vector<int>&arr,int k){
//         int n = arr.size();
//         unordered_map<int,int>mp;
//         int l=0;
//         int r = 0;
//         int maxlen = 0;

//         while(r < n){
//             mp[arr[r]]++;
//             if(mp.size() > k){
//                 mp[arr[l]]--;
//             }
//             if(mp[arr[l]] == 0){
//                 mp.erase(arr[l]);
//                 l++;
//             }
//             if(mp.size() <= k){
//                 maxlen = max(maxlen,r-l+1);
//                 r++;
//             }
//             return maxlen;
//         }
//     }
// };
// int main(){
//     Solution obj;
//     vector<int>arr = {3,3,3,1,2,1,1,2,3,3,4};
//     int k = 2;
//     cout<<"The LongestSubarrayWithkDistinct:"<<obj.longestSubarrayWithKDistinct(arr,k)<<" ";
//     return 0;
// }



#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int longestSubarrayWithKDistinct(vector<int>& arr, int k) {
    unordered_map<int, int> mpp; // Map to store frequency of elements
    int l = 0, r = 0, maxlen = 0;

    while (r < arr.size()) {
        mpp[arr[r]]++;  // Increment frequency of right pointer element
        
        while (mpp.size() > k) { // If more than k distinct elements
            mpp[arr[l]]--;  // Decrease frequency of leftmost element
            if (mpp[arr[l]] == 0) {
                mpp.erase(arr[l]); // Remove element if count becomes 0
            }
            l++; // Move left pointer
        }
        
        maxlen = max(maxlen, r - l + 1); // Update max length
        r++; // Move right pointer
    }
    
    return maxlen;
}

int main() {
    vector<int> arr = {1, 2, 1, 2, 3}; 
    int k = 2;
    cout << "Longest subarray length: " << longestSubarrayWithKDistinct(arr, k) << endl;
    return 0;
}




// class Solution {
//     public:
//         int totalFruit(vector<int>& fruits) {
//             unordered_map<int, int> mp;
//             int l = 0, maxlen = 0;
//             int k = 2;  // Only 2 types of fruits allowed
    
//             for (int r = 0; r < fruits.size(); r++) {
//                 mp[fruits[r]]++;  // Add the fruit type
    
//                 while (mp.size() > k) {  // More than 2 fruit types
//                     mp[fruits[l]]--;
//                     if (mp[fruits[l]] == 0) {
//                         mp.erase(fruits[l]);
//                     }
//                     l++;  // Move left pointer
//                 }
    
//                 maxlen = max(maxlen, r - l + 1);  // Update the max window size
//             }
    
//             return maxlen;
//         }
//     };