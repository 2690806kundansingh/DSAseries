// #include<iostream>
// #include<unordered_map>
// #include<set>      // because it stores in sorted order
// #include<queue>
// #include<vector>
// using namespace std;

// // Function to prepare adjacency list
// void prepareAdjList(unordered_map<int, set<int>> &adjlist, vector<pair<int, int>> edges) {
//     for (int i = 0; i < edges.size(); i++) {
//         int u = edges[i].first;
//         int v = edges[i].second;

//         adjlist[u].insert(v); 
//         adjlist[v].insert(u);
//     }
// }

// // Print adjacency list
// void printAdjList(unordered_map<int, set<int>> &adjlist) {
//     for (auto i : adjlist) {
//         cout << i.first << " -> ";
//         for (auto j : i.second) {
//             cout << j << " ";
//         }
//         cout << endl;
//     }
// }

// // BFS traversal from a starting node
// void bfs(unordered_map<int, set<int>> &adjlist, unordered_map<int, bool> &visited, vector<int> &ans, int node) {
//     queue<int> q;
//     q.push(node);
//     visited[node] = true;

//     while (!q.empty()) {
//         int frontNode = q.front();
//         q.pop();

//         // store frontNode in ans
//         ans.push_back(frontNode);

//         // traverse all neighbours of frontNode
//         for (auto i : adjlist[frontNode]) {
//             if (!visited[i]) {
//                 q.push(i);
//                 visited[i] = true;
//             }
//         }
//     }
// }

// // Function to print BFS of entire graph
// vector<int> PrintBFS(int vertex, vector<pair<int, int>> edges) {
//     unordered_map<int, set<int>> adjlist;
//     vector<int> ans;
//     unordered_map<int, bool> visited;

//     prepareAdjList(adjlist, edges);
//     printAdjList(adjlist);

//     // handle disconnected graph
//     for (int i = 0; i < vertex; i++) {
//         if (!visited[i]) {
//             bfs(adjlist, visited, ans, i);
//         }
//     }
//     return ans;
// }

// // Driver code
// int main() {
//     int vertex = 5;
//     vector<pair<int, int>> edges = { {0, 1}, {0, 2}, {1, 3}, {1, 4} };

//     vector<int> result = PrintBFS(vertex, edges);

//     // Print BFS result
//     for (int i : result) {
//         cout << i << " ";
//     }
//     cout << endl;

//     return 0;
// }


#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void preapareAdj(unordered_map<int,list<int>>&adjlist,vector<pair<int,int>>&sdges){
    for(int i = 0; i<edges.size(); i++){
        int u = edgse[i].first;
        int v = edges[i].second;

        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
}
vector<int>bfs(int vertices,vector<pair<int,int>>edges){
    
}

