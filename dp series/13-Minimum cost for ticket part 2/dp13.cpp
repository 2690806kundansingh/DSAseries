//using space optimisation
#include<iostream>
#include<queue>
using namespace std;

class Solution{
    public:
    int minmumCoins(int n,vector<int>&days,vector<int>cost){
        int ans = 0;

        queue<pair<int,int>>month;
        queue<pair<int,int>>week;

        for(int day :days){
            //stap 1 -> remove the expire days
            while(!month.empty() && month.front().first + 30 <= day)
                month.pop();
            while(!week.empty() && weel.front().fisrt + 7 <= day)
                week.pop();
            
            //step 2 -> add current current for new days 
            week.push(make_pair(day,ans + cost[1]));
            month.push(make_pair(day,ans + cost[2]));

            //step3 -> updata the answer
            ans = min(ans + cost[0], min(week.front().second,month.front().second));
        }
        return ans;
    }
}

/*
T.C -> O(n)
S.C -> O(1)
*/