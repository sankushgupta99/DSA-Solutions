class Solution 
{
    public:
    void DFS(vector<int> adj[], int src, int visited[], stack<int> &s){
        visited[src] = 1;
        
        for(int i : adj[src]){
            if(!visited[i]){
                DFS(adj, i, visited, s);
            }
        }
        
        s.push(src);
    }
	int findMotherVertex(int V, vector<int>adj[])
	{
	    stack<int> s;
	    int visited[V];
	    memset(visited, 0, sizeof(visited));
	    
	    for(int i = 0; i < V; i++){
	        if(!visited[i]){
	            DFS(adj, i, visited, s);
	        }
	    }
	    
	    int mother_vert = s.top();
	    memset(visited, 0, sizeof(visited));
	    
	    DFS(adj, mother_vert, visited, s);
	    
	    for(int i = 0; i < V; i++){
	        if(!visited[i])
	        return -1;
	    }

	    return mother_vert;
	}

};