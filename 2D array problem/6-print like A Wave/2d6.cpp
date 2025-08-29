#include<iostream>
#include<vector>
using namespace std;

//print like a wave
vector<int>waveprint(vector<vector<int>>arr,int nrow,int mcol){
    vector<int>ans;
    for(int col=0;col<mcol;col++){
        if(col & 1){
            //odd condition->bottom to top
            for(int row=nrow-1;row>=0;row--){
                ans.push_back(arr[row][col]);
            }
        }
        else{
            //0 or even condition->top to bottom
            for(int row=0;row<nrow;row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}