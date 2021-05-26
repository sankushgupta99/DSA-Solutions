lass Solution {
public:
	bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
	    vector<int> adj[N];
	    for(auto i : prerequisites){
	        int u = i.second;
	        int v = i.first;
	        adj[u].push_back(v);
	    }
	    
	    int indegree[N];
	    memset(indegree, 0, sizeof(indegree));
	    for(auto i : prerequisites){
	        indegree[i.first]++;
	    }
	    
	    queue<int> q;
	    for(int i = 0; i < N; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    
	    vector<int> res;
	    while(!q.empty()){
	        int size = q.size();
	        while(size > 0){
	            int curr = q.front();
	            q.pop();
	            res.push_back(curr);
	            
	            for(int i : adj[curr]){
	                indegree[i]--;
	                if(indegree[i] == 0)
	                q.push(i);
	            }
	            size--;
	        }
	    }
	    
	    return (res.size() == N);
	}
};