// #include<iostream>
// #include<queue>
// #include<vector>

// using namespace std;

// //using heap
// class Sollution{
//     public:

//     vector<int>mergeKArray(vector<vector<int>>arr,int k){
       
//         vector< pair<int,pair<int,int>>>temp;
//         for(int i = 0; i<k; i++){
//             temp.push_back(make_pair(arr[i][0],make_pair(i,0)));
//         }
//         //creating a min heap
//         priority_queue< pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>>p(temp.begin(),temp.end());
//         //push data row and column in queue

//         vector<int>ans; // which store the sorted array

//         pair<int,pair<int,int>>Element;
//         int i;
//         int j;
//         while(!p.empty()){
//             Element = p.top();
//             p.pop();
//             ans.push_back(Element.first);
//             i = Element.second.first;
//             j = Element.second.second;

//             if(j+1 < k){
//                 p.push(make_pair(arr[i][j+1],make_pair(i,j+1)));
//             }
//         }
//         return ans;
//     }
// };





//using merge short
#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:

    void merge(vector<int>&arr,int start,int mid,int end){
        vector<int>temp(end-start + 1);
        int left = start,right = mid +1,index = 0;

        while(left <= mid && right<= end){
            if(arr[left] <= arr[right]){
                temp[index]= arr[left];
                index++,left++;
            }
            else{
                temp[index] = arr[right];
                index++,right++
            }
        }
        //left array is not empty yet
        while(left <= mid){
            temp[index] = arr[left];
            index++,right++;
        }
        index = 0;
        //put theese value in array
        while(start <= end){
            arr[start] = temp[index];
            start++,index++;
        }
    }
    void mergesort(vector<int>&arr,int start,int end,int portion ,int k){
        
        if(portion < 2)
           return;

        int mid = start + (portion/2) *k-1;
        //left side
        mergesort(arr,start,end,portion/2,k);
        //right side
        mergesort(arr,mid+1,end , portion-portion/2,k);
        merge(arr,start,mid,end);

    }
    vector<int>mergeKArrays(vector<vector<int>>arr,int k){
        //merge short
        vector<int>ans;
        for(int i = 0; i<k ; i++)
        for(int j = 0;j<k; j++){
            ans.push_back(arr[i][j]);
        }
        mergesort(ans,0,ans.size()-1 k,k);
        return ans;
    }
};