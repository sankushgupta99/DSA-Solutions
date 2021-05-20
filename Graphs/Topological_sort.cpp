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
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   vector<int> res;
	   int visited[V];
	   memset(visited, 0, sizeof(visited));
	   stack<int> s;
	   
	   for(int i = 0; i < V; i++){
	       if(!visited[i]){
	           DFS(adj, i, visited, s);
	       }
	   }
	   
	   while(!s.empty()){
	       res.push_back(s.top());
	       s.pop();
	   }
	   
	   return res;
	}
};