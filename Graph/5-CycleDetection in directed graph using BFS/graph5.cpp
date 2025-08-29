//Cycle detection in directed graph using BFS
// topoplogical using kahns algorithm
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<unordered_map>
#include<map>
using namespace std;

vector<int>DetectCycleIdirectGraph(int n,vector<pair<int,int>>&sdges,int v,int e){
    //creating adj list
    unordered_map<int,list<int>>adj;
    for(int i=0;i<edges.size();i++){
        int u = edges[i].first -1;
        int v = edges[i].second -1;
        adj[u].push_back(v);
    }

    //finding all indegree
    vector<int>indegree(n);

    for(auto i : adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }

    // 0 indegree walw ko push karo
    queue<int>q;
    for(int i =0 i<n;i++){
        if(!indegree[i]==0)
           q.push(i);
    }

    //do BFS
    int cnt = 0;
    while(!q.empty()){
        int front = q.front();
        q.pop();

        //int count
        cnt++;

        //neighour indegree update
        for(auto neighour:adj[front]){
            indegree[neighour]--;

            if(indegree[neighour]==0)
               q.push[neoghour];
        }
    }
    if(cnt ==n)
       return false;
    else  
       return true;   
}