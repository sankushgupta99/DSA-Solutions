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