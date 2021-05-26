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

//OR

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
    
    void DFS2(vector<int> adj[], int src, int visited[], vector<int> &v){
        visited[src] = 1;
        v.push_back(src);
        
        for(int i : adj[src]){
            if(!visited[i]){
                DFS2(adj, i, visited, v);
            }
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
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
        
        memset(visited, 0, sizeof(visited));
        vector<vector<int>> res;
        while(!s.empty()){
            int curr = s.top();
            s.pop();
            
            if(!visited[curr]){
                vector<int> v;
                DFS2(adj2, curr, visited, v);
                sort(v.begin(), v.end());
                res.push_back(v);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};