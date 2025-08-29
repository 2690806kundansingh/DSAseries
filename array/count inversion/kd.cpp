//  #include<iostream>
// using namespace std;

// int inversioncount=0;
// void merge(int arr[],int s,int e){
//     int mid=(s+e)/2;
//     int len1=mid-s+1;
//     int len2=e-mid; 
//     //create an array
//     int *first=new int(len1);
//     int *second=new int(len2);
//     //copy value
//     //copy first
//     int k=s;
//     for(int i=0;i<len1;i++){
//         first[i]=arr[k++];
//     }
//     //copy second
//      k=mid+1;
//     for(int i=0;i<len2;i++){
//         second[i]=arr[k++];
//     }
//     //merge two array
//     int index1=0;
//     int index2=0;
//     k=s;

//     while(index1<len1&&index2<len2){
//         if(first[index1]<second[index2]){
//             arr[k++]=first[index1];
//         }
//         else{
//             arr[k++]=second[index2];
//             //count inversion
//             inversioncount += len1 - index1;
//         }

//     }
//     while(index1<len1){
//         arr[k++]=first[index1++];
//     }
//     while(index2<len2){
//         arr[k++]=second[index2++];
//     }
//     delete[]first;
//     delete[]second;
// }
// void mergesort(int arr[],int s,int e){
//     //base case
//     if(s>=e){
//         return;
//     }
//     int mid=(s+e)/2;
//     //sort the left part
//     mergesort(arr,s,mid);
//     //sort the right part
//     mergesort(arr,mid+1,e);
//     //merge
//     merge(arr,s,e);
// }
// int main(){
//     int arr[]={3,5,6,9,1,2,7,8};
//     int n=sizeof arr/sizeof arr[0];
//     int inversioncount=0;
//     mergesort(arr,0,n-1);
//     //print
//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<endl;
//     }
//     //print inversion count
//     cout<<"inversion count"<<inversioncount<<" ";
//     return 0;
// }






#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int mergeAndCount(vector<int>& arr, int left, int mid, int right) {
        vector<int> temp;
        int i = left, j = mid + 1, inv_count = 0;

        while (i <= mid && j <= right) {
            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } else {
                temp.push_back(arr[j++]);
                inv_count += (mid - i + 1); // Count inversions
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }

        return inv_count;
    }

    int mergeSortAndCount(vector<int>& arr, int left, int right) {
        if (left >= right) return 0;
        
        int mid = (left + right) / 2;
        int inv_count = 0;

        inv_count += mergeSortAndCount(arr, left, mid);
        inv_count += mergeSortAndCount(arr, mid + 1, right);
        inv_count += mergeAndCount(arr, left, mid, right);

        return inv_count;
    }

    int countInversions(vector<int>& arr) {
        return mergeSortAndCount(arr, 0, arr.size() - 1);
    }
};

int main() {
    vector<int> arr = {8, 4, 2, 1};
    Solution solution;
    cout << "Inversion Count: " << solution.countInversions(arr) << endl;
    return 0;
}




