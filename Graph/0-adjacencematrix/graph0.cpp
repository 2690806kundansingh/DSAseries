#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;

    // creating an adjacency matrix
    vector<vector<int>> adj(n, vector<int>(n, 0));

    int e;
    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;

        // mark as 1
        adj[u][v] = 1;
        adj[v][u] = 1; // uncomment this if the graph is undirected
    }

    // printing adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
