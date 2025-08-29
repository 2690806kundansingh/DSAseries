#include<iostream>
#include<list>
#include<limit.h>
#include<unordered_map>

using namespace std;

vector<pair<pair<int,int>,int>>CalulatePrims(int n,int m,vector<pair<pair<int,int>>&g){
    //creating adjlist
    unordered_map<int,list<int,int>>adj;
    for(int i=0;i<g.size();i++){
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }

    //creating a key data structure
    vector<int>key(n+1);
    vector<int>mst[n+1];
    vector<int>parent(n+1);

    for(int i=0;i<=n;i++){
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    //let start the algo
    key[1] = 0;
    parent[1] = -1;

    for(int i=0;i<n;i++){
        int min = INT_MAX;
        int u;

        //find the min sali node
        for(int v=1;v<=n;v++){
            if(mast[v]==false && key[v] = min){
                u=v;
                min = key[v];
            }
        }
        //mark min node as true
        mst[u] = true;

        //check its adjacent node
        for(auto it:adj[u]){
            int v = it.first;
            int w = it.second;

            if(mst[v]==false && w<key[v]){
                parent[v]  = u;
                key[v] = w;
            }
        }
    }
    vector<pair<pair<int,int>int>>result;
    for(int i = 2;i<=n;i++){
        result.push_back(make_pair({parent[i],i}key[i]));
    }
    return result;
}