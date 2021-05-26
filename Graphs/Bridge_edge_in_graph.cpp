class Solution
{
	public:
    int par[100001], disc[100001], low[100001];
    
    void DFS(vector<int> adj[], int src, int &curr, int c, int d, bool &isbridge){
        disc[src] = curr++;
        
        for(int i : adj[src]){
            if(i == par[src])
            continue;
            
            par[i] = src;
            if(disc[i] != -1){
                low[src] = min(low[src], disc[i]);
            }
            else{
                DFS(adj, i, curr, c, d, isbridge);
                if(low[i] > disc[src] && ((src == d && i == c) || (src == c && i == d)))
                isbridge = true;
                low[src] = min(low[src], low[i]);
            }
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        memset(par, -1, sizeof(par));
        memset(disc, -1, sizeof(disc));
        
        for(int i = 0; i < V; i++)
        low[i] = INT_MAX;
        
        int curr = 1;
        bool isbridge = false;
        
        for(int i = 0; i < V; i++){
            if(disc[i] == -1){
                DFS(adj, i, curr, c, d, isbridge);
            }
        }
        
        return isbridge;
    }
};

//OR

class Solution
{
	public:
	void DFS(vector<int> adj[], int src, int visited[], int c, int d){
        visited[src] = 1;
        for(int i : adj[src]){
            if(!visited[i]){
                DFS(adj, i, visited, c, d);
            }
        }
    }
    
    void DFS1(vector<int> adj[], int src, int visited[], int c, int d){
        visited[src] = 1;
        
        for(int i : adj[src]){
            if((src == c && i == d) || (src == d && i == c))
            continue;
            
            if(!visited[i]){
                DFS1(adj, i, visited, c, d);
            }
        }
    }
    
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {   
        int visited[V];
        memset(visited, 0, sizeof(visited));
        
        int init_components = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                init_components++;
                DFS(adj, i, visited, c, d);
            }
        }
        
        memset(visited, 0, sizeof(visited));
        int final_components = 0;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                final_components++;
                DFS1(adj, i, visited, c, d);
            }
        }
        return (final_components > init_components);
    }
};