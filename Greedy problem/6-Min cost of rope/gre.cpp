#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
    public:
    long long minCost(long long arr[],int n){
        priority_queue<long long,vector<long long>,greater<long long>>pq;

        for(int i = 0; i<n; i++){
            pq.push(arr[i]);
        }

        long long cost = 0;
        while(pq.size() > 1){
            long long first = pq.top();
            pq.pop();

            long long second = pq.top();
            pq.pop();

            long long mergedlength = first + second;
            cost = cost + mergedlength;
            pq.push(mergedlength);
        }
        return cost;
    }
};