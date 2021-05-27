class Solution
{
    public:
	//Function to detect cycle in a directed graph.
	bool isCyclic(int V, vector<int> adj[]) 
	{
	   	int indegree[V];
	   	memset(indegree, 0, sizeof(indegree));
	   	for(int i = 0; i < V; i++){
	   	    for(int j : adj[i]){
	   	        indegree[j]++;
	   	    }
	   	}
	   	
	   	queue<int> q;
	   	for(int i = 0; i < V; i++){
	   	    if(indegree[i] == 0){
	   	        q.push(i);
	   	    }
	   	}
	   	
	   	vector<int> topo_sort;
	   	while(!q.empty()){
	   	    int size = q.size();
	   	    while(size > 0){
	   	        int curr = q.front();
	   	        q.pop();
	   	        topo_sort.push_back(curr);
	   	        
	   	        for(int i : adj[curr]){
	   	            indegree[i]--;
	   	            if(indegree[i] == 0)
	   	            q.push(i);
	   	        }
	   	        size--;
	   	    }
	   	}
	   	return (topo_sort.size() != V);
	}
};