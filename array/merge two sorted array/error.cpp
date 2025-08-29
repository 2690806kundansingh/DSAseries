#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
    int mid=(s+e)/2;
    //create a two array
    int len1=mid-s+1;
    int len2=e-mid;

    int *first=new int(len1);
    int *second=new int(len2);
    //copy value s to mid
    int k=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[k++];
    }
    //copy value second mid+1
    //where k is main arr index

     k=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[k++];
    }

    //merge two sorted array
    int index1=0;
    int index2=0;
    k=s;
    while(index1<len1&&index2<len2){
        if(first[index1]<second[index2]){
            arr[k++]=first[index1];
        }
        else{
            arr[k++]=second[index2];
        }
    }
    while(index1<len1){
        arr[k++]=first[index1++];
    }
    while(index2<len2){
        arr[k++]=second[index2++];
    }
    delete[]first;
    delete[]second;

}
void mergesort(int arr[],int s,int e){
    //base case
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    //left wale ko sort kardo
    mergesort(arr,s,mid);
    //right ko sort kardo
    mergesort(arr,mid+1,e);
    //merge
    merge(arr,s,e);
}
    

int main(){
    int arr[]={2,5,1,0,9};
    int n=sizeof arr/sizeof arr[0];
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    return 0;

}