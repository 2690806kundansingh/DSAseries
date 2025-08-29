// // N queen problem
// #include<stdlib.h>
// #include<vector>
// using namespace std;

// bool isSafe(int row,int col,vector<vector<int>>&board,int n){
//     int x = row;
//     int y = col;

//     //check for same row
//     while(y>=0){
//         if(board[x][y]==1)
//            return false;
//         y--;   
//     }
//     //check for upper  diagonal
//     int x = row;
//     int y = col;
//     while(x>=0 && y>=0){
//         if(board[x][y]==1)
//            return false;
//         y--; 
//         x--;
//     }

//     //for lower diagonal
//     int x = row;
//     int y = col;
//     while(x<n && y>=0){
//         if(board[x][y]==1)
//            return false;
//         y--; 
//         x++;
//     }
//     return true;

// }

// void addSolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
//     vector<int>temp;

//     for(int i=0;i<n;i++){
//         for(int j=0;j<n;j++){
//             temp.push_back(board[i][j]);
//         }
//     }
//     ans.push_back(temp);
// }


// void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){
//     //base case
//     if(col==n){
//         //borad ki value ko ans me dall do
//         addSolution(ans,board,n);
//         return;
//     }

//     //solve only one case
//     for(int row=0;row<n;row++){//sabhi row pe jana hai
//         //kya queen ko board pe rakhna safe hai
//         if(isSafe(row,col,board,n)){
//             //if placing queen is safe
//             board[row][col]=1;
//             solve(col+1,ans,board,n);
//             //backtrack
//             //wapas ate samay queen ko hata do
//             board[row][col]=0;
//         }
//     }
// }

// vector<vector<int>>nQueen(int n){
//         vector<vector<int>>board(n,vector<int>(n,0));
//         vector<vector<int>>ans;

//         solve(0,ans,board,n);
//         return ans;
//     }

#include <iostream>
#include <vector>
using namespace std;

bool isSafe(int row,int col,vector<vector<int>>&board,int n){
    int x = row;
    int y = col;

    //check for same row
    while(y>=0){
        if(board[x][y]==1)
           return false;
        y--;   
    }
    //check for upper  diagonal
    x = row;
    y = col;
    while(x>=0 && y>=0){
        if(board[x][y]==1)
           return false;
        y--; 
        x--;
    }

    //for lower diagonal
    x = row;
    y = col;
    while(x<n && y>=0){
        if(board[x][y]==1)
           return false;
        y--; 
        x++;
    }
    return true;
}

void addSolution(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    vector<int>temp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);
}

void solve(int col,vector<vector<int>>&ans,vector<vector<int>>&board,int n){
    //base case
    if(col==n){
        //board ki value ko ans me dal do
        addSolution(board,ans,n);
        return;
    }

    //solve only one case
    for(int row=0;row<n;row++){ //sabhi row pe jana hai
        if(isSafe(row,col,board,n)){
            //place queen
            board[row][col]=1;
            solve(col+1,ans,board,n);
            //backtrack
            board[row][col]=0;
        }
    }
}

vector<vector<int>> nQueen(int n){
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;

    solve(0,ans,board,n);
    return ans;
}

int main() {
    int n;
    cout << "Enter the value of N: ";
    cin >> n;

    vector<vector<int>> solutions = nQueen(n);

    cout << "\nTotal solutions: " << solutions.size() << endl;

    // Printing all solutions
    for(int k=0; k<solutions.size(); k++){
        cout << "Solution " << k+1 << ":\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(solutions[k][i*n + j] == 1)
                    cout << "Q ";
                else
                    cout << ". ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
