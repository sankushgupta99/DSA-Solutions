int par[30001], disc[30001], low[30001];
bool ap[30001];

void DFS(int src, vector<int> adj[], int &count, int &curr){
    disc[src] = curr++;
    
    for(int i : adj[src]){
        if(i == par[src])
            continue;
        
        par[i] = src;
        
        if(disc[i] != -1){
            low[src] = min(low[src], disc[i]);
        }
        else{
            if(par[src] == -1)
            count++;
            DFS(i, adj, count, curr);
            
            if(low[i] >= disc[src])
            ap[src] = true;
            low[src] = min(low[src], low[i]);
        }
    }
}

int doctorStrange(int n, int m, vector<vector<int>> &g)
{
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++){
        int u = g[i][0];
        int v = g[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    memset(par, -1, sizeof(par));
    memset(disc, -1, sizeof(disc));
    
    for(int  i = 1; i <= n; i++)
    low[i] = INT_MAX;
    
    memset(ap, false, sizeof(ap));
    int count = 0, curr = 1; 
    
    DFS(1, adj, count, curr);
    if(count == 1)
    ap[1] = false;
    
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(ap[i])
        ans++;
    }
    return ans;
}