// // when the negative edges we use bellman algorithm
// // to find the negative cycle
// // to find the shortest path
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bellmanFord(int n, int m, int src, int dest, vector<vector<int>> edges) {
        // distance initialized to a very large value
        vector<int> dist(n + 1, 1e9);
        dist[src] = 0; // distance to source is zero

        // iterate n-1 times to relax all edges
        for (int i = 1; i <= n - 1; i++) {
            // traverse all edges
            for (int j = 0; j < m; j++) {
                int u = edges[j][0];
                int v = edges[j][1];
                int wt = edges[j][2];

                if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt; // update distance
                }
            }
        }

        // check for negative weight cycle
        bool hasNegativeCycle = false;
        for (int j = 0; j < m; j++) {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v]) {
                hasNegativeCycle = true;
                break;
            }
        }

        if (hasNegativeCycle) {
            cout << "Negative weight cycle detected!" << endl;
            return -1;
        }

        return dist[dest];
    }
};

int main() {
    int n = 5; // number of vertices
    int m = 8; // number of edges
    int src = 1, dest = 5;

    // edges: {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, -1},
        {1, 3, 4},
        {2, 3, 3},
        {2, 4, 2},
        {2, 5, 2},
        {4, 2, 1},
        {4, 3, 5},
        {5, 4, -3}
    };

    Solution sol;
    int shortestDist = sol.bellmanFord(n, m, src, dest);

    if (shortestDist != -1) {
        cout << "Shortest distance from " << src << " to " << dest << " is: " << shortestDist << endl;
    }

    return 0;
}
