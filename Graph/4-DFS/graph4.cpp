#include <iostream>
#include <list>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    void dfs(int node, unordered_map<int, bool> &visited,
             unordered_map<int, list<int>> &adj, vector<int> &component) {
        // store the current node
        component.push_back(node);
        visited[node] = true;

        // recursive DFS for unvisited neighbours
        for (auto i : adj[node]) {
            if (!visited[i]) {
                dfs(i, visited, adj, component);
            }
        }
    }

    vector<vector<int>> depthFirstSearch(int v, int e, vector<vector<int>> &edges) {
        // prepare adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int w = edges[i][1]; // renamed from v to w to avoid shadowing parameter 'v'

            adj[u].push_back(w);
            adj[w].push_back(u);
        }

        vector<vector<int>> ans;
        unordered_map<int, bool> visited;

        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                vector<int> component;
                dfs(i, visited, adj, component);
                ans.push_back(component);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int v = 5;
    int e = 4;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {3, 4}};

    vector<vector<int>> result = sol.depthFirstSearch(v, e, edges);

    // output for connected graph
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[i].size(); j++) { // corrected: result[i].size()
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
