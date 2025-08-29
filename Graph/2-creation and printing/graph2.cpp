vector<vector<int>>printAdjancy(int n,int m, vector<vector<int>>&edges){
    vector<int>ans[n];
    //ans array will store all adjancy node corressponding on index
    for(int i = 0 ;i< m; i++){
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    vector<vector<int>>adj(n);
    for(int  i = 0; i< ans[i].size();j++){
        adj[i].push_back(i);

        //entering all neigouring
        for(int j = 0; j<ans[i].size();j++){
            adj[i].push_back(ans[i][j]);
        }
    }
    return adj;
}