#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    bool checkCycleDfs(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, unordered_map<int, list<int>> &adj) {
        visited[node] = true;
        dfsvisited[node] = true;

        for (auto neighbour : adj[node]) {
            if (!visited[neighbour]) {
                bool cycleDetect = checkCycleDfs(neighbour, visited, dfsvisited, adj);
                if (cycleDetect)
                    return true;
            }
            else if (dfsvisited[neighbour]) {
                return true;
            }
        }
        dfsvisited[node] = false;
        return false;
    }

    bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
        // create adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            adj[u].push_back(v);
        }

        // call DFS for all components
        unordered_map<int, bool> visited;
        unordered_map<int, bool> dfsvisited;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                bool cycleFound = checkCycleDfs(i, visited, dfsvisited, adj);
                if (cycleFound)
                    return true;
            }
        }
        return false;
    }
};

// Example usage
int main() {
    Solution s;
    vector<pair<int, int>> edges = {
        {1, 2}, {2, 3}, {3, 4}, {4, 2}
    };
    int n = 4;

    if (s.detectCycleInDirectedGraph(n, edges))
        cout << "Cycle detected" << endl;
    else
        cout << "No cycle detected" << endl;

    return 0;
}

// T.C = O(N + E)
// S.C = linear