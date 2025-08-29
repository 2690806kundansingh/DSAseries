#include<iostream>
using namespace std;
//to print rowise sum
void printSum(int arr[3][3],int row,int col){
    cout<<"printing the sum"<<endl;
    for(int row=0;row<3;row++){
        int sum=0;
        for(int col=0;col<4;col++){
            sum+=arr[row][col];
        }
        cout<<sum<<" ";
    }
    cout<<endl;
}
int main(){
    int arr[3][3];
    //taking input 
    cout<<"enter the element"<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cin>>arr[row][col];
        }
    }
    //print the array
    cout<<"printing the array"<<endl;
    for(int row=0;row<3;row++){
        for(int col=0;col<3;col++){
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    printSum(arr,3,3);
    return 0;
}
