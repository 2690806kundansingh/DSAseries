// cycle detectioon using bfs

#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool iscyclicBfs(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj) {
        // creating parent mapping
        unordered_map<int, int> parent;
        parent[src] = -1;
        visited[src] = true;

        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto neighbour : adj[front]) {
                if (visited[neighbour] && neighbour != parent[front]) {
                    return true; // cycle found
                } 
                else if (!visited[neighbour]) {
                    q.push(neighbour);
                    visited[neighbour] = true;
                    parent[neighbour] = front;
                }
            }
        }
        return false;
    }

    string cycledetection(vector<vector<int>> &edges, int n, int m) {
        // create adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // handle disconnected graph
        unordered_map<int, bool> visited;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                bool ans = iscyclicBfs(i, visited, adj);
                if (ans)
                    return "Yes";
            }
        }
        return "No";
    }
};

// T.C -> O(N + M)
int main() {
    Solution sol;
    int n = 5; // number of nodes
    int m = 5; // number of edges
    vector<vector<int>> edges = {
        {0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 1} // this contains a cycle
    };

    string result = sol.cycledetection(edges, n, m);
    cout << "Cycle present? " << result << endl;

    return 0;
}
// T.C-> linear