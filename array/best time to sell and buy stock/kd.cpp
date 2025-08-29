//best time shell and buy stock (leetcode)
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Solution{
    public:
    int maxprofit(vector<int>&prices){
        int mini = prices[0];
        int profit = 0;

        for(int i =0 ;i<prices.size(); i++){
            int diff = prices[i] - mini;
            profit = max(profit,diff);
            //mini ko updatekaro
            mini = min(mini,prices[i]);
        }
        return profit;
    }
};

int main(){

    vector<int>prices = {7,1,5,3,6,4};
    Solution obj;

    int result = obj.maxprofit(prices);
    cout<<" the maximum profit is";

    cout<<result <<endl;
    return 0;

}