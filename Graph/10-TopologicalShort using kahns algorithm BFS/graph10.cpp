// Topological Sort using Kahn's Algorithm (BFS)
#include <iostream>
#include <queue>
#include <unordered_map>
#include <list>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> topologySort(vector<vector<int>>& edges, int v, int e) {
        // Create adjacency list
        unordered_map<int, list<int>> adj;
        for (int i = 0; i < e; i++) {
            int u = edges[i][0];
            int w = edges[i][1];
            adj[u].push_back(w);
        }

        // Find all indegrees
        vector<int> indegree(v, 0);
        for (auto& node : adj) {
            for (auto neighbour : node.second) {
                indegree[neighbour]++;
            }
        }

        // Push all nodes with indegree 0 into the queue
        queue<int> q;
        for (int i = 0; i < v; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        // BFS for topological sort
        vector<int> ans;
        while (!q.empty()) {
            int front = q.front();
            q.pop();

            // Store in answer
            ans.push_back(front);

            // Update neighbours' indegree
            for (auto neighbour : adj[front]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    int v = 6, e = 6;
    vector<vector<int>> edges = {
        {5, 0},
        {5, 2},
        {4, 0},
        {4, 1},
        {2, 3},
        {3, 1}
    };

    vector<int> result = sol.topologySort(edges, v, e);

    cout << "Topological Order (Kahn's Algorithm): ";
    for (int node : result)
        cout << node << " ";
    cout << endl;

    return 0;
}

//T.C -> O(n + E)
//S.C -> O(n + E)


