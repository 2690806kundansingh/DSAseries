#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();

        int rowindex=0;
        int colindex=col-1;

        while(rowindex<row && colindex>=0){
            int element=matrix[rowindex][colindex];

            if(element==target){
                return 1;
            }
            if(element<target){
                rowindex++;
            }
            else{
                colindex--;
            }
        }
        return 0;
    }
};


// #include<iostream>
// using namespace std;


// bool isPresent(int arr[3][4],int target,int row, int col){
//     for(int row = 0; row<3;row++){
//         for(int col = 0; col<4;col++){
//             if(arr[row][col] == target){
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }

// int main(){
//     int arr[3][4];

//     for(int row = 0; row < 3; row++){
//         for(int col = 0;col < 4; col++){
//             cin >> arr[row][col] ;
//         }
//     }

//     //print
//     for(int row = 0; row < 3; row++){
//         for(int col = 0;col <4; col++){
//             cout<<arr[row][col] << " ";
//         }
//         cout<<endl;
//     }

//     cout<<"Enter the element to search :"<<endl;
//     int target;
//     cin>>target;

//     if(isPresent(arr,target,3,4)){
//         cout<<"element is present"<<endl;
//     }
//     else{
//         cout<<"not present"<<endl;
//     }
//     return 0;
// }













