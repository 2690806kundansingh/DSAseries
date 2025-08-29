#include<iostream>
#include<vector>
using namespace std;

void MinHeapify(vector<int>&arr,int n,int i){
    int smallest  = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[smallest] < arr[i]){
        smallest = left;
    }
    if(right < n && arr[smallest] < arr[i]){
        smallest = right;
    }
    if(smallest != i){
        swap(arr[smallest],arr[i]);
        MinHeapify(arr,n,smallest);
    }
}
vector<int>BuildMinHeap(vector<int>&arr){
    int n = arr.size();
    for(int i = i/2-1; i>=0 ; i--){
        MinHeapify(arr,n,i);
    }
    return arr;

}