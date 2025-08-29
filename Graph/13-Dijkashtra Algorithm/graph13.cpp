#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <set>
#include <climits>
using namespace std;

class Solution {
public:
    vector<int> Dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
        // 1. Create adjacency list
        unordered_map<int, list<pair<int, int>>> adj;
        for (int i = 0; i < edges; i++) {
            int u = vec[i][0];
            int v = vec[i][1];
            int w = vec[i][2];

            // Undirected graph: add both directions
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // 2. Distance array initialized to infinity
        vector<int> dist(vertices, INT_MAX);

        // 3. Min-heap behavior using set
        set<pair<int, int>> st;

        // 4. Distance to source is 0
        dist[source] = 0;
        st.insert({0, source});

        while (!st.empty()) {
            // 5. Get node with smallest distance
            auto top = *(st.begin());
            int nodeDistance = top.first;
            int topNode = top.second;
            st.erase(st.begin());

            // 6. Traverse neighbors
            for (auto neighbour : adj[topNode]) {
                int adjNode = neighbour.first;
                int edgeWeight = neighbour.second;

                if (nodeDistance + edgeWeight < dist[adjNode]) {
                    // Remove old record if it exists
                    auto record = st.find({dist[adjNode], adjNode});
                    if (record != st.end()) {
                        st.erase(record);
                    }

                    // Update distance
                    dist[adjNode] = nodeDistance + edgeWeight;

                    // Insert new record
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main() {
    int vertices = 5;
    int edges = 6;
    vector<vector<int>> vec = {
        {0, 1, 2},
        {0, 4, 1},
        {1, 2, 3},
        {4, 2, 2},
        {2, 3, 6},
        {4, 3, 4}
    };

    int source = 0;

    Solution sol;
    vector<int> result = sol.Dijkstra(vec, vertices, edges, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < vertices; i++) {
        cout << "Node " << i << " : " << result[i] << "\n";
    }

    return 0;
}
