//Find the specific pair of matrix
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int maxDiff(vector<vector<int>>&matrix,int n){
    vector<vector<int>>maxMat(n,vector<int>(n));
    //n is row and vector<int>(n) for column
    maxMat[n-1][n-1]=matrix[n-1][n-1];

    //filling max matrix from last row and column
    //fiiling column and row constent

    //for last row
    for(int j=n-2;j>=0;j--){
        maxMat[n-1][j]=max(maxMat[n-1][j+1],matrix[n-1][j]);
    }
    //fiilinf row and column constent
    
    //for column
    for(int i=n-2;i>=0;i--){
        maxMat[i][n-1]=max(maxMat[i+1][n-1],matrix[i][n-1]);
    }
    //remaining row and column
    for(int i=n-2;i>=0;i--){
        for(int j=n-2;j>=0;j--){
            maxMat[i][j]=max(maxMat[i+1][j],maxMat[i][j+1],maxMat[i][j]);
        }
    }
    int ans=INT_MIN;
    for(int i=n-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            ans=max(ans,maxMat[i+1][j+1]-matrix[i][j]);
        }
    }
    return ans;
}

void solve(){
    int n;
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    cout<<"MAX VALUE IS:"<<maxDiff(matrix,n)<<endl;
}