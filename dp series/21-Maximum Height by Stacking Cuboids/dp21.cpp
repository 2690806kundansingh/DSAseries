//Maximum Height by Stacking Cuboids
#include<bits/stdc++.h>
using namespace std;
class solution{
    public:

    //check function
    bool check(vector<int> base,vector<int>newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2])
           return true;

        else
           return false;   
    }

    //Using Lis logic
    int solveTab(int n,vector<vector<int>>&a){

        vector<int>currRow(n+1,0);
        vector<int>nextRow(n+1,0);

        for(int curr=n-1;curr>=0;curr--){
            for(int prev=curr-1;prev>=-1;prev--){

                //include
                int take=0;
                if(prev==-1 || check(a[curr],a[prev]))
                   //current row ka 2 column ->a[curr][2]
                   take= a[curr][2] + nextRow[curr+1];

                //exclude
                int notTake=0+nextRow[prev+1];

                currRow[prev+1]=max(take,notTake);   
            }
            nextRow=currRow;
        }
        return nextRow[0];
    }


    int maxHeight(vector<vector<int>>&cuboids){
        //step1: sort all dimensions for every cuboids
        for(auto&a:cuboids){
            sort(a.begin(),a.end());
        }
        //step2 sort all cuboids bassis on w and l
        sort(cuboids.begin(),cuboids.end());

        return solveTab(cuboids.size(),cuboids);

    }
};