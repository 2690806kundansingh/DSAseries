#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//comparator
bool cmp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
}
void makeSet(vector<int>&parent,vector<int>&rank,int n){
    //parent or rank ko starting me initilaize
    for(int i = 0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findParent(vector<int>&parent,int node){
    if(parent[node] == node){ 
        return node;
    }
    return parent[node] = findParent(parent,parent[node]);
}
//union wala parrt
void unionSet(int u,int v,vector<int>&parent,vector<int>rank){
    int ku = findParent(parent,u);
    int kv = findParent(parent,v);

    if(rank[ku]<rank[kv]){
         parent[ku] = kv;
    }
    else if(rank[kv]<rank[ku]){
        parent[kv] = ku;
    }
    else{
        parent[kv] = ku;
        rank[ku]++;
    }
}

int minimumSpanningTree(vector<vector<int>>&edges,int n){
    sort(edges.begin(),edges.end(),cmp);
    vector<int>parent(n);
    vector<int>rank(n);
    makeSet(parent,rank,n);

    int minweight = 0;
    for(int i=0;i<edges.size();i++){
        int u = findParent(parent,edges[i][0]);
        int v = findParent(parent,edges[i][1]);
        int wt = edges[i][2];

        if(u!=v){
            minweight+=wt;
            unionSet(u,v,parent,rank);
        }
    }
    return minweight;
}

int main(){
    int n= 5;
    vector<vector<int>>edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };
    cout<<"Minimum spanning tree is  "<<minimumSpanningTree(edges,n)<<endl;
    return 0;
}



































#include<iostream>
#include<vector>
#include<algorithm> // For sort
using namespace std;

// Comparator function to sort edges by weight
bool cmp(vector<int>&a, vector<int>&b) {
    return a[2] < b[2];
}

// Function to initialize the parent and rank arrays
void makeSet(vector<int>& parent, vector<int>& rank, int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

// Function to find the parent (with path compression)
int findParent(vector<int>& parent, int node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent, parent[node]);
}

// Function to perform union of two sets
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rank[rootU] < rank[rootV]) {
        parent[rootU] = rootV;
    } 
    else if (rank[rootV] < rank[rootU]) {
        parent[rootV] = rootU;
    } 
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

// Function to calculate the minimum spanning tree using Kruskal's algorithm
int minimumSpanningTree(vector<vector<int>>& edges, int n) {
    sort(edges.begin(), edges.end(), cmp); // Sort edges by weight
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank, n);

    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];

        // If u and v are in different sets, add edge to MST
        if (u != v) {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}

int main() {
    int n = 5; // Number of nodes
    vector<vector<int>> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    cout << "Minimum Spanning Tree Weight: " << minimumSpanningTree(edges, n) << endl;
    return 0;
}
