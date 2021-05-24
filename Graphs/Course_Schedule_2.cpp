class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<int> adj[numCourses];
        for(auto i : prerequisites){
            int u = i[1];
            int v = i[0];
            adj[u].push_back(v);
        }
        
        int V = numCourses;
        int indegree[V];
        memset(indegree, 0, sizeof(indegree));
        for(int i = 0; i < V; i++){
            for(int j : adj[i]){
                indegree[j]++;
            }
        }
        
        queue<int> q;
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0)
                q.push(i);
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
                    if(indegree[i] == 0){
                        q.push(i);
                    }
                }
                size--;
            }
        }
        
        if(res.size() != V){
            res.clear();
        }
        return res;
    }
};