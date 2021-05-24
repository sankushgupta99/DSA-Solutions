class Solution {
public:
	bool isEularCircuitExist(int V, vector<int>adj[]){
	    int degree[V];
	    memset(degree, 0, sizeof(degree));
	    
	    for(int i = 0; i < V; i++){
	        for(int j : adj[i]){
	            degree[j]++;
	        }
	    }
	    
	    for(int i = 0; i < V; i++){
	        if(degree[i] % 2 == 1)
	        return false;
	    }
	    
	    return true;
	}

};