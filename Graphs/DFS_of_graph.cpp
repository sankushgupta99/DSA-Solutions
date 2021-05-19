class Solution 
{
    public:
	void DFS_Util(vector<int> adj[], int src, int visited[], vector<int> &dfs){
	    visited[src] = 1;
	    dfs.push_back(src);
	    for(int i : adj[src]){
	        if(!visited[i]){
	            DFS_Util(adj, i, visited, dfs);
	        }
	    }
	}
	vector<int> dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> dfs;
	    int visited[V];
	    memset(visited, 0, sizeof(visited));
	    DFS_Util(adj, 0, visited, dfs);
	    return dfs;
	}
};