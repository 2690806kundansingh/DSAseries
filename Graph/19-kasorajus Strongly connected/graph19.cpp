// // strongly connected grraph using kasorajus algorithm

#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
#include <vector>
using namespace std;

// Reverse DFS (used on transposed graph)
void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            revDfs(nbr, vis, adj);
        }
    }
}

// Normal DFS to fill stack according to finish time
void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj) {
    vis[node] = true;
    for (auto nbr : adj[node]) {
        if (!vis[nbr]) {
            dfs(nbr, vis, st, adj);
        }
    }
    st.push(node);
}

// Function to find number of Strongly Connected Components (SCC)
int stronglyConnectedComponent(int vertices, vector<vector<int>> &edges) {
    // Step 1: Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v); // Directed graph
    }

    // Step 2: Topological sort order using DFS
    stack<int> st;
    unordered_map<int, bool> vis;
    for (int i = 0; i < vertices; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }

    // Step 3: Transpose graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < vertices; i++) {
        vis[i] = false; // reset visited
        for (auto nbr : adj[i]) {
            transpose[nbr].push_back(i);
        }
    }

    // Step 4: Process stack and run reverse DFS
    int count = 0;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        if (!vis[top]) {
            count++;
            revDfs(top, vis, transpose);
        }
    }

    return count;
}

int main() {
    int vertices = 5;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {1, 3},
        {3, 4}
    };

    int sccCount = stronglyConnectedComponent(vertices, edges);
    cout << "Number of Strongly Connected Components: " << sccCount << endl;

    return 0;
}
