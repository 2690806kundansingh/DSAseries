// Topological sort using DFS
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <stack>

using namespace std;

class Solution {
public:
    void topoSort(int node, vector<bool>& visited, stack<int>& s, unordered_map<int, list<int>>& adj) {
        visited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour])
                topoSort(neighbour, visited, s, adj);
        }

        // Push the current node to stack after visiting all its neighbours
        s.push(node);
    }

    vector<int> topological(vector<vector<int>>& edges, int v, int e) {
        // Create adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < e; i++) {
            int u = edges[i][0];
            int w = edges[i][1];
            adj[u].push_back(w);
        }

        vector<bool> visited(v, false);
        stack<int> s;

        // Call DFS for each unvisited node
        for (int i = 0; i < v; i++) {
            if (!visited[i])
                topoSort(i, visited, s, adj);
        }

        // Prepare the result
        vector<int> ans;
        while (!s.empty()) {
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    
    // Example: DAG
    int v = 6, e = 6;
    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = sol.topological(edges, v, e);

    cout << "Topological Order: ";
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}
//T.C = O(N +E)
// S.c = linear

