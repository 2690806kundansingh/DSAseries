#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int>FindIntersection(vector<int>&arr1,int n,vector<int>&arr2,int m){
        vector<int>ans;
        int i = 0;
        int j =0;
        while(i<n && j<m){
            if(arr1[i] == arr2[j]){
                ans.push_back(arr1[i]);
                i++;
                j++;
            }
            else if(arr1[i] < arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    vector<int>arr1 = {1,2,2,2,3,4};
    vector<int>arr2 = {2,2,3,3};

    vector<int>result = obj.FindIntersection(arr1,arr1.size(),arr2,arr2.size());
    cout<<"Intersection";

    for(int num:result){
        cout<<num;
    }
    cout<<endl;
    return 0;

}





// Insert all elements from nums1 into an unordered set (set1).

// Iterate over nums2 and check if each element exists in set1. If yes, store it in resultSet to avoid duplicates.

// Convert resultSet into a vector and return it.

// Why This Fixes TLE:
// Avoids sorting: Sorting takes O(n log n + m log m), which is slow.

// Direct lookup: Using unordered_set allows O(1) average time complexity per lookup.

// No duplicates: unordered_set ensures unique elements in the result.

// This should efficiently handle large inputs without exceeding the time limit. 🚀


class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            if (nums1.empty() || nums2.empty()) return {};  // Edge case handling
    
            unordered_set<int> set1(nums1.begin(), nums1.end());  // Corrected line
            unordered_set<int> resultset;
    
            for (int num : nums2) {
                if (set1.count(num)) {
                    resultset.insert(num);
                }
            }
    
            return vector<int>(resultset.begin(), resultset.end());
        }
    };
    