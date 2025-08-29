#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Solution {
public:
    unordered_map<int, list<int>> adj;

    void edges(int u, int v, bool direction) {
        // direction = 0 -> undirected
        // direction = 1 -> directed
        adj[u].push_back(v);
        if (direction == 0) {
            adj[v].push_back(u);
        }
    }

    // printing the adjacency list
    void printAdj() {
        for (auto i : adj) {
            cout << i.first << " -> ";
            for (auto j : i.second) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
}; // <-- semicolon here

int main() {
    Solution sol;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    int m;
    cout << "Enter the number of edges: ";
    cin >> m;

    for (int i = 0; i < m; i++) {
        cout << "Enter edge (u v): ";
        int u, v;
        cin >> u >> v;

        // creating an undirected graph
        sol.edges(u, v, 0);
    }

    // printing adjacency list
    cout << "\nAdjacency List:\n";
    sol.printAdj();
    return 0;
}
