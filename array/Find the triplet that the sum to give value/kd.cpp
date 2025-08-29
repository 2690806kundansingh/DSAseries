// //find the triplet sum
// //first method O(n^3)
// // #include<bits/stdc++.h>
// // vector<vector<int>>triplet(int n,vector<int>&num){
    
// //     st<vector<int>>st;

// //     for(int i=0;i<n;i++){
// //         for(int j=i+1;j<n;j++){
// //             for(int k=j+1;j<n;j++){
// //                 if(num[i]+num[j]+num[k]==0)
// //                 //store unique element
// //                 vector<int>temp={num[i],num[j],num[k]};
// //                 sort(temp.begin(),temp.end());
// //                 st.insert(temp);    
// //             }
// //         }
// //     }
// //     vector<vector<int>>ans(st.begin(),st.end());
// //     return ans;
// // }


// //second method O(n^2)
// #include<bits/stdc++.h>
// vector<vector<int>>triplet(int n,vector<int>&num){
//     set<vector<int>>st;
//     for(int i=0;i<n;i++){
//         //for i on next step
//         set<int>hashset;
//         for(int j=i+1;i<n;i++){
//             int third=-(num[i]+num[j]);
//             if(hashest.find(third)!=hashset.end()){
//                 vector<int>temp={num[i],num[j],third};
//                 sort(temp.begin(),temp.end());
//                 st.insert(temp);
//             }
//             hashset.insert(num[j]);
//         }
//     }
//     vector<vector<int>>ans(st.begin(),st.end);
//         return ans;
// }


//third optimal aproach
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>>triplet(vector<int>&num){
        int n = num.size();
        vector<vector<int>>ans;
        sort(num.begin(),num.end());
        for(int i=0;i<n;i++){
            //eqvivalent codition
            if(i>0&&num[i]==num[i-1])//skip duplication
             continue;
            //equivalent codintion j andk
            int j=i+1;
            int k=n-1;
            //cross codition
            while(j<k){
                int sum= num[i]+num[j]+num[k];
                if(sum<0){
                    j++;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    //we got equal condtion means we get triplet
                    vector<int>temp={num[i],num[j],num[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    while(j<k&&num[j]==num[j-1])
                        j++;
                    while(j<k&&num[k]==num[k-1])
                        k--;    
                }
            }
        }
        return ans;
    }
};

int main(){
    vector<int>num = {-1,0,1,2,-1,-4};
    Solution obj;

    vector<vector<int>>result = obj.triplet(num);

    for (auto vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
    }
    return 0;
}
