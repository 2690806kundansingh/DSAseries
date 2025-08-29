// //chocolate distribution problem
// //java
// class solution{
//     public long findindiff(arraylist<integer>a,int n,int m){
//         if(a.size()==0){
//             return 0;
//         }
//         collection.sort(a);
//         long res=long.Max_Value;
//         for(int i=0;i<n-m+1;i++){
//             int minelement=a.get(i);
//             int maxelement=a.get(i+m-1);
//             res=math.min(res,maxelement-minelement);
//         }
//         return res;
//     }
// }


//in c++
#include<bits/stdc++.h>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    long findindiff(vector<int>&a,int n,int m){
        if(a.size()==0){
            return 0;
        }
        sort(a.begin(),a.end());
        int res = INT_MAX;
        // long res=numeric_limit<long>max();
        for(int i=0 ;i<n-m+1;i++){
            int minelement=a[i];
            int maxelement=a[i+m-1];
            res=min(res,maxelement-minelement);
        }
        return res;
    }
};
int main(){
    vector<int>a = {3,4,1,9,56,7,9,12};
    int n = 8;
    int m = 4;
    Solution obj;
    int result = obj.findindiff(a,n,m);
    cout<<"This is the chocolate distribution :"<<result << endl;
    return 0;

}