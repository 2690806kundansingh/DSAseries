//fint the union and intersection of two sorted array

#include<iostream>
using namespace std;
//to find union
void print_union(int arr1[],int arr2[],int m,int n){
    int i=0;
    int j=0;
    while(i<m&&j<n){
        if(arr1[i]<arr2[j]){
            cout<<arr1[i]<<" ";
            i++;
        }
        else if(arr2[j]<arr1[i]){
            cout<<arr2[j]<<" ";
            j++;
        }
        else{
            cout<<arr2[j]<<" ";
            j++;
        }
    }
    //to find the remaining larger element
    while(i<m){
    cout<<arr1[i]<<endl;
    i++;
    }
    while(j<n){
    cout<<arr2[j]<<endl;
    j++;
    }
    cout<<endl;
}
//to find intersection
void print_intersction(int arr1[],int arr2[],int m,int n){
    int i=0;
    int j=0;
    while(i<m&&j<n){
        if(arr1[i]<arr2[j]){
            i++;
        }
        else if(arr2[j]<arr1[i]){
            j++;
        }
        else{
            cout<<arr2[j]<<" ";
            j++;
        }
    }
    //to find the remaining larger element
    while(i<m){
    cout<<arr1[i]<<endl;
    i++;
    }
    while(j<n){
    cout<<arr2[j]<<endl;
    j++;
    }
}
int main(){
    int arr1[]={1,2,4,5,6};
    int arr2[]={1,2,3,5,7};
    int m=sizeof arr1/sizeof arr1[0];
    int n=sizeof arr2/sizeof arr2[0];
    print_union(arr1,arr2,m,n);
    print_intersction(arr1,arr2,m,n);
    return 0;
}