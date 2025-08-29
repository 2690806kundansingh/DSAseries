#include<iostream>
#include<list>
#include<unordered_map>
using namespace std;


//dfs function
void dfs(int node,int parent,int timer,vector<int>&disc,vector<int>&low,vector<int>&result,
unordered_map<int,list<int>>&adj,unordered_map<int,bool>>vis){
    vis[node] = true;
    //suru me 
    disc[node] = low[node] = timer++;
    //neighour ko search karo
    for(auto nbr:adj[node]){
        if(nbr == parent)
           continue;
        if(!vis[nbr]){
            dfs(nbr,node,timer,disc,low,result,adj,vis);
            low[node] = min(low[node],low[nbr]);

            //check edge bridge hai ki nahi
            if(low[nbr]>disc[node]){
                vector<int>ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            //node already visited and it is not parent
            //back age wala case
            low[node]  = min(low[node],disc[nbr]);
        }   
    }

}

vector<vector<int>>FindBridge(vector<vector<int>>&edges,int v,int e){
    //creatin adj
    unordered_map<int,list<int>adj;
    for(int i=0;i<v;i++){
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int>disc(v);
    vector<int>low(v);
    int parent = -1;
    unordered_map<int,bool>>vis;

    for(int i=0;i<v;i++){
        disc[i] = -1;
        low[i] = -1
    }

    //DFS
    vector<int>result;
    for(int i = 0;i<v;i++){
        dfs(!vis[i]){
            dfs(i,parent,timer,disc,low,result,adj,vis);
        }
    }
    return result;
}