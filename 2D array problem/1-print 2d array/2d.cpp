#include<iostream>
using namespace std;
int main(){
    int arr[3][4];
    //create 2d array
    //taking input row wise
    // for(int row=0;row<3;row++){
    //     for(int col=0;col<4;col++){
    //         cin>>arr[row][col];
    //     }
    // }

    
    //taking input by column wise
    for(int col=0;col<4;col++){
        for(int row=0;row<3;row++){
            cin>>arr[row][col];
        }
    }

    //print an array
    for(int i=0;i<3;i++){
        for(int j=0;j<4;j++){
            cout<<arr[j][i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

