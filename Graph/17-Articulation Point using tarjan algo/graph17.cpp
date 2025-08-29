#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
using namespace std;

int min(int a,int b){
    if(a<b)
      return a;
    return b;  
}
void dfs(int node,int parent,vector<int>&desc,vector<int>&low,unordered_map<int,bool>&visited,unordered_map<int,list<int>>&adj,vector<int>&ap,int &timer){
    visited[node] = true;
    desc[node] = low[node] = timer++;
    int child = 0;

    //traverse neighour
    for(auto nbr : adj[node]){
        if(nbr == parent)
           continue;

        if(!visited[nbr]){
            dfs(nbr,node,desc,low,visited,adj,ap,timer);
            // low ko update karo
            low[node] = min(low[node],low[nbr]);

            //check articulation point or node
            if(low[nbr] >= desc[node] && parent != -1){
                ap[node] = 1;
            } 
            child++;

        }   
        else{
            low[node] = min(low[node],desc[nbr]);
        }
    }
    if(parent == -1 && child > 1)
       ap[node] = 1;
}


int main(){

    int n = 5;
    int e = 5;
    vector<pair<int,int>>edges;

    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    //adj list
    unordered_map<int,list<int>> adj;
    for(int i = 0; i<edges.size(); i++){
        int u = edges[i].first;
        int v= edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int>desc(n);
    vector<int>low(n);
    unordered_map<int,bool>visited;
    vector<int>ap(n,0);// for ans to store

    for(int i = 0; i<n ; i++){
        desc[i] = -1;
        low[i] = -1;
    }

    //dfs
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i,-1,desc,low,visited,adj,ap,timer);
        }
    }

    //printing articulation point (ap)
    for(int i = 0; i<n; i++){
        if(ap[i] != 0){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    return 0;


}