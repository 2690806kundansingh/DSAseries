#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool iscyclicdfs(int node,int parent,unordered_map<int,bool>&visited,unordered_map<int, list<int>> &adj){
        visited[node] = true;

        //sabhi ke neighour leke ke aoo adj se
        for(auto neighour : adj[node]){
            if(!visited[neighour]){
                bool cycleDetected = iscyclicdfs(neighour,node,visited,adj);
                if(cycleDetected)
                   return true;
            }
            else if(neighour != parent){
                //then cycle present
                return true;
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
                bool ans = iscyclicdfs(i, -1,visited, adj);
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