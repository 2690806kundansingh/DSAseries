//find max and min in an array
#include<iostream>
using namespace std;
int getmax(int arr[],int n){
    int maxi=INT_MINI;
    for(int i=0;i<n;i++){
        maxi=max(maxi,arr[i]);
        return maxi;
    }
int getmin(int arr[],int n){
    int mini=INT_MAX;
    for(int i=0;i<n;i++){
      mini=min(mini,arr[i]);
      return mini;  
    }
}    
}
int main(){
    int n;
    cin>>n; 
    int arr[100];
    //taking input
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"maximum element"<<getmax(arr,n)<<" ";
    cout<<"minimum element"<<getmin(arr,n)<<" ";

}