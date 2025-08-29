#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    long long FindSubarray(vector<int>& nums, int n){
        unordered_map<long long, int> mp;
        long long sum = 0;
        long long ans = 0;
        mp[0] = 1;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            // Corrected condition
            if(mp.find(sum) != mp.end()){ 
                ans += mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {6, -1, -3, 4, -2, -2, 4, 6, -12, -7};
    Solution obj;

    long long result = obj.FindSubarray(nums, 10);
    cout << "The count of subarrays with sum equal to 0 is: " << result << endl;
    return 0;
}
