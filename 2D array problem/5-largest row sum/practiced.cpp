#include<iostream>
#include<limits.h>
using namespace std;

int largestSum(int arr[3][4],int row,int col){
    int maxi = INT_MIN;
    int rowIndex = -1;

    for(int row = 0; row<3; row++){
        int sum = 0;
        for(int col = 0; col < 4; col++){
            sum += arr[row][col];
        }
        if(sum > maxi){
            maxi = sum;
            rowIndex = row;
        }
    }
    cout<<"The largest row some is :"<<maxi <<endl;
    return rowIndex;
}
int main(){
    int arr[3][4];
    cout<<"Enter the element "<<endl;
    for(int row = 0;row <3; row++){
        for(int col = 0; col <4; col++){
            cin >> arr[row][col];
        }
    }
    //print
    for(int row = 0; row<3;row++){
        for(int col = 0; col<4; col++){
            cout<<arr[row][col] <<" ";
        }
        cout<<endl;
    }
    int ansindex = largestSum(arr,3,4);
    cout<<"Max row is at index "<<ansindex<<endl;
    return 0;
}