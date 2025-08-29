// // brute force
// #include <bits/stdc++.h>
// vector<vector<int>> foursum(vector<int> &num, int target)
// {
//     int n = num.size();
//     set < vrctor<int> st;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//             {
//                 for (int l = k + 1; l < n; l++)
//                 {
//                     long long sum = num[i] + num[j];
//                     sum = num[j] + num[k];
//                     sum = num[k] + num[l];
//                     if (sum == target)
//                     {
//                         vector<vector<int>> temp = {num[i], num[j], num[k], num[l]};
//                         sort(temp.begin(), temp.end());
//                         st.insert(temp);
//                     }
//                 }
//             }
//         }
//     }
//     vector<vector<int>> ans(st.begin().st.end());
//     return ans;
// }



//optimal codition
// #include<bits/stdc++.h>
// #include<vector>
// using namespace std;

// class Solution{
//     public:
//     vector<vector<int>> forsum(vector<int>&nums,int target){
//         int n=nums.size();
//         vector<vector<int>>ans;
//         sort(nums.begin(),nums.end());
//         for(int i=0;i<n;i++){
//             //check equvalenece condition
//             if(i>0&&nums[i]==nums[i-1])
//               continue;
//             for(int j=i+1;j<n;j++){
//                 if(j!=(i+1)&&nums[j]==nums[j-1])
//                 continue;
//                 int k=j+1;
//                 int l=n-1;
//                 //cross condition
//                 while(k<l){
//                     long long sum=nums[i];
//                     sum=sum+nums[j];
//                     sum=sum+nums[k];
//                     sum=sum+nums[k];
//                     if(sum==target){
//                         vector<int>temp={nums[i],nums[j],nums[k],nums[l]}; 
//                         ans.push_back(temp);
//                         k++;
//                         l--;
//                         // cross all the duplicate
//                         while(k<l&&nums[k]==nums[k-1]) k++;
//                         while(k<l&&nums[l]==nums[l-1]) l--;
//                     }
//                     else if(sum<target) k++;
//                     else l--;
//                 }
//             }  
//         }
//         return ans;
//     }
// };



#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>>forsum(vector<int>&nums,int target){
    
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());

        for(int i =0; i< n; i++){
            if(i>0 && nums[i] == nums[i-1])
            continue;
            for(int j = i+1 ; j<n; j++){
                if(j!= (i+1) && nums[j] == nums[j-1])
                  continue;

                int k = j+1;
                int l = n-1;
                
                while(k<l){
                    long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target){
                        vector<int>temp = {nums[i],nums[j],nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        l--;

                        while(k<l && nums[k] == nums[k-1])
                           k++;
                        while(k<l && nums[l] == nums[l-1])
                           l--;
                    }
                    else if(sum < target){
                        k++;
                    }
                    else{
                        l--;
                    }
                }
            }
        }

        return ans;
    }
};

int main(){
    vector<int>nums = {1,0,-1,0,-2,2};
    Solution obj;
    vector<vector<int>>result = obj.forsum(nums,0);
    
    for (auto vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;

}
