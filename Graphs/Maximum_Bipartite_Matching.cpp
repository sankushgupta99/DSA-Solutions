class Solution {
public:
    int graph[205][205];
    
    vector<int> BFS(int src, int N){
        vector<int> par(N);
        vector<int> vis(N);
        for(int i = 0; i < N; i++){
            par[i] = -1;
            vis[i] = 0;
        }
        
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int v = 0; v < N; v++){
                if(!vis[v] && graph[u][v] > 0){
                    vis[v] = 1;
                    q.push(v);
                    par[v] = u;            
                }
            }
        }
        return par;
    }
    
    void find_min(int dest, vector<int> par, int &min_edge){
        for(int v = dest; par[v] != -1; v = par[v]){
            int u = par[v];
            min_edge = min(min_edge, graph[u][v]);
        }
    }
    
    void subtract_min_edge(int dest, vector<int> par, int min_edge){
        for(int v = dest; par[v] != -1; v = par[v]){
            int u = par[v];
            graph[u][v] -= min_edge;
        }
    }
    
    void add_back_edge(int dest, vector<int> par, int min_edge){
        for(int v = dest; par[v] != -1; v = par[v]){
            int u = par[v];
            graph[v][u] += min_edge;
        }
    }
    
	int maximumMatch(vector<vector<int>>&G){
	    memset(graph, 0, sizeof(graph));
	    int m = G.size();
	    int n = G[0].size();
	    
	    for(int i = 1; i <= m; i++){
	        graph[0][i] = 1;
	    }
	    for(int i = m + 1; i <= m + n; i++){
	        graph[i][m+n+1] = 1;
	    }
	    for(int i = 0; i < G.size(); i++){
	        for(int j = 0; j < G[0].size(); j++){
	            if(G[i][j] == 1){
	                graph[i+1][j+m+1] = 1;
	            }
	        }
	    }
	    
	    int src = 0;
	    int dest = m + n + 1;
	    int ans = 0;
	    vector<int> par;
	    
	    do{
	        par = BFS(src, m + n + 2);
	        
	        if(par[dest] != -1){
	            int min_edge = INT_MAX; 
	            find_min(dest, par, min_edge);
	            ans += min_edge;
	            subtract_min_edge(dest, par, min_edge);
	            add_back_edge(dest, par, min_edge);
	        }
	        
	    }while(par[dest] != -1);
	    
	    return ans;
	}

};