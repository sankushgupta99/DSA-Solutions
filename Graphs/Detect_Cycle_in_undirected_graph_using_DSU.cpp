class Solution 
{
    public:
    int par[100010], rank[100010];
    
    int find(int x){
        if(par[x] == x)
        return x;
        
        int temp = find(par[x]);
        par[x] = temp;
        return temp;
    }
    
    void unionSet(int x, int y){
        int lox = find(x);
        int loy = find(y);
        
        if(rank[lox] > rank[loy]){
            par[loy] = lox;
        }
        else if(rank[loy] > rank[lox]){
            par[lox] = loy;
        }
        else{
            par[lox] = loy;
            rank[loy]++;
        }
    }
    
	bool isCycle(int V, vector<int>adj[])
	{
	    for(int i = 0; i < V; i++){
	        par[i] = i;
	        rank[i] = 1;
	    }
	    
	    vector<pair<int, int>> edges;
	    for(int i = 0; i < V; i++){
	        for(int j : adj[i]){
	            if(j >= i){
	                edges.push_back({i, j});
	            }
	        }
	    }
	    
	    for(int i = 0; i < edges.size(); i++){
	        int u = edges[i].first;
	        int v = edges[i].second;
	        if(find(u) == find(v)){
	            return true;
	        }
	        unionSet(u, v);
	    }
	    return false;
	}
};