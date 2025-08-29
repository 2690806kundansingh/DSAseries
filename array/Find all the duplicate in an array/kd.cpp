#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> seen;
        vector<int> duplicates; // To store duplicates
        
        for (int i = 0; i < n; i++) {
            if (seen.find(nums[i]) != seen.end()) {
                duplicates.push_back(nums[i]); // Store duplicate instead of printing
            } else {
                seen.insert(nums[i]);
            }
        }
        return duplicates; // Return the vector of duplicates
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
    
    vector<int> result = sol.findDuplicates(nums);
    
    cout << "Duplicate elements: ";
    for (int num : result) {
        cout << num << " ";
    }

    return 0;
}




// #include<bits/stdc++.h>
// using namespace std;

// void FindDuplicate(int arr[],int n){
//     sort(arr,arr+n);
//     int  i = 0;
//     cout<<"Duplicate"<<" ";
//     while(i<n-1){
//         if(arr[i] == arr[i+1]){
//             cout<<arr[i];
//             //skip the duplication
//             while(i<n-1 && arr[i] == arr[i+1]){
//                 i++;
//             }
//         }
//         i++;//move to the next unique element
//     }

// }

// int main(){
//     int arr[] = {1,3,4,2,2,3,5,6,1};
//     int n = sizeof(arr)/sizeof(arr[0]);

//     FindDuplicate(arr,n);
//     return 0;
// }