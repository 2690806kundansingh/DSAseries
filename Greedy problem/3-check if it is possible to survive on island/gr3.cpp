#include<iostream>
using namespace std;

class Solution{
    public:
    int minmumDays(int S,int N,int M){
        int sunday = S/7;

        int buyingDays = S-sunday;
        int totalfood = S*N;
        int ans = 0;

        if(totalfood % N == 0){
            ans = totalfood/N;
        }
        else{
            ans = totalfood/N + 1;
        }
        if(ans <= buyingDays)
           return ans;
        else
           return -1;   
    }
};