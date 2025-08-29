
// Shortest path for undirected graph using BFS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> shortestpath(vector<pair<int,int>>& edges, int n, int m, int s, int t) {
        // Create adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i].first;
            int v = edges[i].second;
            // Undirected graph
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // BFS
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;

        parent[s] = -1;
        visited[s] = true;
        q.push(s); // push start node

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            for (auto i : adj[front]) {
                if (!visited[i]) {
                    visited[i] = true;
                    parent[i] = front;
                    q.push(i);
                }
            }
        }

        // Prepare shortest path
        vector<int> ans;
        int currentNode = t;
        ans.push_back(t);

        while (currentNode != s) {
            currentNode = parent[currentNode];
            ans.push_back(currentNode);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    int n = 7; // number of nodes
    int m = 7; // number of edges

    vector<pair<int, int>> edges = {
        {0, 1}, {0, 3}, {1, 2},
        {3, 4}, {4, 5}, {5, 6}, {2, 6}
    };

    int s = 0; // start node
    int t = 6; // target node

    Solution sol;
    vector<int> path = sol.shortestpath(edges, n, m, s, t);

    cout << "Shortest path from " << s << " to " << t << ": ";
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
