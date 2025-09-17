#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

struct Job{
    int id;
    int dead;
    int profit;
};

class Soltuin{
    public:

    static bool cmp(Job a,Job b){
        return a.profit > b.profit;
    }
    //function to find the maximum profit and the number of jobs done.
    vector<int>JobShedule(Job arr[],int n){
        sort(arr,arr+n,cmp);

        //first we need to find the maximum deadline
        int maxDeadline = INT_MIN;
        for(int i = 0; i<n ;i++){
            maxDeadline = max(maxDeadline,arr[i].dead);
        }
        vector<int>schedule(maxDeadline+1,-1);
        int count = 0;
        int maxProfit = 0;

        for(int i = 0; i<n; i++){
            int currprofit = arr[i].profit;
            int currJobID = arr[i].dead;
            int currDead = arr[i].dead;

            for(int k = currDead;k>0; k--){
                if(schedule[k] == -1){
                    count++; 
                   maxProfit += currprofit;
                   schedule[k] = currJobID; 
                   break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(count);
        ans.push_back(maxProfit);
        return ans;
    }
};