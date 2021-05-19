class Solution
{
	public:
	void DFS(vector<int> adj[], int src, int visited[], stack<int> &s){
	    visited[src] = 1;
	    for(int i = 0; i < adj[src].size(); i++){
	        if(!visited[adj[src][i]]){
	            DFS(adj, adj[src][i], visited, s);
	        }
	    }
	    s.push(src);
	}
    int kosaraju(int V, vector<int> adj[])
    {
        stack<int> s;
        int visited[V];
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                DFS(adj, i, visited, s);
            }
        }
        
        vector<int> adj2[V];
        for(int i = 0; i < V; i++){
            for(int j : adj[i]){
                adj2[j].push_back(i);
            }
        }
        
        int visited2[V];
        memset(visited2, 0, sizeof(visited2));
        stack<int> s2;
        int scc = 0;
        
        while(!s.empty()){
            int src = s.top();
            s.pop();
            if(!visited2[src]){
                scc++;
                DFS(adj2, src, visited2, s2);
            }
        }
        
        return scc;
    }
};