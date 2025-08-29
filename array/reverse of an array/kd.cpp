#include<iostream>
using namespace std;
int main(){
    int arr[]={2,5,7,9,4,6,7};
    int n=sizeof arr/sizeof arr[0];
    for(int i=n-1;i>=0;i--){
        cout<<arr[i]<<" ";
    }
}